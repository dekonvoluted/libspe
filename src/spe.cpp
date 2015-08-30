// This file is part of libSPE, a C++ library to interface with SPE files.
//
// Copyright (c) 2012,2013,2014,2015 Karthik Periagaram <dekonvoluted@gmail.com>
//
// libSPE is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libSPE is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libSPE. If not, see <http://www.gnu.org/licenses/>.

#include <vector>
#include <cstddef>
#include <sys/stat.h>
#include <stdexcept>

#include "spe.h"
#include "data.h"
#include "metadata.h"

namespace SPE {
/*!
 * \param filePath The path to the SPE file
 */
File::File( const std::string& filePath )
{
    // Verify that the given file path exists
    struct stat buffer;
    if ( stat( filePath.c_str(), &buffer ) ) throw std::runtime_error( "File " + filePath + " does not exist." );

    read( filePath );
}

File::~File()
{
    if(  file.is_open() ) file.close();
}

/*!
 * \param filePath The path to the SPE file
 */
void File::read( const std::string& filePath )
{
    if ( file.is_open() ) file.close();

    file.open( filePath.c_str(), std::ios::in | std::ios::binary );
    metadata.read( file );
}

/*!
 * \param row The index of the row of the image, starts at 0
 * \param col The index of the column of the image, starts at 0
 * \param frame The index of the frame of the image, starts at 0
 * \return The intensity of the pixel
 */
float File::getPixel( const unsigned short row, const unsigned short col, const long frame )
{
    switch ( metadata.datatype() ) {
        case 0:
            return getPixelValue<float>( row, col, frame );
        case 1:
            return getPixelValue<std::int32_t>( row, col, frame );
        case 2:
            return getPixelValue<std::int16_t>( row, col, frame );
        case 3:
            return getPixelValue<std::uint16_t>( row, col, frame );
        default:
            return 0.0;
    }
}

/*!
 * \param frame The index of the frame of the image, starts at 0
 * \return An array of pixel intensities forming one frame of the image
 */
Eigen::ArrayXXf File::getFrame( const long frame )
{
    switch ( metadata.datatype() ) {
        case 0:
            return getFrameArray<float>( frame );
        case 1:
            return getFrameArray<std::int32_t>( frame );
        case 2:
            return getFrameArray<std::int16_t>( frame );
        case 3:
            return getFrameArray<std::uint16_t>( frame );
        default:
            return Eigen::ArrayXXf( metadata.ydim(), metadata.xdim() );
    }
}

/*!
 * \return An array of pixel intensities forming the average of all frames in the SPE file
 */
Eigen::ArrayXXf File::getAverageFrame()
{
    Eigen::ArrayXXf averageFrame( metadata.ydim(), metadata.xdim() );

    for ( auto frame = 0; frame < metadata.NumFrames(); ++frame ) {
        averageFrame += getFrame( frame );
    }

    averageFrame /= metadata.NumFrames();

    return averageFrame;
}

/*!
 * \return The number of rows in one frame of the image
 */
std::size_t File::rows() const
{
    return metadata.ydim();
}

/*!
 * \return The number of columns in one frame of the image
 */
std::size_t File::columns() const
{
    return metadata.xdim();
}

/*!
 * \return The number of frames of the image
 */
std::size_t File::frames() const
{
    return metadata.NumFrames();
}
}

