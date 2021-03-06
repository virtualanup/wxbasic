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
    SYM_LITERAL,       // literal
    SYM_VARIABLE,      // variable
    SYM_CONSTANT,      // constant
    SYM_BUILTIN,       // builtin function
    SYM_FUNCTION,      // user defined function
    SYM_USER_CLASS,    // user class name
    SYM_BUILTIN_CLASS, // builtin class name
    SYM_OBJECT         // instance of a class object
};

static const std::unordered_map<SymbolType, std::string> SymbolNames{
    {SymbolType::SYM_LITERAL, "a literal"},
    {SymbolType::SYM_VARIABLE, "a variable"},
    {SymbolType::SYM_CONSTANT, "a constant"},
    {SymbolType::SYM_BUILTIN, "a builtin routine"},
    {SymbolType::SYM_FUNCTION, "a function"},
    {SymbolType::SYM_USER_CLASS, "a user-defined class"},
    {SymbolType::SYM_BUILTIN_CLASS, "a builtin class"},
    {SymbolType::SYM_OBJECT, "an object"}};

struct Symbol {
public:
    SymbolType type;  // type of the symbol
    std::string name; // name of the symbol

    size_t scope; // scope of this symbol
    size_t index; // index at the symbol table

    std::shared_ptr<Symbol> parent;

    Symbol(const std::string &sym_name, SymbolType stype) {
        name = sym_name;
        type = stype;
    }
    std::string symbol_name() { return SymbolNames.at(type); }

    virtual ~Symbol() = 0; // pure virtual destructor.
};

struct LiteralSymbol : public Symbol {
    LiteralSymbol(const std::string &sym_name)
        : Symbol(sym_name, SymbolType::SYM_LITERAL) {}
    ~LiteralSymbol() {}
};

// Common parent of funciton symbol and class symbol
struct FuncClassSymbol : public Symbol {
    int flags;
    FuncClassSymbol(const std::string &sym_name, SymbolType stype)
        : Symbol(sym_name, stype) {
        flags = 0;
    }
    virtual ~FuncClassSymbol() = 0;
    bool is_abstract() { return (flags & SYM_ISABSTRACT) != 0; }
};

struct FunctionSymbol : public FuncClassSymbol {

    bool referenced;       // If this function is referenced
    void (*builtin)(void); // pointer to builtin function (if this is builtin)
    size_t args;           // number of arguments
    size_t opt_args;       // optional args
    bool va_args;          // is variable argument?

    std::vector<Code> pcode; // bytecode for the function

    FunctionSymbol(const std::string &sym_name)
        : FuncClassSymbol(sym_name, SymbolType::SYM_FUNCTION),
          referenced(false) {
        builtin = NULL;
        args = 0;
        opt_args = 0;
        va_args = false;
    }
    ~FunctionSymbol() {}
};

struct ClassSymbol : public FuncClassSymbol {
    // The scope created by this class. Members will be created
    // in this scope
    size_t class_scope;

    // Class that this class inherited from
    std::shared_ptr<ClassSymbol> superclass;

    std::unordered_map<std::string, std::shared_ptr<Symbol>> members;
    std::unordered_map<std::string, std::shared_ptr<FunctionSymbol>> methods;

    ClassSymbol(const std::string &sym_name)
        : FuncClassSymbol(sym_name, SymbolType::SYM_USER_CLASS) {}

    std::shared_ptr<FunctionSymbol> find_method(const std::string &);

    ~ClassSymbol() {}
};

// global scope always has index 0
static const int global_scope = 0;

typedef std::unordered_map<std::string, size_t> SymbolTableObj;

class SymbolTable {
    // We maintain a hash table to map the symbol name and
    // the symbol scope to its index in the vector
    std::vector<SymbolTableObj> index;

    // this is a list of owners of the scopes
    std::vector<std::shared_ptr<Symbol>> scope_owners;

    // vector is used to store all the symbols (for fast indexing)
    std::vector<std::shared_ptr<Symbol>> table;

    size_t current_scope;
    size_t class_scope;

public:
    SymbolTable();
    virtual ~SymbolTable();
    std::shared_ptr<Symbol> unused(const std::string &);

    std::shared_ptr<Symbol> find_symbol(const std::string &symbol_name);

    void add_symbol(std::shared_ptr<Symbol> sym);

    // enter an existing scope for the given symbol
    int create_scope(std::shared_ptr<Symbol> owner);

    void enter_scope(size_t scope);
    std::shared_ptr<Symbol> scope_owner(size_t scope);

    void print();
};

} // namespace wxbasic
#endif // WXBASIC_SYMBOL_H
