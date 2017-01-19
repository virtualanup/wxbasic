#include"error.h"

namespace wxbasic {

    Error::Error(const std::string& error)
    {
        message = "Error : "+ error;
    }

    Error::Error(const std::string &error, size_t pos, const std::string &source, const std::string &source_name)
    {
        size_t a = 0;
        if(pos > 20)
            a = pos-20;
        size_t b = source.size();
        if(b > pos+20)
            b= pos+20;

        message = "Error : "+error+"\n";
        message += "In file "+source_name+"\n";
        for(size_t i =a; i<b; i++)
            message += source[i];

        message += "\n";

        for(size_t i =a; i<pos; i++)
            message += "-";
        message += "^";


    }

    std::string Error::get_message() const
    {
        return message;
    }
}
