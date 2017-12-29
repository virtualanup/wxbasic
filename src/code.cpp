#include "code.h"

namespace wxbasic {
Code::Code() {}

void Code::emit(OpcodeType code) { pcode.push_back(code); }

void Code::clear() {
    pcode.clear();
    backpatch.clear();
    last = OpcodeType::OP_UNDEFINED;
}

void Code::emit_op(OpcodeType code) {
    pcode.push_back(code);
    last = code;
}

// Append the code to this code
// Backpatch address if required
void Code::append(std::shared_ptr<Code> source) {
    // code can be NULL
    if (source == NULL)
        return;

    size_t dest_bp_size= pcode.size();

    // Fix the backpatch
    for (size_t i = 0; i < source->backpatch.size(); i++) {
        source->backpatch[i] += dest_bp_size;
    }

    // Append the backpatch and the opcodes
    backpatch.insert(backpatch.end(), source->backpatch.begin(), source->backpatch.end());
    pcode.insert(pcode.end(), source->pcode.begin(), source->pcode.end());

    last = source->last;
}

} // namespace wxbasic
