
#ifndef WXBASIC_H
#define WXBASIC_H

#include<string>

namespace wxbasic {

    class WxBasic {
        public:
            WxBasic(const std::string input);
            void print_tokens() const;
    };
}

#endif // WXBASIC_H

