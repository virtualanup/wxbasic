#ifndef WXBASIC_CODE_H
#define WXBASIC_CODE_H

#include <memory>
#include <vector>

#include "opcode.h"
namespace wxbasic {

/* Opcode can store either opcode type or address for different stack
 * positions . We use union instead of inheriting two classes from a base
 * class to make things easier. The type of opcode is always known in the VM.*/
union OpcodeWrapper {
    OpcodeType op_type;
    size_t val;

    OpcodeWrapper(size_t i_val) { val = i_val; }
    OpcodeWrapper(OpcodeType type) { op_type = type; }
};

// Bytecode class
class Code {
public:
    OpcodeType last;                  // value of the last bytecode added
    std::vector<OpcodeWrapper> pcode; // bytecode array
    std::vector<size_t> backpatch;    // list of address to backpatch

    Code();
    void clear();
    void emit(OpcodeType code);
    void emit_op(OpcodeType code);
    void append(std::shared_ptr<Code>);
};

} // namespace wxbasic
#endif // WXBASIC_CODE_H
