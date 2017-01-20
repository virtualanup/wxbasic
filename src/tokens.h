
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

        TOK_LT,
        TOK_LTE,
        TOK_GT,
        TOK_GTE,
        TOK_NE,

        TOK_SHL,
        TOK_SHR,

        TOK_BINOP, // +, -, *, /, %, ^, '\'

        TOK_LPAREN,
        TOK_RPAREN,


        TOK_EOF,
    };

    const static std::map<TokenType, std::string> TokenNames = {
        {TokenType::TOK_INTEGER,"TOK_INTEGER"},
        {TokenType::TOK_FLOAT,"TOK_FLOAT"},
        {TokenType::TOK_STRING,"TOK_STRING"},

        {TokenType::TOK_LT,"TOK_LT"},
        {TokenType::TOK_LTE,"TOK_LTE"},
        {TokenType::TOK_GT,"TOK_GT"},
        {TokenType::TOK_GTE,"TOK_GTE"},
        {TokenType::TOK_NE,"TOK_NE"},

        {TokenType::TOK_SHL,"TOK_SHL"},
        {TokenType::TOK_SHR,"TOK_SHR"},

        {TokenType::TOK_BINOP,"TOK_BINOP"},

        {TokenType::TOK_LPAREN,"TOK_LPAREN"},
        {TokenType::TOK_RPAREN,"TOK_RPAREN"},

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
