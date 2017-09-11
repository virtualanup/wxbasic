#ifndef WXBASIC_PARSER_H
#define WXBASIC_PARSER_H

#include "code.h"
#include "tokenizer.h"
#include <memory>

namespace wxbasic {

class Parser {

    Tokenizer &tokenizer;
    std::vector<std::shared_ptr<Code>> code;

protected:
    void parse_statement();

public:
    Parser(Tokenizer &tok);
    void parse();
    const std::vector<std::shared_ptr<Code>> get_code() const;
};
}
#endif // WXBASIC_PARSER_H
