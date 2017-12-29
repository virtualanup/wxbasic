#include "tokenizer.h"
#include <fstream>
#include <iostream>
#include <sstream>

namespace wxbasic {

std::shared_ptr<wxbasic::Token> Tokenizer::next_token() {

    while (pos < source.size()) {

        switch (source[pos]) {
        case ' ':
        case '\t':
        case '\r':
            pos++;
            break;

        case '\'': // basic style comment
        case '#':  // python style comment

            while (pos < source.size() && source[pos] != '\n')
                pos++;
            pos++;
            break;

        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
            // parse a number
            tok_number();
            return cur_token;

        case '\"':
            tok_string();
            return cur_token;

        case ':':
        case '\n':
            // line breaks
            set_token(TokenType::TOK_SEPERATOR);
            pos++;
            return cur_token;

        // operators
        case '(':
            set_token(TokenType::TOK_LPAREN, "(");
            pos++;
            return cur_token;

        case '[':
            set_token(TokenType::TOK_LSQBKT, "[");
            pos++;
            return cur_token;

        case ']':
            set_token(TokenType::TOK_RSQBKT, "]");
            pos++;
            return cur_token;

        case '{':
            set_token(TokenType::TOK_LCURLY, "{");
            pos++;
            return cur_token;

        case '}':
            set_token(TokenType::TOK_RCURLY, "}");
            pos++;
            return cur_token;

        case ';':
            set_token(TokenType::TOK_SEMICOLON, ";");
            pos++;
            return cur_token;

        case ',':
            set_token(TokenType::TOK_COMMA, ",");
            pos++;
            return cur_token;

        case '.':
            pos++;
            if (pos <= source.size() - 2 && source[pos] == '.' &&
                source[pos + 1] == '.') {
                set_token(TokenType::TOK_3DOTS, "...");
                pos += 2;
            } else
                set_token(TokenType::TOK_DOT, ".");
            return cur_token;

        case ')':
            set_token(TokenType::TOK_RPAREN, ")");
            pos++;
            return cur_token;

        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
        case '\\':
            set_token(TokenType::TOK_OP, std::string(1, source[pos]));
            pos++;
            return cur_token;
        case '!':
            pos++;
            if (pos < source.size() && source[pos] == '=') {
                set_token(TokenType::TOK_NE, "!=");
                pos++;
                return cur_token;
            } else
                throw TokenizerError("Expected = after !", *this);

        case '=':
            set_token(TokenType::TOK_EQ, std::string(1, source[pos]));
            pos++;
            return cur_token;

        case '<':
            pos++;
            if (pos < source.size() && source[pos] == '=') {
                set_token(TokenType::TOK_LTE, "<=");
                pos++;
            } else if (pos < source.size() && source[pos] == '>') {
                set_token(TokenType::TOK_NE, "<>");
                pos++;
            } else if (pos < source.size() && source[pos] == '<') {

                set_token(TokenType::TOK_SHL, "<<");
                pos++;
            } else {
                set_token(TokenType::TOK_LT, "<");
            }
            return cur_token;

        case '>':
            pos++;
            if (pos < source.size() && source[pos] == '=') {
                set_token(TokenType::TOK_GTE, ">=");
                pos++;
            } else if (pos < source.size() && source[pos] == '>') {
                set_token(TokenType::TOK_SHR, ">>");
                pos++;
            } else {
                set_token(TokenType::TOK_GT, ">");
            }
            return cur_token;

        default:
            // check if it is identifier
            // TODO: Allow identifier to start from $?
            if (source[pos] == '_' ||
                (source[pos] >= 'A' && source[pos] <= 'Z') ||
                (source[pos] >= 'a' && source[pos] <= 'z')) {
                // identifier
                size_t start_pos = pos;
                while (pos < source.size() &&
                       (source[pos] == '_' ||
                        (source[pos] >= 'A' && source[pos] <= 'Z') ||
                        (source[pos] >= 'a' && source[pos] <= 'z') ||
                        (source[pos] >= '0' && source[pos] <= '9') ||
                        ((source[pos] & 0x80) != 0))) {
                    pos++;
                }

                std::string content = source.substr(start_pos, pos - start_pos);
                // check for built in keyword
                if (Keywords.count(content) != 0) {
                    set_token(Keywords.at(content), content);
                } else {
                    set_token(TokenType::TOK_IDENTIFIER, content);
                }
                return cur_token;
            }

            throw TokenizerError(std::string("Unexpected Character \'") +
                                     source[pos] + std::string("\'"),
                                 *this);
        }
    }

    set_token(TokenType::TOK_EOF, "");
    return cur_token;
}

std::shared_ptr<wxbasic::Token> Tokenizer::token() {
    // returns current token
    return cur_token;
}

void Tokenizer::load(const std::string &src,
                     const std::string &srcname = "unnamed") {
    source = src;
    source_name = std::shared_ptr<std::string>(new std::string(srcname));

    pos = 0;
    // scan the first token
    next_token();
}

void Tokenizer::skip_white() {
    while (pos < source.size() && (source[pos] == '\t' || source[pos] == ' '))
        pos++;
    return;
}

void Tokenizer::tok_digits() {
    while (pos < source.size() && ((source[pos] >= '0' && source[pos] <= '9')))
        pos++;
}

void Tokenizer::tok_hex_digits() {

    while (pos < source.size() && ((source[pos] >= '0' && source[pos] <= '9') ||
                                   (source[pos] >= 'a' && source[pos] <= 'f') ||
                                   (source[pos] >= 'F' && source[pos] <= 'F')))
        pos++;
}

void Tokenizer::tok_bin_digits() {
    while (pos < source.size() && ((source[pos] == '1' || source[pos] == '0')))
        pos++;
}

void Tokenizer::tok_number() {
    // number
    //

    // might need the starting position later
    size_t start_pos = pos;

    if (source[pos] == '0') {
        // parse hexadecimal and binary numbers
        pos++;
        if (pos < source.size() && (source[pos] == 'x' || source[pos] == 'X')) {

            pos++;
            tok_hex_digits();

            set_token(TokenType::TOK_INTEGER,
                      source.substr(start_pos, pos - start_pos));
            return;
        } else if (pos < source.size() &&
                   (source[pos] == 'b' || source[pos] == 'B')) {

            pos++;
            size_t start_pos = pos;
            tok_bin_digits();

            set_token(TokenType::TOK_INTEGER,
                      source.substr(start_pos, pos - start_pos));

        } else {
            tok_digits();
        }
    }

    // read remaining digits
    tok_digits();
    if (pos < source.size() && source[pos] == '.') {
        pos++;
        tok_digits();

        set_token(TokenType::TOK_FLOAT,
                  source.substr(start_pos, pos - start_pos));
    } else {
        set_token(TokenType::TOK_INTEGER,
                  source.substr(start_pos, pos - start_pos));
    }
}

void Tokenizer::tok_string() {

    static std::string eol_error = "Unexpected end of file";
    std::string tok_str;

    // skip the "
    pos++;

    while (pos < source.size()) {
        switch (source[pos]) {
        case '\n':
            throw TokenizerError("Unexpected end of line", *this);
        case '"':
            // end of string
            set_token(TokenType::TOK_STRING, tok_str);
            pos++;
            return;
        case '\\':
            // special character
            pos++;
            if (pos >= source.size())
                throw TokenizerError(eol_error, *this);

            switch (source[pos]) {
            case 'n':
                tok_str += "\n";
                break;
            case 'r':
                tok_str += "\r";
                break;
            case '\\':
                tok_str += "\\";
                break;
            case 't':
                tok_str += "\t";
                break;
            case 'v':
                tok_str += "\v";
                break;
            case '\"':
                tok_str += "\"";
                break;
            case '\'':
                tok_str += "\'";
                break;
            default:
                throw TokenizerError("Unknown escape code", *this);
            }
            break;
        default:
            tok_str += source[pos];
            pos++;
        }
    }

    throw TokenizerError(eol_error, *this);
}

void Tokenizer::set_token(TokenType token, const std::string &content) {
    cur_token =
        std::shared_ptr<wxbasic::Token>(new Token(token, content, source_name));

    if (token == TokenType::TOK_INTEGER || token == TokenType::TOK_FLOAT) {
        std::stringstream itemp(content);

        if (token == TokenType::TOK_INTEGER)
            itemp >> cur_token->value.int_val;
        else if (token == TokenType::TOK_FLOAT)
            itemp >> cur_token->value.float_val;
    }
}

std::string Tokenizer::token_content() { return cur_token->content; }

bool Tokenizer::is_token(TokenType tok) const { return cur_token->type == tok; }

TokenType Tokenizer::token_type() const { return cur_token->type; }
int Tokenizer::get_pos() const { return pos; }

void Tokenizer::expect(TokenType type, const std::string &str) {
    if (cur_token->type != type)
        throw TokenizerError("Expected " + str, *this);
    // skip ahead
    next_token();
}

} // namespace wxbasic
