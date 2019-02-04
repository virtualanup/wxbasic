#ifndef WXBASIC_NUMBER_H
#define WXBASIC_NUMBER_H

#include "common.h"
#include "variant.h"
#include <memory>
#include <string>

namespace wxbasic {

class WNumber : public Variant {
public:
    WNumber(VariantType type);

    ~WNumber();
};

// Class for storing integers. This can be extended to support Big integers
class WInteger : public WNumber {
    Integer value;

public:
    WInteger(Integer n) : WNumber(VariantType::INTEGER), value(n) {}
    WInteger() : WInteger(0) {}

    Integer getValue() { return value; }
};

// Class for storing floating point numbers
class WFloat : public WNumber {
    Float value;

public:
    WFloat(Float n) : WNumber(VariantType::FLOAT) {}
    WFloat() : WFloat(0.0) {}

    Float get_value() { return value; }
};

} // namespace wxbasic

#endif // WXBASIC_NUMBER_H
