#include"wxbasic.h"

namespace wxbasic {

    WxBasic::WxBasic(const std::string input_file) {
        tokenizer.load_file(input_file);
    }

    void WxBasic::parse() {
        tokenizer.tokenize();
    }

    void WxBasic::print_tokens() const {
        // print out the tokens
        std::cout<<tokenizer.get_tokens().size()<<" Tokens:"<<std::endl;
        for(Token tok: tokenizer.get_tokens()) {
            std::cout<<tok.str()<<std::endl;
        }
    }
}
