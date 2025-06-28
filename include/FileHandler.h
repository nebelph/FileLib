#pragma once

#include <fstream>
#include <iostream>
#include <memory>

class FileHandler {
public:
    FileHandler( std::string );

    void write_line();
    void read_line();

    std::string filename_m;
    std::fstream *file;

    ~FileHandler();

private:
};