#include "symbol.h"

namespace wxbasic {

// This is used to hash the <name, level> pair
// TODO: Replace this with something better
template <class T1, class T2>
std::size_t pair_hash::operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);
    return h1 ^ h2;
}
SymbolTable::SymbolTable() : current_scope(0) {}
SymbolTable::~SymbolTable() {}

void SymbolTable::unused(const std::string &name) {
    if (name.size() == 0 || name[0] == '_')
        return;

    if (!isalnum(name[0]))
        throw Error(name + " is not a valid name");

    // If item doesn't exist, return
    if (table.count(make_pair(name, current_scope)) == 0)
        return;

    Symbol sym = table[make_pair(name, current_scope)];
}

} // namespace wxbasic
