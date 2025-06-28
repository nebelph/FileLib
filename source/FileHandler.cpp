#include "FileHandler.h"

FileHandler::FileHandler( std::string filename ) : filename_m( filename )
{
    file = new std::fstream( filename_m, std::ios::in | std::ios::out );
    if ( file->is_open() ) {
        std::cout << filename_m << " is opened." << std::endl;
    }
}

void FileHandler::write_line()
{
    *file << "Some information 1" << std::endl;
}

void FileHandler::read_line()
{
    file->clear();
    file->seekg(0);

    std::string line;

    while ( std::getline( *file, line ) ) {
        std::cout << "Read: " << line << std::endl;
    }
}

FileHandler::~FileHandler()
{
    if ( file->is_open() ) {
        file->close();
        delete file;

        std::cout << filename_m << " is closed." << std::endl;
    } else {
        std::cout << filename_m << " is already closed." << std::endl;
    }
}