#include "literal.h"
#include "number.h"
#include "string.h"
namespace wxbasic {

LiteralTable::LiteralTable() {}

LiteralTable::~LiteralTable() {}

// Adds a literal in the table and returns its index
size_t LiteralTable::add(std::shared_ptr<Variant> item) {
    table.push_back(item);
    return table.size() - 1;
}

size_t LiteralTable::add_integer(Integer val) {
    auto ival = std::shared_ptr<Variant>(new WInteger(val));
    return add(ival);
}
size_t LiteralTable::add_float(Float val) {
    auto fval = std::shared_ptr<Variant>(new WFloat(val));
    return add(fval);
}
size_t LiteralTable::add_string(const std::string &val) {
    auto sval = std::shared_ptr<Variant>(new WString());
    return add(sval);
}

// retrieve the value at the given index
std::shared_ptr<Variant> LiteralTable::get(size_t index) {
    return table[index];
}

} // namespace wxbasic
