#include "string.h"

namespace wxbasic {
WString::WString(const std::string &val)
    : Variant(false, VariantType::STRING) {}
WString::~WString() {}

} // namespace wxbasic
