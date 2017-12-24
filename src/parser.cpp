#include "parser.h"
#include <fstream>
#include <iostream>

namespace wxbasic {

Parser::Parser(const std::string &sourcecode, const std::string &file_name) {
    source_name = file_name;
    source = sourcecode;
}

Parser::Parser(const std::string &file_name) {
    source_name = file_name;

    // try to load the file
    std::ifstream input_file(source_name);

    if (!input_file)
        throw Error("Can't open file \"" + source_name + "\"");

    input_file.seekg(0, std::ios::end);
    source.reserve(input_file.tellg());
    input_file.seekg(0, std::ios::beg);

    source.assign((std::istreambuf_iterator<char>(input_file)),
                  std::istreambuf_iterator<char>());
}

// Parse the source code
Code Parser::parse() {

    // Load the content
    tokenizer.load(source, source_name);

    // Vector of bytecode
    code.clear();

    while (!tokenizer.is_token(TokenType::TOK_EOF)) {
        parse_statement();
        tokenizer.next_token();
    }
    return code;
}

// Parse a single statement
void Parser::parse_statement() {

    // empty line
    if (is_seperator()) {
        parse_seperator();
        return;
    }

    switch (tokenizer.token()->type) {
    case TokenType::TOK_PRINT:
        parse_print();
        break;
    default:
        break;
    }
}

void Parser::parse_print() {
    skip();
    if (is_seperator()) {
        // empty print statement.
        code.emit_op(OpcodeType::OP_EMITLN);
        return;
    }
    while (1) {
        // leading ;
        if (tokenizer.is_token(TokenType::TOK_SEMICOLON)) {
            skip();
            if (is_seperator())
                break;
        }

        // leading ,
        else if (tokenizer.is_token(TokenType::TOK_COMMA)) {
            skip();
            code.emit_op(OpcodeType::OP_EMITTAB);
            if (is_seperator()) {
                code.emit_op(OpcodeType::OP_EMITLN);
                break;
            }
        } else if (is_seperator()) {
            break;
        } else {
            parse_expression(0);
            // trailing values
            if (tokenizer.is_token(TokenType::TOK_SEMICOLON)) {
                skip();
                code.emit_op(OpcodeType::OP_PRINT);
            } else if (tokenizer.is_token(TokenType::TOK_COMMA)) {
                skip();
                code.emit_op(OpcodeType::OP_EMITTAB);
                if (is_seperator()) {
                    code.emit_op(OpcodeType::OP_EMITLN);
                }
            } else {
                break;
            }
        }
    }
}

void Parser::parse_expression(int) {}

bool Parser::is_seperator() {
    return tokenizer.is_token(TokenType::TOK_SEPERATOR) ||
           tokenizer.is_token(TokenType::TOK_EOF);
}

void Parser::skip() {
    // get next token
    tokenizer.next_token();
}

void Parser::parse_seperator() {
    if (!is_seperator()) {
        throw ParserError("Expected end of line", *this);
    }
    if (!tokenizer.is_token(TokenType::TOK_EOF))
        skip();
}

void Parser::print_tokens() {
    tokenizer.load(source, source_name);
    while (tokenizer.next_token()->type != TokenType::TOK_EOF) {
        std::cout << tokenizer.token()->str() << std::endl;
    }
}

} // namespace wxbasic
