#include<iostream>
#include<fstream>
#include"error.h"
#include"tokenizer.h"

namespace wxbasic {

    void Tokenizer::tokenize() {
        while(pos < source.size()) {
            switch(source[pos]) {
                case ' ':
                case '\t':
                case '\r':
                    pos++;
                    break;

                case '\'': // basic style comment
                case '#': // python style comment

                    while(pos < source.size() && source[pos] != '\n')
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
                    break;

                case '\"':
                    tok_string();
                    break;

                case '\n':
                    pos++;
                    break;

                default:
                    throw Error(std::string("Unexpected character") + source[pos], pos, source, *source_name);
                    pos++;
            }
        }
    }

    void Tokenizer::load_file(std::string file_name) {
        // try to load the file
        std::ifstream input_file(file_name);

        if(!input_file)
            throw Error("Can't open file \""+file_name+"\"");

        input_file.seekg(0, std::ios::end);
        source.reserve(input_file.tellg());
        input_file.seekg(0, std::ios::beg);

        source.assign((std::istreambuf_iterator<char>(input_file)),
                std::istreambuf_iterator<char>());

        source_name = std::shared_ptr<std::string>(new std::string(file_name));

        pos = 0;

    }

    void Tokenizer::load_from_str(const std::string &src, const std::string &srcname="unnamed") {
        source = src;

        source_name = std::shared_ptr<std::string>(new std::string(srcname));

        pos = 0;
    }


    const std::vector<wxbasic::Token>& Tokenizer::get_tokens() const {
        return tokens;
    }

    void Tokenizer::skip_white() {
        while( pos < source.size() && (source[pos] == '\t' || source[pos] == ' '))
            pos++;
        return;
    }

    void Tokenizer::tok_digits() {
        while(pos < source.size() &&
                (
                 (source[pos] >= '0' && source[pos] <= '9')
                ))
            pos++;


    }

    void Tokenizer::tok_hex_digits() {

        while(pos < source.size() &&
                (
                 (source[pos] >= '0' && source[pos] <= '9') ||
                 (source[pos] >= 'a' && source[pos] <= 'f') ||
                 (source[pos] >= 'F' && source[pos] <= 'F')
                ))
            pos++;

    }

    void Tokenizer::tok_bin_digits() {
        while(pos < source.size() &&
                (
                 (source[pos] == '1' || source[pos] == '0')
                ))
            pos++;
    }


    void Tokenizer::tok_number() {
        // number
        //

        // might need the starting position later
        size_t start_pos = pos;

        if(source[pos] == '0')
        {
            // parse hexadecimal and binary numbers
            pos++;
            if(pos < source.size() && (source[pos] == 'x' || source[pos] == 'X')) {

                pos++;
                tok_hex_digits();

                tokens.push_back(
                        Token(
                            TokenType::TOK_INTEGER,
                            source.substr(start_pos, pos - start_pos),
                            source_name
                            )
                        );
                return;
            }
            else if(pos < source.size() && (source[pos] == 'b' || source[pos] == 'B')) {

                pos++;
                size_t start_pos = pos;
                tok_bin_digits();

                tokens.push_back(
                        Token(
                            TokenType::TOK_INTEGER,
                            source.substr(start_pos, pos - start_pos),
                            source_name
                            )
                        );

            }
            else {
                tok_digits();
            }

        }

        // read remaining digits
        tok_digits();
        if(pos < source.size() && source[pos] == '.')
        {
            pos++;
            tok_digits();

            tokens.push_back(
                    Token(
                        TokenType::TOK_FLOAT,
                        source.substr(start_pos, pos - start_pos),
                        source_name
                        )
                    );
        }
        else
        {
            tokens.push_back(
                    Token(
                        TokenType::TOK_INTEGER,
                        source.substr(start_pos, pos - start_pos),
                        source_name
                        )
                    );

        }
    }


    void Tokenizer::tok_string() {

        static std::string eol_error = "Unexpected end of file";
        std::string tok_str;

        // skip the "
        pos++;

        while(pos < source.size()) {
            switch(source[pos]) {
                case '\n':
                    throw Error("Unexpected end of line");
                    break;
                case '"':
                    // end of string
                    tokens.push_back(
                            Token(
                                TokenType::TOK_STRING,
                                tok_str,
                                source_name
                                )
                            );
                    pos++;
                    return;
                case '\\':
                    // special character
                    pos++;
                    if(pos >= source.size())
                        throw Error(eol_error);
                    switch(source[pos]) {
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
                        case '\"':
                            tok_str += "\"";
                            break;
                        case '\'':
                            tok_str += "\'";
                            break;
                        default:
                            throw Error("Unknown escape code");
                    }
                    break;
                default:
                    tok_str += source[pos];
                    pos++;
            }
        }

        throw Error(eol_error);
    }
}
