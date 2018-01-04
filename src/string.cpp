#include "string.h"

namespace wxbasic {
WString::WString(const std::string &val)
    : Variant(false, VariantType::STRING), value(val) {}
WString::~WString() {}

} // namespace wxbasic
