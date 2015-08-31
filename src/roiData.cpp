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

#include <iomanip>

#include "roiData.h"

namespace SPE {
//! \param OFFSET The offset at which the current ROI info block begins
ROIData::ROIData( const std::size_t OFFSET ) : Data( OFFSET, 12 )
{}

/*!
 * \param file The file stream to read data from
 * \return void
 */
void ROIData::read( std::ifstream& file )
{
    Data::read( file );

    retrieve( startx, 0 );
    retrieve( endx, 2 );
    retrieve( groupx, 4 );
    retrieve( starty, 6 );
    retrieve( endy, 8 );
    retrieve( groupy, 10 );
}

void ROIData::reset()
{
    Data::reset();

    startx = 0;
    endx = 0;
    groupx = 0;
    starty = 0;
    endy = 0;
    groupy = 0;
}
}

/*!
 * \param out An output stream
 * \param roiData An instance of SPE ROI data
 */
std::ostream& operator<<( std::ostream& out, const SPE::ROIData& roiData )
{
    const int MAXWIDTH = 20;
    out << std::setw( MAXWIDTH ) << "startx" << '\t' << roiData.startx << '\n';
    out << std::setw( MAXWIDTH ) << "endx" << '\t' << roiData.endx << '\n';
    out << std::setw( MAXWIDTH ) << "groupx" << '\t' << roiData.groupx << '\n';
    out << std::setw( MAXWIDTH ) << "starty" << '\t' << roiData.starty << '\n';
    out << std::setw( MAXWIDTH ) << "endy" << '\t' << roiData.endy << '\n';
    out << std::setw( MAXWIDTH ) << "groupy" << '\t' << roiData.groupy;

    return out;
}

