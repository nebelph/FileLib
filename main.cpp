#include <iostream>

#include "include/FileHandler.h"

int main()
{
    try {
        std::string filename = "file.txt";
        FileHandler fh(filename);
        
        std::string wr_line = "Hello World!";
        fh.write_line(wr_line);

        std::string r_line;
        fh.read_line(r_line);
        std::cout << "Read: " << r_line << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}