#ifndef WXBASIC_TOKENIZER_H
#define WXBASIC_TOKENIZER_H

#include <memory>
#include <vector>

#include "error.h"
#include "tokens.h"

namespace wxbasic {

class TokenizerError;

class Tokenizer {
    std::string source;
    std::shared_ptr<std::string> source_name;

    // current token
    std::shared_ptr<wxbasic::Token> cur_token;

    size_t pos;

    friend TokenizerError;

protected:
    void skip_white();
    void tok_number();

    void tok_spaces();
    void tok_digits();
    void tok_hex_digits();
    void tok_bin_digits();

    void tok_string();

    void set_token(TokenType token, const std::string &content = "");

public:
    std::shared_ptr<wxbasic::Token> next_token();
    std::shared_ptr<wxbasic::Token> token();

    void load_file(std::string file_name);
    void load_from_str(const std::string &src, const std::string &srcname);
};

class TokenizerError : public Error {
public:
    TokenizerError(const std::string &error, const Tokenizer &tokenizer)
        : Error(error, tokenizer.pos, tokenizer.source,
                *tokenizer.source_name){};
};
}
#endif // WXBASIC_TOKENIZER_H
