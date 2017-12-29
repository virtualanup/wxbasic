#ifndef WXBASIC_CODE_H
#define WXBASIC_CODE_H

#include <vector>
#include <memory>

#include "opcode.h"
namespace wxbasic {

enum ByteCodeType {

};
// Bytecode class
class Code {
public:
    OpcodeType last;               // value of the last bytecode added
    std::vector<OpcodeType> pcode; // bytecode array
    std::vector<int> backpatch;    // list of address to backpatch

    Code();
    void clear();
    void emit(OpcodeType code);
    void emit_op(OpcodeType code);
    void append(std::shared_ptr<Code>);
};

} // namespace wxbasic
#endif // WXBASIC_CODE_H
