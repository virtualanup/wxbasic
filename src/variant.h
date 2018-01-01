#ifndef WXBASIC_VARIANT_H
#define WXBASIC_VARIANT_H

#include "common.h"
#include <string>

namespace wxbasic {

enum class VariantType {
    STRING,
    INTEGER,
    FLOAT,
    OBJECT,
    ARRAY,
    TABLE,
    LIST,
    VARPTR,
    ROUTINE,
    TIME
};

class Variant {
    VariantType type;
    VariantType cast;

    virtual ~Variant() = 0;
};

} // namespace wxbasic

#endif // WXBASIC_VARIANT_H
