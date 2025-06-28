#include "FileHandler.h"

FileHandler::FileHandler( const std::string &filename ) : m_filename( filename )
{
    // std::unique_ptr<std::fstream> raw_file = std::make_unique<std::fstream>( m_filename, std::ios::in | std::ios::out | std::ios::trunc );
    // D d;
    // m_file = std::unique_ptr<std::fstream, D>( raw_file.release(), d );

    m_file = std::make_unique<std::fstream>( m_filename, std::ios::in | std::ios::out | std::ios::trunc );
    
    if ( ! m_file->is_open() ) {
        throw std::runtime_error( "File can't be opened: " + m_filename );
    }
}

FileHandler::~FileHandler() = default;

void FileHandler::write_line( const std::string &line )
{
    *m_file << line << std::endl;
    if ( m_file->fail() ) {
        throw std::runtime_error( "Can't write to file: " + m_filename );
    }
}

void FileHandler::read_line( std::string &line )
{
    m_file->clear();
    m_file->seekg( 0 );

    if ( ! std::getline( *m_file, line ) ) {
        if ( m_file->eof() ) {
            line.clear();
        } else {
            throw std::runtime_error( "Can't read file: " + m_filename );
        }
    }
}