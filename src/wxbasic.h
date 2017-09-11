
#ifndef WXBASIC_H
#define WXBASIC_H

#include "parser.h"
#include "tokenizer.h"
#include <iostream>
#include <memory>
#include <string>

namespace wxbasic {

class WxBasic {

    Parser parser;
    Tokenizer tokenizer;

public:
    WxBasic();
    WxBasic(const std::string file_name);
    void load_file(const std::string file_name);

    void print_tokens();

    void run();
};
}

#endif // WXBASIC_H
