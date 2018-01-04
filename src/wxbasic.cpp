#include "wxbasic.h"

namespace wxbasic {

WxBasic::WxBasic() {}

WxBasic::WxBasic(const std::string file_name) { load_file(file_name); }

void WxBasic::run() {
    // initialize the parser
}

void WxBasic::load_file(const std::string file_name) {
    Parser parser = Parser(file_name, sym_table, lit_table);
    auto code = parser.parse();
}

} // namespace wxbasic
