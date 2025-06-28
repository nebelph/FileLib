#include "FileHandler.h"

FileHandler::FileHandler( std::string filename ) : filename_m( filename )
{
    file_m = std::make_unique<std::fstream>( filename_m, std::ios::in | std::ios::out );

    if ( file_m->is_open() ) {
        std::cout << filename_m << " is opened." << std::endl;
    } else {
        std::cerr << filename_m << " can not be opened." << std::endl;
    }
}

void FileHandler::write_line( std::string line )
{
    *file_m << line << std::endl;
}

void FileHandler::read_line( std::string &line )
{
    file_m->clear();
    file_m->seekg( 0 );

    std::getline( *file_m, line );
}

FileHandler::~FileHandler()
{
    if ( file_m->is_open() ) {
        file_m->close();

        std::cout << filename_m << " is closed." << std::endl;
    } else {
        std::cout << filename_m << " is already closed." << std::endl;
    }
}