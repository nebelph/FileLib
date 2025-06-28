#include <iostream>

#include "include/FileHandler.h"

int main()
{
    try {
        std::string filename_1 = "file.txt";
        FileHandler fh1( filename_1 );

        std::string filename_2 = "file.txt";
        FileHandler fh2( filename_2 );

        std::string r_line_2;
        fh2.read_line( r_line_2 );
        std::cout << "Read: " << r_line_2 << std::endl;

        std::string wr_line_1 = "Hello World!";
        fh1.write_line( wr_line_1 );

        std::string r_line_1;
        fh1.read_line( r_line_1 );
        std::cout << "Read: " << r_line_1 << std::endl;

    } catch ( const std::exception &e ) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}