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

#ifndef SPE_FILE_H
#define SPE_FILE_H

#include <string>
#include <fstream>
#include <Eigen/Core>

#include "metadata.h"
#include "offsets.h"

namespace SPE {
class File
{
    public:
    File() = default;
    File( const std::string& );
    ~File();

    void read( const std::string& );
    float getPixel( const unsigned short, const unsigned short, const long = 0 );
    Eigen::ArrayXXf getFrame( const long = 0 );
    Eigen::ArrayXXf getAverageFrame();

    unsigned short rows() const;
    unsigned short columns() const;
    long frames() const;

    Metadata metadata;

    private:
    std::ifstream file;

    template<class T> float getPixelValue( const unsigned short row, const unsigned short col, const long frame )
    {
        T pixel;
        const std::size_t offset = OFFSET_DATA + ( sizeof( pixel ) * ( ( metadata.xdim * metadata.ydim * frame ) + ( metadata.xdim * row ) + col ) );
        Data pixelData( offset, sizeof( pixel ) );
        pixelData.read( file );
        pixelData.retrieve( pixel );
        return pixel;
    }

    template<class T> Eigen::ArrayXXf getFrameArray( const long frame )
    {
        Eigen::ArrayXXf frameArray( metadata.ydim, metadata.xdim );
        const std::size_t frameDim = metadata.xdim * metadata.ydim;
        const std::size_t frameSize = frameDim * sizeof( T );
        const std::size_t offset = OFFSET_DATA + ( frameSize * frame );

        std::vector<T> pixels( frameDim, 0 );
        Data frameData( offset, frameSize );
        frameData.read( file );
        frameData.retrieve( *pixels.data(), 0, frameSize );

        auto count = 0;
        for ( auto row = 0; row < metadata.ydim; ++row ) {
            for ( auto col = 0; col < metadata.xdim; ++col ) {
                frameArray( row, col ) = pixels.at( count++ );
            }
        }

        return frameArray;
    }
};
}

#endif

