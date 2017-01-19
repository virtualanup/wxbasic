#include"wxbasic.h"

namespace wxbasic {

    WxBasic::WxBasic() {

    }

    WxBasic::WxBasic(const std::string file_name) {
        load_file(file_name);
    }

    void WxBasic::parse() {
        tokenizer.tokenize();
    }

    void WxBasic::load_file(const std::string file_name) {
        tokenizer.load_file(file_name);
    }

    void WxBasic::print_tokens() const {
        // print out the tokens
        std::cout<<tokenizer.get_tokens().size()<<" Tokens:"<<std::endl;

        for(Token tok: tokenizer.get_tokens()) {
            std::cout<<tok.str()<<std::endl;
        }
    }

}
