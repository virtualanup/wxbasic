#include"wxbasic.h"

namespace wxbasic {

    WxBasic::WxBasic() {

    }

    WxBasic::WxBasic(const std::string file_name) {
        load_file(file_name);
    }

    void WxBasic::parse() {
    }

    void WxBasic::load_file(const std::string file_name) {
        tokenizer.load_file(file_name);
    }

    void WxBasic::print_tokens(){
        // print out the tokens
        while(tokenizer.next_token()->type != TokenType::TOK_EOF) {
            std::cout<<tokenizer.token()->str()<<std::endl;
        }
    }

}
