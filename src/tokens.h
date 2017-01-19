
#ifndef WXBASIC_TOKENS_H
#define WXBASIC_TOKENS_H

#include<memory>
#include<string>
#include<map>

namespace wxbasic {

    enum class TokenType {
        TOK_INTEGER,
        TOK_FLOAT,
        TOK_STRING,
        TOK_EOF,
    };

    const static std::map<TokenType, std::string> TokenNames = {
        {TokenType::TOK_INTEGER,"TOK_INTEGER"},
        {TokenType::TOK_FLOAT,"TOK_FLOAT"},
        {TokenType::TOK_STRING,"TOK_STRING"},
        {TokenType::TOK_EOF,"End of File"},
    };


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
