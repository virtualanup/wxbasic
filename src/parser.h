#ifndef WXBASIC_PARSER_H
#define WXBASIC_PARSER_H

#include"tokenizer.h"

namespace wxbasic {

    class Parser {

        Tokenizer& tokenizer;

        public:
            Parser(Tokenizer& tok);
    };
}
#endif // WXBASIC_PARSER_H
