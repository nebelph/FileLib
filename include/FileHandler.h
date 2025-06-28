#pragma once

#include <fstream>
#include <iostream>
#include <memory>

struct D
{
    D() {};
};

class FileHandler {
public:
    FileHandler( const std::string & );
    ~FileHandler();

    void write_line( const std::string & );
    void read_line( std::string & );

private:
    std::string m_filename;
    std::unique_ptr<std::fstream/*, D*/> m_file;
};