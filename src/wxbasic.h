
#ifndef WXBASIC_H
#define WXBASIC_H

#include<iostream>
#include<string>
#include"tokenizer.h"

namespace wxbasic {

    class WxBasic {

        Tokenizer tokenizer;

        public:
            WxBasic(const std::string input_file);
            void parse();
            void print_tokens() const;
    };
}

#endif // WXBASIC_H

