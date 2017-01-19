#ifndef WXBASIC_TOKENIZER_H
#define WXBASIC_TOKENIZER_H

#include<memory>
#include<vector>

#include"tokens.h"

namespace wxbasic {

    class Tokenizer {
        std::vector<wxbasic::Token> tokens;

        std::string source;
        std::shared_ptr<std::string> source_name;

        size_t pos;


        protected:

        void skip_white();
        void tok_number();

        void tok_digits();
        void tok_hex_digits();
        void tok_bin_digits();

        void tok_string();

        public:
        void tokenize();

        void load_file(std::string file_name);
        void load_from_str(const std::string &src, const std::string &srcname);

        const std::vector<wxbasic::Token>& get_tokens() const;

    };

}
#endif // WXBASIC_TOKENIZER_H
