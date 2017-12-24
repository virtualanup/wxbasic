
#ifndef WXBASIC_TOKENS_H
#define WXBASIC_TOKENS_H

#include <memory>
#include <string>
#include <unordered_map>

namespace wxbasic {

enum class TokenType {
    TOK_INTEGER,
    TOK_FLOAT,
    TOK_STRING,

    TOK_IDENTIFIER,

    TOK_LT,
    TOK_LTE,
    TOK_GT,
    TOK_GTE,
    TOK_NE,
    TOK_EQ,

    TOK_SHL,
    TOK_SHR,

    TOK_BINOP, // +, -, *, /, %, ^, '\'

    TOK_LPAREN,
    TOK_RPAREN,

    TOK_COMMA,
    TOK_SEMICOLON,

    TOK_PRINT,
    TOK_INPUT,

    TOK_NOT,
    TOK_OR,
    TOK_AND,
    TOK_INV,

    TOK_SEPERATOR,
    TOK_EOF,
};

const static std::unordered_map<TokenType, std::string> TokenNames = {
    {TokenType::TOK_INTEGER, "TOK_INTEGER"},
    {TokenType::TOK_FLOAT, "TOK_FLOAT"},
    {TokenType::TOK_STRING, "TOK_STRING"},

    {TokenType::TOK_IDENTIFIER, "TOK_IDENTIFIER"},

    {TokenType::TOK_LT, "TOK_LT"},
    {TokenType::TOK_LTE, "TOK_LTE"},
    {TokenType::TOK_GT, "TOK_GT"},
    {TokenType::TOK_GTE, "TOK_GTE"},
    {TokenType::TOK_NE, "TOK_NE"},
    {TokenType::TOK_EQ, "TOK_EQ"},

    {TokenType::TOK_SHL, "TOK_SHL"},
    {TokenType::TOK_SHR, "TOK_SHR"},

    {TokenType::TOK_BINOP, "TOK_BINOP"},

    {TokenType::TOK_LPAREN, "TOK_LPAREN"},
    {TokenType::TOK_RPAREN, "TOK_RPAREN"},

    {TokenType::TOK_COMMA, "TOK_COMMA"},
    {TokenType::TOK_SEMICOLON, "TOK_SEMICOLON"},

    {TokenType::TOK_PRINT, "TOK_PRINT"},
    {TokenType::TOK_INPUT, "TOK_INPUT"},

    {TokenType::TOK_NOT, "TOK_NOT"},
    {TokenType::TOK_OR, "TOK_OR"},
    {TokenType::TOK_AND, "TOK_AND"},
    {TokenType::TOK_INV, "TOK_INV"},


    {TokenType::TOK_SEPERATOR, "TOK_SEPERATOR"},

    {TokenType::TOK_EOF, "TOK_EOF"},
};

const static std::unordered_map<std::string, TokenType> Keywords = {
    {"print", TokenType::TOK_PRINT},
    {"input", TokenType::TOK_INPUT},

    {"not", TokenType::TOK_NOT},
    {"or", TokenType::TOK_OR},
    {"and", TokenType::TOK_AND},

    {"inv", TokenType::TOK_INV},
};

class Token {
public:
    wxbasic::TokenType type;
    std::string content;
    std::shared_ptr<std::string> source_name;

    Token(TokenType t_type, const std::string &content,
          std::shared_ptr<std::string>);

    std::string str() const;
};
} // namespace wxbasic

#endif // WXBASIC_TOKENS_H
