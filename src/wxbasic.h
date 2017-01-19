
#ifndef WXBASIC_H
#define WXBASIC_H

#include<iostream>
#include<string>
#include"tokenizer.h"

namespace wxbasic {

    class WxBasic {

        Tokenizer tokenizer;

        public:
            WxBasic();
            WxBasic(const std::string file_name);
            void load_file(const std::string file_name);
            void parse();
            void print_tokens() const;
    };
}

#endif // WXBASIC_H

