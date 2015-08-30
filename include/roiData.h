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

#ifndef SPE_ROIDATA_H
#define SPE_ROIDATA_H

#include <fstream>
#include <cstdint>
#include <iostream>

#include "data.h"

namespace SPE {
/*! \brief Binary data present in an ROI info block
 *
 * This struct contains all the data present in an ROI info block.
 */
struct ROIData : public Data
{
    public:
    /*! \brief Create an empty ROI info block
     *
     * An empty instance of ROIData is created.
     * All fields of the ROIData default to zero (when applicable).
     */
    ROIData( const std::size_t );
    ~ROIData() = default;

    /*! \brief Read data from an opened SPE file
     *
     * This method extracts the binary data comprising an ROI info block from an opened SPE file.
     * The extracted bytes are stored internally for further processing.
     */
    void read( std::ifstream& );

    //! \brief left x start value
    std::uint16_t startx = 0;

    //! \brief right x value
    std::uint16_t endx = 0;

    //! \brief amount x is binned/grouped in hw
    std::uint16_t groupx = 0;

    //! \brief top y start value
    std::uint16_t starty = 0;

    //! \brief bottom y value
    std::uint16_t endy = 0;

    //! \brief amount y is binned/grouped in hw
    std::uint16_t groupy = 0;

    private:
    virtual void reset();
};
}

/*! \brief Output an ROI info block
 *
 * This method prints out the available info to an output stream
 */
std::ostream& operator<<( std::ostream&, const SPE::ROIData& );

#endif

