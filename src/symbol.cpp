#include "symbol.h"
#include <iostream>

namespace wxbasic {

Symbol::~Symbol() {}
FuncClassSymbol::~FuncClassSymbol() {}

SymbolTable::SymbolTable() {
    // Create the global scope
    current_scope = 0;
    class_scope = 0;

    auto global_sym =
        std::shared_ptr<FunctionSymbol>(new FunctionSymbol("__global"));

    create_scope(global_sym);

    // Add the global function symbol in its own scope
    add_symbol(global_sym);
}

int SymbolTable::create_scope(std::shared_ptr<Symbol> owner) {
    // Create a new index for the scope
    int free_scope = index.size();
    index.push_back(SymbolTableObj());
    scope_owners.push_back(owner);
    return free_scope;
}

std::shared_ptr<Symbol> SymbolTable::scope_owner(size_t scope) {
    return scope_owners[scope];
}

void SymbolTable::enter_scope(size_t scope) {
    if (scope >= index.size()) {
        // Scope doesn't exist. throw error.
    }
    current_scope = scope;
    if (scope_owners[current_scope]->type == SymbolType::SYM_BUILTIN_CLASS ||
        scope_owners[current_scope]->type == SymbolType::SYM_USER_CLASS) {
        class_scope = current_scope;
    } else
        class_scope = 0;
}

SymbolTable::~SymbolTable() {}

std::shared_ptr<Symbol> SymbolTable::unused(const std::string &name) {
    auto symbol = find_symbol(name);

    // If symbol not found, do nothing
    if (symbol == NULL)
        return NULL;
    else if (current_scope != global_scope &&
             symbol->type == SymbolType::SYM_VARIABLE &&
             symbol->scope == global_scope) {
        // symbol is global variable and we are in local scope. Do nothing
    } else if (class_scope != 0 && symbol->scope == class_scope) {
        // Global symbol but we're inside a class
    } else {
        return symbol;
    }
    return NULL;
}

void SymbolTable::add_symbol(std::shared_ptr<Symbol> sym) {
    // Append it to the symbol list
    table.push_back(sym);
    // Store the index
    sym->index = table.size() - 1;

    sym->scope = current_scope;

    // Store the index in hash table
    index[current_scope][sym->name] = table.size() - 1;
}

std::shared_ptr<Symbol>
SymbolTable::find_symbol(const std::string &symbol_name) {
    // tries to find the symbol in local scope. If not found, tries to find
    // it in class scope. If not found, tries to find it in global scope
    if (index[current_scope].count(symbol_name) != 0)
        return table[index[current_scope].at(symbol_name)];

    if (class_scope > 0 && index[class_scope].count(symbol_name) != 0)
        return table[index[class_scope].at(symbol_name)];

    if (index[global_scope].count(symbol_name) == 1)
        return table[index[global_scope].at(symbol_name)];

    // No symbol found
    return NULL;
}

// find method of a class
std::shared_ptr<FunctionSymbol>
ClassSymbol::find_method(const std::string &name) {
    // Try to find the method in current scope
    if (methods.count(name) == 1)
        return methods.at(name);

    if (superclass == NULL)
        return NULL;

    // try to find the method in superclass
    return superclass->find_method(name);
}

void SymbolTable::print() {
    std::cout << "Symbol Table: " << std::endl;
    for (size_t i = 0; i < index.size(); i++) {
        auto owner = scope_owners[i];
        std::cout << "Table for " << owner->name << " of "
                  << SymbolNames.at(owner->type) << std::endl;
        // print out all the children
        auto objects = index[i];
        for (auto item : index[i]) {
            std::cout << "\t" << item.first << " is "
                      << SymbolNames.at(table[item.second]->type) << std::endl;
        }
        std::cout<<std::endl;
    }
    std::cout << std::endl << std::endl;
}

} // namespace wxbasic
