#ifndef WXBASIC_TOKENIZER_H
#define WXBASIC_TOKENIZER_H
#include<vector>

#include"tokens.h"

namespace wxbasic {

    class Tokenizer {
        std::vector<wxbasic::Token> tokens;
        public:
        Tokenizer(const std::string& source_name, const std::string& source);
        void tokenize();
    };

}
#endif // WXBASIC_TOKENIZER_H
