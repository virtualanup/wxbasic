#ifndef WXBASIC_PARSER_H
#define WXBASIC_PARSER_H

#include "code.h"
#include "tokenizer.h"
#include <memory>

namespace wxbasic {

class Parser {
private:
    void parse_statement();

    std::string filename;
    std::string source;

public:
    Parser(const std::string &sourcecode, const std::string &file_name);
    Parser(const std::string &filename);
    const std::vector<std::shared_ptr<Code>> parse();
    void print_tokens();
};

} // namespace wxbasic
#endif // WXBASIC_PARSER_H
