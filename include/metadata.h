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

#ifndef SPE_METADATA_H
#define SPE_METADATA_H

#include <fstream>
#include <cstdint>

#include "data.h"

namespace SPE {
/*! \brief The metadata associated with the SPE file
 *
 * This struct contains all the metadata present in the header of the SPE file.
 * The implementation is compatible with SPE version 2.5 headers.
 */
    struct Metadata : public Data
{
    public:
    /*! \brief Create an empty metadata instance
     *
     * An empty instance of metadata is created.
     * All fields of metadata default to zero (when applicable).
     */
    Metadata();
    ~Metadata() = default;

    /*! \brief Read metadata from an opened SPE file
     *
     * This method extracts the binary metadata from an open SPE file.
     * The extracted bytes are stored internally for further processing.
     */
    void read( std::ifstream& );

    /*! \brief The number of columns in the image
     */
    std::uint16_t xdim;

    /*! \brief The number of rows in the image
     */
    std::uint16_t ydim;

    /*! \brief The datatype of intensity of each pixel in the image
     *
     * This is the internal representation of the intensity of each pixel in the image.
     * The possible values are:
     * - 0 = floating point, 4 bytes per pixel
     * - 1 = long integer, 4 bytes per pixel
     * - 2 = short integer, 2 bytes per pixel
     * - 3 = unsigned short integer, 2 bytes per pixel
     */
    std::int16_t datatype;

    /*! \brief The number of frames present in the SPE file
     */
    std::int32_t NumFrames;

    private:
    virtual void reset();
};
}

#endif

