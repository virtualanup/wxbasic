#include "literal.h"
namespace wxbasic {

LiteralTable::LiteralTable() {}

LiteralTable::~LiteralTable() {}

// Adds a literal in the table and returns its index
size_t LiteralTable::add(std::shared_ptr<Variant> item) {
    table.push_back(item);
    return table.size() - 1;
}

// retrieve the value at the given index
std::shared_ptr<Variant> LiteralTable::get(size_t index) {
    return table[index];
}

} // namespace wxbasic
