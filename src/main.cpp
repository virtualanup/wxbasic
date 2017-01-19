#include<iostream>
#include<fstream>

#include"error.h"
#include"version.h"
#include"wxbasic.h"

int main(int argc, char* argv[])
{
    const std::string error = "Error: type wxbasic --help for more information";

    if(argc ==1 ||
            (argc == 2 &&
             (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")))
    {
        std::cout<<"\n"
            "Usage: wxbasic [options] filename.\n"
            " Options:\n"
            "  -h  --help     Print this help message.\n"
            "  -v  --version  Print version information.\n"
            "      --tokens   Print tokens.\n"
            "\n";
        return 0;
    }

    if(argc == 2 && (std::string(argv[1]) == "-v" || std::string(argv[1]) == "--version")) {
        std::cout<<"wxBasic Version: "<<wxbasic::VERSION<<std::endl;
        return 0;
    }

    try {

        if(argc == 3 && std::string(argv[1]) == "--tokens") {
            wxbasic::WxBasic basic = wxbasic::WxBasic(std::string(argv[2]));

            basic.parse();

            basic.print_tokens();

            return 0;
        }
    }
    catch(const wxbasic::Error &error) {
        std::cout<<error.get_message()<<std::endl;
        return 1;
    }
    catch(...) {
        std::cout<<"Unknown Error"<<std::endl;
    }

    std::cout<<error<<std::endl;
    return 1;
}
