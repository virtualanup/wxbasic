#include"parser.h"

namespace wxbasic {

    Parser::Parser(Tokenizer& tok):tokenizer(tok){}

    void Parser::parse() {

    }

    const std::vector< std::shared_ptr<Code> > Parser::get_code() const {
        return code;
    }
}
