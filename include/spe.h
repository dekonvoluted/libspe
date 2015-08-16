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
/*! \brief An SPE file
 *
 * This class contains all the methods needed to read and extract data and metadata from an SPE image file.
 * SPE files usually have an extension .SPE or .spe and contain one or more frames of data.
 * The data could be an image (multiple rows, multiple columns) or a spectrum (single row, multiple columns).
 *
 * This release of libspe supports SPE version 2.5 headers.
 */
class File
{
    public:
    /*! \brief Create an empty instance of SPE file
     *
     * The path to an SPE file can be provided later using the SPE::File::read() method.
     */
    File() = default;

    /*! \brief Create an instance of SPE file located at a given path
     *
     * The provided path is used to open an SPE file and read in the header containing metadata about the file.
     * Image data, in the form of frames can be extracted when needed.
     */
    File( const std::string& );
    ~File();

    /*! \brief Open an SPE file for reading
     *
     * This method opens an SPE file and extracts metadata from the header.
     * The file is kept open for subsequent methods to retrieve image data.
     * If this instance of SPE::File was initialized with another file path, the earlier metadata and file handle are replaced.
     */
    void read( const std::string& );

    /*! \brief Get intensity of a specified pixel
     *
     * This is a simple method to demonstrate how a single pixel can be retrieved from any frame.
     * The frame number is optional and defaults to the first frame (0) if not provided explicitly.
     */
    float getPixel( const unsigned short, const unsigned short, const long = 0 );

    /*! \brief Get one frame of data
     *
     * Fetches the specified frame from the file in the form of an Eigen::ArrayXXf of floating point values.
     * While the internal representation of the data in the SPE file could be integers or floating point values, the output will always be floating point values.
     * If the optional frame number is not provided, it defaults to 0 and fetches the first frame.
     */
    Eigen::ArrayXXf getFrame( const long = 0 );

    /*! \brief Get the average of all frames in the image
     *
     * This method calculates the mean intensity of all the pixels forming the image.
     * The average of all the frames of data is returned.
     */
    Eigen::ArrayXXf getAverageFrame();

    /*! \brief Get the number of rows in the image
     *
     * This is a convenient way to access the number of rows in the image.
     */
    std::size_t rows() const;

    /*! \brief Get the number of columns in the image
     *
     * This is a convenient way to access the number of columns in the image.
     */
    std::size_t columns() const;

    /*! \brief Get the number of frames in the image
     *
     * This is a convenient way to access the number of frames in the image.
     */
    std::size_t frames() const;

    /*! \brief Directly access metadata obtained from the header
     *
     * This instance contains all the available metadata in the header of the SPE file.
     * Note that this access to each of the metadata fields comes with write privileges.
     * Modifying the values will have no effect on the file itself.
     */
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

