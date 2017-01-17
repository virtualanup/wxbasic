
#ifndef WXBASIC_TOKENS_H
#define WXBASIC_TOKENS_H

#include<memory>
#include<string>
#include<map>

namespace wxbasic {

    enum class TokenType {
        END_OF_FILE,
    };

    const extern std::map<TokenType, std::string> TokenNames;

    class Token {
        public:
            wxbasic::TokenType token;
            std::string content;
            std::shared_ptr<std::string> source_name;

            Token(TokenType type, const std::string &content, std::shared_ptr<std::string>);

            std::string str() const;
    };

}

#endif // WXBASIC_TOKENS_H
