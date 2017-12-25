
#ifndef WXBASIC_H
#define WXBASIC_H

#include "parser.h"
#include "tokenizer.h"
#include"symbol.h"

#include <iostream>
#include <memory>
#include <string>

namespace wxbasic {

class WxBasic {
    SymbolTable sym_table;
public:
    WxBasic();
    WxBasic(const std::string file_name);

    void load_file(const std::string file_name);
    void run();
};
} // namespace wxbasic

#endif // WXBASIC_H
