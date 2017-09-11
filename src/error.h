
#ifndef WXBASIC_ERROR_H
#define WXBASIC_ERROR_H

#include <memory>
#include <string>

namespace wxbasic {

class Error {
    std::string message;

public:
    Error(const std::string &);
    Error(const std::string &error, size_t pos, const std::string &source,
          const std::string &source_name);

    std::string get_message() const;
};
}

#endif // WXBASIC_ERROR_H
