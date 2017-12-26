#include "symbol.h"

namespace wxbasic {

Symbol::~Symbol() {}

SymbolTable::SymbolTable() {
    current_scope = global_scope;

    // Create a global scope
    table.push_back(SymbolTableObj());

    // Declare the global scope
    add_symbol(std::shared_ptr<FunctionSymbol>(new FunctionSymbol("__global")));
}

SymbolTable::~SymbolTable() {}

bool SymbolTable::unused(const std::string &name) {
    return true;
}

void SymbolTable::add_symbol(std::shared_ptr<Symbol> sym) {
    table[current_scope][sym->name] = sym;
}

} // namespace wxbasic
