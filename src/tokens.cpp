
#include"tokens.h"


namespace wxbasic
{
    const std::map<TokenType, std::string> TokenNames = {
        {TokenType::END_OF_FILE,"End of File"}
    };

    Token::Token(TokenType type, const std::string &content, std::shared_ptr<std::string>
            source_name)
        : token(type), content(content) {
        }

    std::string Token::str() const{
        return  TokenNames.at(token) + " - " + content;
    }

}
