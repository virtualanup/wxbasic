
#include "tokens.h"
#include <iostream>

namespace wxbasic {
Token::Token(TokenType t_type, const std::string &content,
             std::shared_ptr<std::string> source_name)
    : type(t_type), content(content) {}

std::string Token::str() const {
    return TokenNames.at(type) + " - \"" + content + "\"";
}
}
