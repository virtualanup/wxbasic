#ifndef WXBASIC_SYMBOL_H
#define WXBASIC_SYMBOL_H

#include "code.h"
#include "error.h"
#include <string>
#include <unordered_map>
#include <vector>

namespace wxbasic {

#define SYM_ISNATIVE 1   // native datatype
#define SYM_ISPRIVATE 2  // not publicly visible
#define SYM_ISABSTRACT 4 // applies to Class or method
#define SYM_ISVIRTUAL 8  // applies to method
#define SYM_ISSHARED 16  // can be called without instantiation

// types of symbols
enum class SymbolType {
    SYM_KEYWORD,       // keyword
    SYM_LITERAL,       // literal
    SYM_VARIABLE,      // variable
    SYM_CONSTANT,      // constant
    SYM_BUILTIN,       // builtin function
    SYM_FUNCTION,      // user defined function
    SYM_SUB,           // user defined sub
    SYM_USER_CLASS,    // user class name
    SYM_BUILTIN_CLASS, // builtin class name
    SYM_OBJECT         // instance of a class object
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
    ~LiteralSymbol() {}
};

struct FunctionSymbol : public Symbol {

    bool referenced;         // If this function is referenced
    void (*builtin)(void);   // pointer to builtin function (if this is builtin)
    std::vector<Code> pcode; // bytecode for the function

    FunctionSymbol(const std::string &sym_name)
        : Symbol(sym_name), referenced(false) {
        builtin = NULL;
    }
    ~FunctionSymbol() {}
};

struct ClassSymbol : public Symbol {
    bool abstract;

    ClassSymbol(const std::string &sym_name, bool is_abstract)
        : Symbol(sym_name) {
            abstract = is_abstract;
    }

    bool is_abstract(){return abstract;}

    ~ClassSymbol() {}
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
    bool unused(const std::string &);
    void add_symbol(std::shared_ptr<Symbol> sym);
};

} // namespace wxbasic
#endif // WXBASIC_SYMBOL_H
