#pragma once

#include <fstream>
#include <iostream>
#include <memory>

class FileHandler {
public:
    FileHandler( std::string );

    void write_line( std::string );
    void read_line( std::string& );

    std::string filename_m;
    std::unique_ptr<std::fstream> file_m;

    ~FileHandler();

private:
};