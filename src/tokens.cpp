
#include<iostream>
#include"tokens.h"


namespace wxbasic
{
    Token::Token(TokenType type, const std::string &content, std::shared_ptr<std::string>
            source_name)
        : token(type), content(content) {
        }

    std::string Token::str() const{
        return  TokenNames.at(token) + " - \"" + content + "\"";
    }

}
