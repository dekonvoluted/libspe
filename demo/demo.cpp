// This file is part of libspe, a C++ library to interface with spe files.
// Copyright (c) 2012,2013,2014,2015 Karthik Periagaram <dekonvoluted@gmail.com>
//
// libspe is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libspe is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libspe.  If not, see <http://www.gnu.org/licenses/>.

#include <vector>
#include <string>
#include <iostream>
#include <dirent.h>
#include <fnmatch.h>

#include "spe.h"

using namespace std;

int filter( const struct dirent* );
std::vector<std::string> findSPEFiles( const std::string& );

int main()
{
    // Find all SPE files in the current directory
    auto filePaths = findSPEFiles( "./" );

    for ( auto& filePath : filePaths ) {
        // Write out metadata from file
        SPE::File image( filePath );

        std::cout << "Image: " << filePath << std::endl;
        std::cout << "Size: " << image.rows() << " rows x " << image.columns() << " cols x " << image.frames() << " frames." << std::endl;
        std::cout << "Pixel( row: 0, col: 0, frame: 0 ): " << image.getPixel( 0, 0, 0 ) << std::endl;

        auto frame0 = image.getFrame( 0 );
        std::cout << "Frame 0: " << frame0( 0, 0 ) << " " << frame0( 0, 1 ) << " " << frame0( 0, 2 ) << "..." << std::endl;
        std::cout << "         " << frame0( 1, 0 ) << " " << frame0( 1, 1 ) << " " << frame0( 1, 2 ) << "..." << std::endl;
        std::cout << "         " << frame0( 2, 0 ) << " " << frame0( 2, 1 ) << " " << frame0( 2, 2 ) << "..." << std::endl;
        std::cout << std::endl;
    }

    return 0;
}

// Find files in a given directory
std::vector<std::string> findSPEFiles( const std::string& directory )
{
    std::vector<std::string> filePaths;

    // Return empty vector if directory is invalid
    if ( not opendir( directory.c_str() ) ) return filePaths;

    // Find all filtered files in directory
    struct dirent** files;
    auto numFiles = scandir( directory.c_str(), &files, filter, alphasort );

    for ( auto count = 0; count < numFiles; ++count )
        filePaths.push_back( files[ count ]->d_name );

    return filePaths;
}

// Filter files with extension (case-insensitive)
int filter( const struct dirent* file )
{
    return not fnmatch( "*.spe", file->d_name, FNM_CASEFOLD );
}

