#ifndef WXBASIC_SYMBOL_H
#define WXBASIC_SYMBOL_H

#include "code.h"
#include "error.h"
#include <string>
#include <unordered_map>
#include <vector>

namespace wxbasic {

#define W_SYM_ISNATIVE 1   // native datatype
#define W_SYM_ISPRIVATE 2  // not publicly visible
#define W_SYM_ISABSTRACT 4 // applies to Class or method
#define W_SYM_ISVIRTUAL 8  // applies to method
#define W_SYM_ISSHARED 16  // can be called without instantiation

// types of symbols
enum class SymbolType {
    W_SYM_KEYWORD,       // keyword
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
protected:
    SymbolType type;

public:
    std::string name;

    Symbol(const std::string &sym_name) { name = sym_name; }
    Symbol(const Symbol &sym) { name = sym.name; }

    virtual ~Symbol() = 0; // pure virtual destructor.

    SymbolType get_type() { return type; }
};

struct LiteralSymbol : public Symbol {
    LiteralSymbol(const std::string &sym_name) : Symbol(sym_name) {}
    virtual ~LiteralSymbol() {}
};

struct FunctionSymbol : public Symbol {

    bool referenced;         // If this function is referenced
    void (*builtin)(void);   // pointer to builtin function (if this is builtin)
    std::vector<Code> pcode; // bytecode for the function

    FunctionSymbol(const std::string &sym_name)
        : Symbol(sym_name), referenced(false) {
        builtin = NULL;
    }
    virtual ~FunctionSymbol() {}
};

// global scope always has index 0
static const int global_scope = 0;

typedef std::unordered_map<std::string, std::shared_ptr<Symbol>> SymbolTableObj;

class SymbolTable {
    std::vector<SymbolTableObj> table;
    int current_scope;
    int class_scope;
public:
    SymbolTable();
    virtual ~SymbolTable();
    void unused(const std::string &);
    void add_symbol(std::shared_ptr<Symbol> sym);
};

} // namespace wxbasic
#endif // WXBASIC_SYMBOL_H
