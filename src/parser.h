#ifndef WXBASIC_PARSER_H
#define WXBASIC_PARSER_H

#include "code.h"
#include "symbol.h"
#include "tokenizer.h"
#include <memory>

namespace wxbasic {

class ParserError;

class Parser {
private:
    Tokenizer tokenizer;

    std::string source_name;
    std::string source;
    SymbolTable &sym_table;

    Code code;

    void parse_expression(int);
    void parse_operand();
    void parse_statement();
    void parse_seperator(bool must_exist = true);
    void parse_print();

    void expect(TokenType, const std::string &);
    bool is_seperator();
    void skip();


    TokenType skip_line();
    void scan_routines();
    void skip_expression();
    friend ParserError;

public:
    Parser(const std::string &sourcecode, const std::string &file_name,
           SymbolTable &symbol_table);
    Parser(const std::string &filename, SymbolTable &symbol_table);
    Code parse();
    void print_tokens();
};

class ParserError : public Error {
public:
    ParserError(const std::string &error, const Parser &parser)
        : Error(error, parser.tokenizer.get_pos(), parser.source,
                parser.source_name){};
};

} // namespace wxbasic
#endif // WXBASIC_PARSER_H
