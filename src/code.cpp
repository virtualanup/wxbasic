#include "code.h"

namespace wxbasic {
Code::Code() {}

void Code::emit(OpcodeType code) { pcode.push_back(code); }

void Code::clear() {
    pcode.clear();
    backpatch.clear();
    last = OP_UNDEFINED;
}

void Code::emit_op(OpcodeType code) {
    pcode.push_back(code);
    last = code;
}

} // namespace wxbasic
