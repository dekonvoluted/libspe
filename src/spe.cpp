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
#include "offsets.h"

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
    switch( metadata.datatype ) {
        case 0:
            {
                float pixel;
                const std::size_t offset = OFFSET_DATA + ( sizeof( pixel ) * ( ( metadata.xdim * metadata.ydim * frame ) + ( metadata.xdim * row ) + col ) );
                Data pixelData( offset, sizeof( pixel ) );
                pixelData.read( file );
                pixelData.retrieve( pixel );
                return pixel;
            }
        case 1:
            {
                int32_t pixel;
                const std::size_t offset = OFFSET_DATA + ( sizeof( pixel ) * ( ( metadata.xdim * metadata.ydim * frame ) + ( metadata.xdim * row ) + col ) );
                Data pixelData( offset, sizeof( pixel ) );
                pixelData.read( file );
                pixelData.retrieve( pixel );
                return pixel;
            }
            break;
        case 2:
            {
                int16_t pixel;
                const std::size_t offset = OFFSET_DATA + ( sizeof( pixel ) * ( ( metadata.xdim * metadata.ydim * frame ) + ( metadata.xdim * row ) + col ) );
                Data pixelData( offset, sizeof( pixel ) );
                pixelData.read( file );
                pixelData.retrieve( pixel );
                return pixel;
            }
        case 3:
            {
                uint16_t pixel;
                const std::size_t offset = OFFSET_DATA + ( sizeof( pixel ) * ( ( metadata.xdim * metadata.ydim * frame ) + ( metadata.xdim * row ) + col ) );
                Data pixelData( offset, sizeof( pixel ) );
                pixelData.read( file );
                pixelData.retrieve( pixel );
                return pixel;
            }
    }
    return -1.0f;
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

