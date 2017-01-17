#include<iostream>
#include"tokenizer.h"

namespace wxbasic {

    Tokenizer::Tokenizer(const std::string& source_name, const std::string& source) {
        std::cout<<"Constructor for tokenizer with soruce "<<source<<std::endl;
    }

    void Tokenizer::tokenize() {
        // tokenize the input
        // pass
    }
}
