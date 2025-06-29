#include "utils.h"
#include "FileHandler.h"

int menu()
{
    std::string filename;
    std::string command;
    std::string line;
    std::vector<std::string> lines;
    FileHandler fh;

    do {
        filename = "";

        std::cout << "To stop the program, type 'stop'." << std::endl;
        std::cout << "To create or open a file, enter its name." << std::endl;

        std::getline( std::cin, filename );
        if ( filename == "stop" ) {
            break;
        }

        try {
            fh = FileHandler( filename );
        } catch ( const std::runtime_error &e ) {
            std::cerr << e.what() << std::endl;
            continue;
        }

        std::cout << "To write data, type 'write'." << std::endl;
        std::cout << "To read data, type 'read'." << std::endl;
        std::cout << "To close the file, type 'close'." << std::endl;

        std::cout << "*" << filename << "*\n";

        while ( std::cout << "> " && std::getline( std::cin, command ) ) {
            lines.clear();

            try {
                if ( command == "write" ) {
                    std::getline( std::cin, line );
                    fh.write_line( line );
                } else if ( command == "read" ) {
                    fh.read_all_lines( lines );
                    for (const auto& i : lines ) {
                        std::cout << i << std::endl;
                    }
                } else if ( command == "close" ) {
                    fh.reset();
                    break;
                } else {
                    std::cerr << "Invalid command! Please try again." << std::endl;
                }
            } catch ( const std::runtime_error &e ) {
                std::cerr << e.what() << std::endl;
            }
        }
    } while ( true );

    return 0;
}