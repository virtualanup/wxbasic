#ifndef WXBASIC_CODE_H
#define WXBASIC_CODE_H

#include <vector>

#include "opcode.h"
namespace wxbasic {

enum ByteCodeType {

};
// Bytecode class
class Code {
public:
    int last;                      // value of the last bytecode added
    std::vector<OpcodeType> pcode; // bytecode array
    std::vector<int> backpatch;    // list of address to backpatch
    Code();
    void emit(OpcodeType code);
    void emit_op(OpcodeType code);
};

} // namespace wxbasic
#endif // WXBASIC_CODE_H
