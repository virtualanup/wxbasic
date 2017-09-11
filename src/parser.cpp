#include "parser.h"

namespace wxbasic {

Parser::Parser(Tokenizer &tok) : tokenizer(tok) {}

void Parser::parse() {
    code.clear();

    tokenizer.next_token();
    while (tokenizer.token()->type != TokenType::TOK_EOF) {
        parse_statement();
        tokenizer.next_token();
    }
}

const std::vector<std::shared_ptr<Code>> Parser::get_code() const {
    return code;
}

void Parser::parse_statement() {}
}
