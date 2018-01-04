#ifndef WXBASIC_LITERAL_H
#define WXBASIC_LITERAL_H

#include <string>
#include <vector>

#include "common.h"
#include "variant.h"

namespace wxbasic {

// Literal table store literal values like value of a dictionary, value of
// a string, etc.

// TODO: Hash the literal value to avoid duplicates?
class LiteralTable {
    std::vector<std::shared_ptr<Variant>> table;

public:
    LiteralTable();
    ~LiteralTable();

    size_t add(std::shared_ptr<Variant> item);

    size_t add_integer(Integer val);
    size_t add_float(Float val);
    size_t add_string(const std::string &);

    std::shared_ptr<Variant> get(size_t index);
};

} // namespace wxbasic

#endif // WXBASIC_LITERAL_H
