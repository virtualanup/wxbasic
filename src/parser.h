#ifndef WXBASIC_PARSER_H
#define WXBASIC_PARSER_H

#include<memory>
#include"code.h"
#include"tokenizer.h"

namespace wxbasic {

    class Parser {

        Tokenizer& tokenizer;
        std::vector< std::shared_ptr<Code> > code;

        public:
        Parser(Tokenizer& tok);
        void parse();
        const std::vector< std::shared_ptr<Code> > get_code() const;
    };
}
#endif // WXBASIC_PARSER_H
