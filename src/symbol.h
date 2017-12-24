#ifndef WXBASIC_SYMBOL_H
#define WXBASIC_SYMBOL_H

#include "error.h"
#include <string>
#include <unordered_map>

namespace wxbasic {

#define W_SYM_ISNATIVE 1   // native datatype
#define W_SYM_ISPRIVATE 2  // not publicly visible
#define W_SYM_ISABSTRACT 4 // applies to Class or method
#define W_SYM_ISVIRTUAL 8  // applies to method
#define W_SYM_ISSHARED 16  // can be called without Me


struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const;
};

// types of symbols
enum SymbolType {
    W_SYM_KEYWORD = 1,   // keyword
    W_SYM_LITERAL,       // literal
    W_SYM_VARIABLE,      // variable
    W_SYM_CONSTANT,      // constant
    W_SYM_BUILTIN,       // builtin function
    W_SYM_FUNCTION,      // user defined function
    W_SYM_SUB,           // user defined sub
    W_SYM_USER_CLASS,    // user class name
    W_SYM_BUILTIN_CLASS, // builtin class name
    W_SYM_OBJECT         // instance of a class object
};

struct Symbol {
    std::string name;
    int index;
};

class SymbolTable {
    std::unordered_map<std::pair<std::string, int>, Symbol, pair_hash> table;

    int current_scope;
    int global_scope;
public:
    SymbolTable();
    virtual ~SymbolTable();
    void unused(const std::string &);
};

} // namespace wxbasic
#endif // WXBASIC_SYMBOL_H
