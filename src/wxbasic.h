
#ifndef WXBASIC_H
#define WXBASIC_H

#include "parser.h"
#include "tokenizer.h"
#include <iostream>
#include <memory>
#include <string>

namespace wxbasic {

class WxBasic {
    std::vector<std::unique_ptr<Code>> code;
public:
    WxBasic();
    WxBasic(const std::string file_name);

    void load_file(const std::string file_name);
    void print_tokens();
    void run();
};
} // namespace wxbasic

#endif // WXBASIC_H
