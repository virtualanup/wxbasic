#include "code.h"

namespace wxbasic {
Code::Code() {}

void Code::emit(int code) { pcode.push_back(code); }

void Code::emit_op(int code) {
    pcode.push_back(code);
    last = code;
}
} // namespace wxbasic
