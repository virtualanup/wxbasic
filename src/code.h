#ifndef WXBASIC_CODE_H
#define WXBASIC_CODE_H

#include <vector>

namespace wxbasic {

class Code {
public:
    int last;                   // value of the last bytecode added
    std::vector<int> pcode;     // bytecode array
    std::vector<int> backpatch; // list of address to backpatch
    Code();
    void emit(int code);
    void emit_op(int code);
};

} // namespace wxbasic
#endif // WXBASIC_CODE_H
