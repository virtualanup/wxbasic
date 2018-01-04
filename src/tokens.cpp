
#include "tokens.h"
#include <iostream>

namespace wxbasic {
Token::Token(TokenType t_type, const std::string &content,
             std::shared_ptr<std::string> source_name)
    : type(t_type), content(content) {}

std::string Token::str() const {
    return TokenNames.at(type) + " - \"" + content + "\"";
}

bool Token::is_operator() const {
    switch (type) {
    case TokenType::TOK_LT:
    case TokenType::TOK_LE:
    case TokenType::TOK_GT:
    case TokenType::TOK_GE:
    case TokenType::TOK_NE:
    case TokenType::TOK_EQ:

    case TokenType::TOK_SHL:
    case TokenType::TOK_SHR:

    case TokenType::TOK_OP:

    case TokenType::TOK_AND:
    case TokenType::TOK_INV:
    case TokenType::TOK_NOT:
    case TokenType::TOK_OR:

        return true;
    default:
        return false;
    }
}

int Token::op_strength() const {
    // If current token is an operator, return its strength
    switch (type) {

    case TokenType::TOK_LT:
    case TokenType::TOK_LE:
    case TokenType::TOK_GT:
    case TokenType::TOK_GE:
    case TokenType::TOK_NE:
    case TokenType::TOK_EQ:
        return 13;

    case TokenType::TOK_SHL:
    case TokenType::TOK_SHR:
        return 15;
    case TokenType::TOK_OP:
        return true;

    case TokenType::TOK_AND:
        return 11;
    case TokenType::TOK_INV:
        return 6;
    case TokenType::TOK_OR:
        return 10;
    case TokenType::TOK_XOR:
        return 9;
    default:
        return 0;
    }
}
} // namespace wxbasic
