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
    {SymbolType::SYM_USER_CLASS, "a class"},
    {SymbolType::SYM_BUILTIN_CLASS, "a builtin class"},
    {SymbolType::SYM_OBJECT, "an object"}};

struct Symbol {
public:
    SymbolType type;
    std::string name;
    int scope;

    std::shared_ptr<Symbol> parent;

    Symbol(const std::string &sym_name) { name = sym_name; }
    Symbol(const Symbol &sym) { name = sym.name; }
    std::string symbol_name() { return SymbolNames.at(type); }

    virtual ~Symbol() = 0; // pure virtual destructor.
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
    std::shared_ptr<ClassSymbol> superclass;

    ClassSymbol(const std::string &sym_name, bool is_abstract)
        : Symbol(sym_name) {
        abstract = is_abstract;
    }

    bool is_abstract() { return abstract; }

    std::shared_ptr<FunctionSymbol> find_method(const std::string &);

    ~ClassSymbol() {}
};

// global scope always has index 0
static const int global_scope = 0;

typedef std::unordered_map<std::string, int> SymbolTableObj;

class SymbolTable {
    // We maintain a hash table to map the symbol name and
    // the symbol scope to its index in the vector
    std::vector<SymbolTableObj> index;

    // vector is used to store all the symbols (for fast indexing)
    std::vector<std::shared_ptr<Symbol>> table;

    int current_scope;
    int class_scope;

public:
    SymbolTable();
    virtual ~SymbolTable();
    std::shared_ptr<Symbol> unused(const std::string &);
    std::shared_ptr<Symbol> find_symbol(const std::string &symbol_name);

    void add_symbol(std::shared_ptr<Symbol> sym);

    int enter_scope(int scope = -1);
};

} // namespace wxbasic
#endif // WXBASIC_SYMBOL_H
