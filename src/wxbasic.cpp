#include "wxbasic.h"

namespace wxbasic {

WxBasic::WxBasic() {}

WxBasic::WxBasic(const std::string file_name) { load_file(file_name); }

void WxBasic::run() {
    // initialize the parser
}

void WxBasic::load_file(const std::string file_name) {
    Parser parser = Parser(file_name);
    parser.parse();
}

void WxBasic::print_tokens() {
    // print out the tokens
}
} // namespace wxbasic
