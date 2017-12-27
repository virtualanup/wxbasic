
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
    TOK_LSQBKT,
    TOK_RSQBKT,
    TOK_LCURLY,
    TOK_RCURLY,

    TOK_COMMA,
    TOK_SEMICOLON,
    TOK_DOT,
    TOK_3DOTS,

    // keywords
    TOK_ABSTRACT,
    TOK_AND,
    TOK_AS,
    TOK_CLASS,
    TOK_FUNCTION,
    TOK_INPUT,
    TOK_INV,
    TOK_NOT,
    TOK_OR,
    TOK_PRINT,
    TOK_SHARED,
    TOK_VIRTUAL,

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
    {TokenType::TOK_LSQBKT, "TOK_LSQBKT"},
    {TokenType::TOK_RSQBKT, "TOK_RSQBKT"},
    {TokenType::TOK_LCURLY, "TOK_LCURLY"},
    {TokenType::TOK_RCURLY, "TOK_RCURLY"},


    {TokenType::TOK_COMMA, "TOK_COMMA"},
    {TokenType::TOK_SEMICOLON, "TOK_SEMICOLON"},

    {TokenType::TOK_ABSTRACT, "TOK_ABSTRACT"},
    {TokenType::TOK_AND, "TOK_AND"},
    {TokenType::TOK_AS, "TOK_AS"},
    {TokenType::TOK_CLASS, "TOK_CLASS"},
    {TokenType::TOK_FUNCTION, "TOK_FUNCTION"},
    {TokenType::TOK_INPUT, "TOK_INPUT"},
    {TokenType::TOK_INV, "TOK_INV"},
    {TokenType::TOK_NOT, "TOK_NOT"},
    {TokenType::TOK_OR, "TOK_OR"},
    {TokenType::TOK_PRINT, "TOK_PRINT"},
    {TokenType::TOK_SHARED, "TOK_SHARED"},
    {TokenType::TOK_VIRTUAL, "TOK_VIRTUAL"},

    {TokenType::TOK_SEPERATOR, "TOK_SEPERATOR"},

    {TokenType::TOK_EOF, "TOK_EOF"},
};

const static std::unordered_map<std::string, TokenType> Keywords = {
    {"abstract", TokenType::TOK_ABSTRACT},
    {"and", TokenType::TOK_AND},
    {"as", TokenType::TOK_AS},
    {"class", TokenType::TOK_CLASS},
    {"function", TokenType::TOK_FUNCTION},
    {"input", TokenType::TOK_INPUT},
    {"inv", TokenType::TOK_INV},
    {"not", TokenType::TOK_NOT},
    {"or", TokenType::TOK_OR},
    {"print", TokenType::TOK_PRINT},
    {"shared", TokenType::TOK_SHARED},
    {"virtual", TokenType::TOK_VIRTUAL},
};

class Token {
public:
    wxbasic::TokenType type;
    std::string content;

    union {
        long long int_val;
        long double float_val;
    } value;

    std::shared_ptr<std::string> source_name;
    Token(TokenType t_type, const std::string &content,
          std::shared_ptr<std::string>);

    std::string str() const;
};
} // namespace wxbasic

#endif // WXBASIC_TOKENS_H
