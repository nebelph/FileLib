#include "FileHandler.h"

FileHandler::FileHandler() = default;

FileHandler::FileHandler( const std::string &filename ) : m_filename( filename )
{
    m_file = std::make_unique<std::fstream>( m_filename, std::ios::in | std::ios::out | std::ios::app );

    if ( ! m_file->is_open() ) {
        throw std::runtime_error( "File can't be created or opened: " + m_filename );
    }
}

FileHandler::~FileHandler() = default;

FileHandler &FileHandler::operator=( FileHandler &&other ) noexcept
{
    if ( this != &other ) {
        m_filename = std::move( other.m_filename );
        m_file = std::move( other.m_file );
    }
    return *this;
}

void FileHandler::write_line( const std::string &line )
{
    m_file->clear();

    *m_file << line << std::endl;
    if ( m_file->fail() ) {
        throw std::runtime_error( "Error while writing to file: " + m_filename );
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
            throw std::runtime_error( "Error while reading file: " + m_filename );
        }
    }
}

void FileHandler::read_all_lines( std::vector<std::string> &vec )
{
    m_file->clear();
    m_file->seekg( 0 );

    std::string line = "";
    vec.clear();

    while ( std::getline( *m_file, line ) ) {
        vec.push_back( line );
    }

    if ( m_file->bad() ) {
        throw std::runtime_error( "Error while reading file: " + m_filename );
    }
}

void FileHandler::reset()
{
    m_file->close();
    m_filename.clear();
}