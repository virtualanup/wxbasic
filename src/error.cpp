#include"error.h"

namespace wxbasic {

    Error::Error(const std::string& error)
    {
        message = "Error : "+ error;
    }

    Error::Error(const std::string &error, size_t pos, const std::string &source, const std::string &source_name)
    {
        message = "Error : " + error;
    }

    std::string Error::get_message() const
    {
        return message;
    }
}
