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

#include <iomanip>

#include "metadata.h"
#include "offsets.h"

namespace SPE {
Metadata::Metadata() : Data( 0, OFFSET_DATA ),
    m_ControllerVersion( 0 ),
    m_LogicOutput( 0 ),
    m_AmpHiCapLowNoise( 0 ),
    m_xdim( 0 ),
    m_ydim( 0 ),
    m_datatype( 0 ),
    m_NumFrames( 0 )
{}

/*!
 * \param file The file stream to read data from
 * \return void
 */
void Metadata::read( std::ifstream& file )
{
    Data::read( file );

    retrieve( m_ControllerVersion, OFFSET_CONTROLLERVERSION );
    retrieve( m_LogicOutput, OFFSET_LOGICOUTPUT );
    retrieve( m_AmpHiCapLowNoise, OFFSET_AMPHICAPLOWNOISE );
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

    m_ControllerVersion = 0;
    m_LogicOutput = 0;
    m_AmpHiCapLowNoise = 0;
    m_xdim = 0;
    m_ydim = 0;
    m_datatype = 0;
    m_NumFrames = 0;
}
}

/*!
 * \param out An output stream
 * \param metadata An instance of SPE metadata
 */
std::ostream& operator<< ( std::ostream& out, const SPE::Metadata& metadata )
{
    const int MAXWIDTH = 20;
    out << std::setw( MAXWIDTH ) << "# Field" << '\t' << "value" << '\n';
    out << std::setw( MAXWIDTH ) << "# -----" << '\t' << "-----" << '\n' << '\n';

    out << std::setw( MAXWIDTH ) << "ControllerVersion" << '\t' << metadata.m_ControllerVersion << '\n';
    out << std::setw( MAXWIDTH ) << "LogicOutput" << '\t' << metadata.m_LogicOutput << '\n';
    out << std::setw( MAXWIDTH ) << "AmpHiCapLowNoise" << '\t' << metadata.m_AmpHiCapLowNoise << '\n';
    out << std::setw( MAXWIDTH ) << "xdim" << '\t' << metadata.xdim() << '\n';
    out << std::setw( MAXWIDTH ) << "datatype" << '\t' << metadata.datatype() << '\n';
    out << std::setw( MAXWIDTH ) << "ydim" << '\t' << metadata.ydim() << '\n';
    out << std::setw( MAXWIDTH ) << "NumFrames" << '\t' << metadata.NumFrames() << '\n';

    return out;
}

