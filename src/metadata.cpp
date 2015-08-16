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

#include "metadata.h"
#include "offsets.h"

namespace SPE {
Metadata::Metadata() : Data( 0, OFFSET_DATA ), m_xdim( 0 ), m_ydim( 0 ), m_datatype( 0 ), m_NumFrames( 0 )
{}

/*!
 * \param file The file stream to read data from
 * \return void
 */
void Metadata::read( std::ifstream& file )
{
    Data::read( file );

    retrieve( m_xdim, OFFSET_XDIM );
    retrieve( m_ydim, OFFSET_YDIM );
    retrieve( m_datatype, OFFSET_DATATYPE );
    retrieve( m_NumFrames, OFFSET_NUMFRAMES );
}

/*!
 * \return The number of rows in the image
 */
std::uint16_t Metadata::xdim() const
{
    return m_xdim;
}

/*!
 * \return The number of columns in the image
 */
std::uint16_t Metadata::ydim() const
{
    return m_ydim;
}

/*!
 * \return The datatype used to store pixel intensity in the image
 */
std::int16_t Metadata::datatype() const
{
    return m_datatype;
}

/*!
 * \return The number of frames in the image
 */
std::int32_t Metadata::NumFrames() const
{
    return m_NumFrames;
}

void Metadata::reset()
{
    Data::reset();

    m_xdim = 0;
    m_ydim = 0;
    m_datatype = 0;
    m_NumFrames = 0;
}
}

