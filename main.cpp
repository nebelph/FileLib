#include <iostream>

#include "include/FileHandler.h"

int main()
{
    std::cout << "This is my File Library!\n";

    std::string filename = "file.txt";
    FileHandler fh(filename);
    
    fh.write_line();

    fh.read_line();

    return 0;
}