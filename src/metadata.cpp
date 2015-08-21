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
Metadata::Metadata() : Data( 0, OFFSET_DATA )
{}

/*!
 * \param file The file stream to read data from
 * \return void
 */
void Metadata::read( std::ifstream& file )
{
    Data::read( file );

    retrieve( ControllerVersion, OFFSET_CONTROLLERVERSION );
    retrieve( LogicOutput, OFFSET_LOGICOUTPUT );
    retrieve( AmpHiCapLowNoise, OFFSET_AMPHICAPLOWNOISE );
    retrieve( xDimDet, OFFSET_XDIMDET );
    retrieve( mode, OFFSET_MODE );
    retrieve( exp_sec, OFFSET_EXP_SEC );
    retrieve( VChipXdim, OFFSET_VCHIPXDIM );
    retrieve( VChipYdim, OFFSET_VCHIPYDIM );
    retrieve( yDimDet, OFFSET_YDIMDET );
    retrieve( date[0], OFFSET_DATE, DATEMAX );
    retrieve( VirtualChipFlag, OFFSET_VIRTUALCHIPFLAG );
    retrieve( noscan, OFFSET_NOSCAN );
    retrieve( DetTemperature, OFFSET_DETTEMPERATURE );
    retrieve( DetType, OFFSET_DETTYPE );
    retrieve( m_xdim, OFFSET_XDIM );
    retrieve( stdiode, OFFSET_STDIODE );
    retrieve( DelayTime, OFFSET_DELAYTIME );
    retrieve( ShutterControl, OFFSET_SHUTTERCONTROL );
    retrieve( AbsorbLive, OFFSET_ABSORBLIVE );
    retrieve( AbsorbMode, OFFSET_ABSORBMODE );
    retrieve( CanDoVirtualChipFlag, OFFSET_CANDOVIRTUALCHIPFLAG );
    retrieve( ThresholdMinLive, OFFSET_THRESHOLDMINLIVE );
    retrieve( ThresholdMinVal, OFFSET_THRESHOLDMINVAL );
    retrieve( ThresholdMaxLive, OFFSET_THRESHOLDMAXLIVE );
    retrieve( ThresholdMaxVal, OFFSET_THRESHOLDMAXVAL );
    retrieve( SpecAutoSpectroMode, OFFSET_SPECAUTOSPECTROMODE );
    retrieve( SpecCenterWlNm, OFFSET_SPECCENTERWLNM );
    retrieve( SpecGlueFlag, OFFSET_SPECGLUEFLAG );
    retrieve( SpecGlueStartWlNm, OFFSET_SPECGLUESTARTWLNM );
    retrieve( SpecGlueEndWlNm, OFFSET_SPECGLUEENDWLNM );
    retrieve( SpecGlueMinOvrlpNm, OFFSET_SPECGLUEMINOVRLPNM );
    retrieve( m_datatype, OFFSET_DATATYPE );
    retrieve( m_ydim, OFFSET_YDIM );
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
 * \return The datatype used to store pixel intensity in the image
 */
std::int16_t Metadata::datatype() const
{
    return m_datatype;
}

/*!
 * \return The number of columns in the image
 */
std::uint16_t Metadata::ydim() const
{
    return m_ydim;
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

    ControllerVersion = 0;
    LogicOutput = 0;
    AmpHiCapLowNoise = 0;
    xDimDet = 0;
    mode = 0;
    exp_sec = 0.0;
    VChipXdim = 0;
    VChipYdim = 0;
    yDimDet = 0;
    date = "ddmmmyyyy\0";
    VirtualChipFlag = 0;
    noscan = 0;
    DetTemperature = 0.0;
    DetType = 0;
    m_xdim = 0;
    stdiode = 0;
    DelayTime = 0.0;
    ShutterControl = 0;
    AbsorbLive = 0;
    AbsorbMode = 0;
    CanDoVirtualChipFlag = 0;
    ThresholdMinLive = 0;
    ThresholdMinVal = 0.0;
    ThresholdMaxLive = 0;
    ThresholdMaxVal = 0.0;
    SpecAutoSpectroMode = 0;
    SpecCenterWlNm = 0.0;
    SpecGlueFlag = 0;
    SpecGlueStartWlNm = 0.0;
    SpecGlueEndWlNm = 0.0;
    SpecGlueMinOvrlpNm = 0.0;
    m_datatype = 0;
    m_ydim = 0;
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

    out << std::setw( MAXWIDTH ) << "ControllerVersion" << '\t' << metadata.ControllerVersion << '\n';
    out << std::setw( MAXWIDTH ) << "LogicOutput" << '\t' << metadata.LogicOutput << '\n';
    out << std::setw( MAXWIDTH ) << "AmpHiCapLowNoise" << '\t' << metadata.AmpHiCapLowNoise << '\n';
    out << std::setw( MAXWIDTH ) << "xDimDet" << '\t' << metadata.xDimDet << '\n';
    out << std::setw( MAXWIDTH ) << "mode" << '\t' << metadata.mode << '\n';
    out << std::setw( MAXWIDTH ) << "exp_sec" << '\t' << metadata.exp_sec << '\n';
    out << std::setw( MAXWIDTH ) << "VChipXdim" << '\t' << metadata.VChipXdim << '\n';
    out << std::setw( MAXWIDTH ) << "VChipYdim" << '\t' << metadata.VChipYdim << '\n';
    out << std::setw( MAXWIDTH ) << "yDimDet" << '\t' << metadata.yDimDet << '\n';
    out << std::setw( MAXWIDTH ) << "date" << '\t' << metadata.date << '\n';
    out << std::setw( MAXWIDTH ) << "VirtualChipFlag" << '\t' << metadata.VirtualChipFlag << '\n';
    out << std::setw( MAXWIDTH ) << "noscan" << '\t' << metadata.noscan << '\n';
    out << std::setw( MAXWIDTH ) << "DetTemperature" << '\t' << metadata.DetTemperature << '\n';
    out << std::setw( MAXWIDTH ) << "DetType" << '\t' << metadata.DetType << '\n';
    out << std::setw( MAXWIDTH ) << "xdim" << '\t' << metadata.xdim() << '\n';
    out << std::setw( MAXWIDTH ) << "stdiode" << '\t' << metadata.stdiode << '\n';
    out << std::setw( MAXWIDTH ) << "DelayTime" << '\t' << metadata.DelayTime << '\n';
    out << std::setw( MAXWIDTH ) << "ShutterControl" << '\t' << metadata.ShutterControl << '\n';
    out << std::setw( MAXWIDTH ) << "AbsorbLive" << '\t' << metadata.AbsorbLive << '\n';
    out << std::setw( MAXWIDTH ) << "AbsorbMode" << '\t' << metadata.AbsorbMode << '\n';
    out << std::setw( MAXWIDTH ) << "CanDoVirtualChipFlag" << '\t' << metadata.CanDoVirtualChipFlag << '\n';
    out << std::setw( MAXWIDTH ) << "ThresholdMinLive" << '\t' << metadata.ThresholdMinLive << '\n';
    out << std::setw( MAXWIDTH ) << "ThresholdMinVal" << '\t' << metadata.ThresholdMinVal << '\n';
    out << std::setw( MAXWIDTH ) << "ThresholdMaxLive" << '\t' << metadata.ThresholdMaxLive << '\n';
    out << std::setw( MAXWIDTH ) << "ThresholdMaxVal" << '\t' << metadata.ThresholdMaxVal << '\n';
    out << std::setw( MAXWIDTH ) << "SpecAutoSpectroMode" << '\t' << metadata.SpecAutoSpectroMode << '\n';
    out << std::setw( MAXWIDTH ) << "SpecCenterWlNm" << '\t' << metadata.SpecCenterWlNm << '\n';
    out << std::setw( MAXWIDTH ) << "SpecGlueFlag" << '\t' << metadata.SpecGlueFlag << '\n';
    out << std::setw( MAXWIDTH ) << "SpecGlueStartWlNm" << '\t' << metadata.SpecGlueStartWlNm << '\n';
    out << std::setw( MAXWIDTH ) << "SpecGlueEndWlNm" << '\t' << metadata.SpecGlueEndWlNm << '\n';
    out << std::setw( MAXWIDTH ) << "SpecGlueMinOvrlpNm" << '\t' << metadata.SpecGlueMinOvrlpNm << '\n';
    out << std::setw( MAXWIDTH ) << "datatype" << '\t' << metadata.datatype() << '\n';
    out << std::setw( MAXWIDTH ) << "ydim" << '\t' << metadata.ydim() << '\n';
    out << std::setw( MAXWIDTH ) << "NumFrames" << '\t' << metadata.NumFrames() << '\n';

    return out;
}

