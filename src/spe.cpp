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
#include <cstddef>

#include "spe.h"
#include "data.h"
#include "metadata.h"

namespace SPE {
File::File( const std::string& filePath )
{
    read( filePath );
}

File::~File()
{
    if(  file.is_open() ) file.close();
}

void File::read( const std::string& filePath )
{
    if ( file.is_open() ) file.close();

    file.open( filePath.c_str(), std::ios::in | std::ios::binary );
    metadata.read( file );
}

float File::getPixel( const unsigned short row, const unsigned short col, const long frame )
{
    switch ( metadata.datatype ) {
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

Eigen::ArrayXXf File::getFrame( const long frame )
{
    switch ( metadata.datatype ) {
        case 0:
            return getFrameArray<float>( frame );
        case 1:
            return getFrameArray<std::int32_t>( frame );
        case 2:
            return getFrameArray<std::int16_t>( frame );
        case 3:
            return getFrameArray<std::uint16_t>( frame );
        default:
            return Eigen::ArrayXXf( metadata.ydim, metadata.xdim );
    }
}

Eigen::ArrayXXf File::getAverageFrame()
{
    Eigen::ArrayXXf averageFrame( metadata.ydim, metadata.xdim );

    for ( auto frame = 0; frame < metadata.NumFrames; ++frame ) {
        averageFrame += getFrame( frame );
    }

    return averageFrame / metadata.NumFrames;
}

unsigned short File::rows() const
{
    return metadata.ydim;
}

unsigned short File::columns() const
{
    return metadata.xdim;
}

long File::frames() const
{
    return metadata.NumFrames;
}
}

