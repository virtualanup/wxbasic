#include "parser.h"
#include <fstream>
#include <iostream>

namespace wxbasic {

Parser::Parser(const std::string &sourcecode, const std::string &file_name) {
    filename = file_name;
    source = sourcecode;
}

Parser::Parser(const std::string &file_name) {
    filename = file_name;
    // try to load the file
    std::ifstream input_file(filename);

    if (!input_file)
        throw Error("Can't open file \"" + filename + "\"");

    input_file.seekg(0, std::ios::end);
    source.reserve(input_file.tellg());
    input_file.seekg(0, std::ios::beg);

    source.assign((std::istreambuf_iterator<char>(input_file)),
                  std::istreambuf_iterator<char>());
}

const std::vector<std::shared_ptr<Code>> Parser::parse() {
    Tokenizer tokenizer;
    tokenizer.load(source, filename);
    std::vector<std::shared_ptr<Code>> code;

    while (tokenizer.token()->type != TokenType::TOK_EOF) {
        parse_statement();
        tokenizer.next_token();
    }
    return code;
}

void Parser::parse_statement() {}

void Parser::print_tokens() {
    Tokenizer tokenizer = Tokenizer();
    tokenizer.load(source, filename);
    while (tokenizer.next_token()->type != TokenType::TOK_EOF) {
        std::cout << tokenizer.token()->str() << std::endl;
    }
}

} // namespace wxbasic
