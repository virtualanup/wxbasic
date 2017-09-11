#include "wxbasic.h"

namespace wxbasic {

WxBasic::WxBasic() : parser(tokenizer) {}

WxBasic::WxBasic(const std::string file_name) : parser(tokenizer) {
    load_file(file_name);
}

void WxBasic::run() {
    // initialize the parser
    parser.parse();
}

void WxBasic::load_file(const std::string file_name) {
    tokenizer.load_file(file_name);
}

void WxBasic::print_tokens() {
    // print out the tokens
    while (tokenizer.next_token()->type != TokenType::TOK_EOF) {
        std::cout << tokenizer.token()->str() << std::endl;
    }
}
}
