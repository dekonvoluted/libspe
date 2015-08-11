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
                std::int32_t pixel;
                const std::size_t offset = OFFSET_DATA + ( sizeof( pixel ) * ( ( metadata.xdim * metadata.ydim * frame ) + ( metadata.xdim * row ) + col ) );
                Data pixelData( offset, sizeof( pixel ) );
                pixelData.read( file );
                pixelData.retrieve( pixel );
                return pixel;
            }
            break;
        case 2:
            {
                std::int16_t pixel;
                const std::size_t offset = OFFSET_DATA + ( sizeof( pixel ) * ( ( metadata.xdim * metadata.ydim * frame ) + ( metadata.xdim * row ) + col ) );
                Data pixelData( offset, sizeof( pixel ) );
                pixelData.read( file );
                pixelData.retrieve( pixel );
                return pixel;
            }
        case 3:
            {
                std::uint16_t pixel;
                const std::size_t offset = OFFSET_DATA + ( sizeof( pixel ) * ( ( metadata.xdim * metadata.ydim * frame ) + ( metadata.xdim * row ) + col ) );
                Data pixelData( offset, sizeof( pixel ) );
                pixelData.read( file );
                pixelData.retrieve( pixel );
                return pixel;
            }
    }
    return -1.0f;
}

Eigen::ArrayXXf File::getFrame( const long frame )
{
    Eigen::ArrayXXf frameArray( metadata.ydim, metadata.xdim );
    const std::size_t frameDim = metadata.xdim * metadata.ydim;

    switch( metadata.datatype ) {
        case 0:
            {
                std::vector<float> pixels( frameDim, 0 );
                const std::size_t frameSize = frameDim * sizeof( float );
                const std::size_t offset = OFFSET_DATA + ( frameSize * frame );
                Data frameData( offset, frameSize );
                frameData.read( file );
                frameData.retrieve( *pixels.data(), 0, frameSize );

                auto count = 0;
                for ( auto row = 0; row < metadata.ydim; ++row ) {
                    for ( auto col = 0; col < metadata.xdim; ++col ) {
                        frameArray( row, col ) = pixels.at( count++ );
                    }
                }
            }
            break;
        case 1:
            {
                std::vector<std::int32_t> pixels( frameDim, 0 );
                const std::size_t frameSize = frameDim * sizeof( std::int32_t );
                const std::size_t offset = OFFSET_DATA + ( frameSize * frame );
                Data frameData( offset, frameSize );
                frameData.read( file );
                frameData.retrieve( *pixels.data(), 0, frameSize );

                auto count = 0;
                for ( auto row = 0; row < metadata.ydim; ++row ) {
                    for ( auto col = 0; col < metadata.xdim; ++col ) {
                        frameArray( row, col ) = pixels.at( count++ );
                    }
                }
            }
            break;
        case 2:
            {
                std::vector<std::int16_t> pixels( frameDim, 0 );
                const std::size_t frameSize = frameDim * sizeof( std::int16_t );
                const std::size_t offset = OFFSET_DATA + ( frameSize * frame );
                Data frameData( offset, frameSize );
                frameData.read( file );
                frameData.retrieve( *pixels.data(), 0, frameSize );

                auto count = 0;
                for ( auto row = 0; row < metadata.ydim; ++row ) {
                    for ( auto col = 0; col < metadata.xdim; ++col ) {
                        frameArray( row, col ) = pixels.at( count++ );
                    }
                }
            }
            break;
        case 3:
            {
                std::vector<std::uint16_t> pixels( frameDim, 0 );
                const std::size_t frameSize = frameDim * sizeof( std::uint16_t );
                const std::size_t offset = OFFSET_DATA + ( frameSize * frame );
                Data frameData( offset, frameSize );
                frameData.read( file );
                frameData.retrieve( *pixels.data(), 0, frameSize );

                auto count = 0;
                for ( auto row = 0; row < metadata.ydim; ++row ) {
                    for ( auto col = 0; col < metadata.xdim; ++col ) {
                        frameArray( row, col ) = pixels.at( count++ );
                    }
                }
            }
            break;
    }
    return frameArray;
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

