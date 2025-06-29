#pragma once

#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

struct D {
    D() { };
};

class FileHandler {
public:
    FileHandler();
    FileHandler( const std::string & );
    ~FileHandler();

    FileHandler &operator=( FileHandler && ) noexcept;

    void write_line( const std::string & );
    void read_line( std::string & );
    void read_all_lines( std::vector<std::string> & );

    void reset();

private:
    std::string m_filename;
    std::unique_ptr<std::fstream> m_file;
};