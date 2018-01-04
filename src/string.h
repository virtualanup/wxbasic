#ifndef WXBASIC_STRING_H
#define WXBASIC_STRING_H

#include "common.h"
#include "variant.h"
#include <memory>
#include <string>

namespace wxbasic {

class WString : public Variant {
    std::string value;

public:
    WString(const std::string& val="");
    ~WString();
};

} // namespace wxbasic

#endif // WXBASIC_STRING_H
