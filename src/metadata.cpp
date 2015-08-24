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
    retrieve( date[ 0 ], OFFSET_DATE, DATEMAX );
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
    retrieve( SpecGlueFinalResNm, OFFSET_SPECGLUEFINALRESNM );
    retrieve( PulserType, OFFSET_PULSERTYPE );
    retrieve( CustomChipFlag, OFFSET_CUSTOMCHIPFLAG );
    retrieve( XPrePixels, OFFSET_XPREPIXELS );
    retrieve( XPostPixels, OFFSET_XPOSTPIXELS );
    retrieve( YPrePixels, OFFSET_YPREPIXELS );
    retrieve( YPostPixels, OFFSET_YPOSTPIXELS );
    retrieve( asynen, OFFSET_ASYNEN );
    retrieve( m_datatype, OFFSET_DATATYPE );
    retrieve( PulserMode, OFFSET_PULSERMODE );
    retrieve( PulserOnChipAccums, OFFSET_PULSERONCHIPACCUMS );
    retrieve( PulserRepeatExp, OFFSET_PULSERREPEATEXP );
    retrieve( PulseRepWidth, OFFSET_PULSEREPWIDTH );
    retrieve( PulseRepDelay, OFFSET_PULSEREPDELAY );
    retrieve( PulseSeqStartWidth, OFFSET_PULSESEQSTARTWIDTH );
    retrieve( PulseSeqEndWidth, OFFSET_PULSESEQENDWIDTH );
    retrieve( PulseSeqStartDelay, OFFSET_PULSESEQSTARTDELAY );
    retrieve( PulseSeqEndDelay, OFFSET_PULSESEQENDDELAY );
    retrieve( PulseSeqIncMode, OFFSET_PULSESEQINCMODE );
    retrieve( PImaxUsed, OFFSET_PIMAXUSED );
    retrieve( PImaxMode, OFFSET_PIMAXMODE );
    retrieve( PImaxGain, OFFSET_PIMAXGAIN );
    retrieve( BackGrndApplied, OFFSET_BACKGRNDAPPLIED );
    retrieve( PImax2nsBrdUsed, OFFSET_PIMAX2NSBRDUSED );
    retrieve( minblk, OFFSET_MINBLK );
    retrieve( numminblk, OFFSET_NUMMINBLK );
    retrieve( SpecMirrorLocation[ 0 ], OFFSET_SPECMIRRORLOCATION, 4 );
    retrieve( SpecSlitLocation[ 0 ], OFFSET_SPECSLITLOCATION, 8 );
    retrieve( CustomTimingFlag, OFFSET_CUSTOMTIMINGFLAG );
    retrieve( ExperimentTimeLocal[ 0 ], OFFSET_EXPERIMENTTIMELOCAL, TIMEMAX );
    retrieve( ExperimentTimeUTC[ 0 ], OFFSET_EXPERIMENTTIMEUTC, TIMEMAX );
    retrieve( ExposUnits, OFFSET_EXPOSUNITS );
    retrieve( ADCoffset, OFFSET_ADCOFFSET );
    retrieve( ADCrate, OFFSET_ADCRATE );
    retrieve( ADCtype, OFFSET_ADCTYPE );
    retrieve( ADCresolution, OFFSET_ADCRESOLUTION );
    retrieve( ADCbitAdjust, OFFSET_ADCBITADJUST );
    retrieve( gain, OFFSET_GAIN );
    retrieve( Comments[ 0 ][ 0 ], OFFSET_COMMENTS, COMMENTMAX );
    retrieve( Comments[ 1 ][ 0 ], OFFSET_COMMENTS + COMMENTMAX, COMMENTMAX );
    retrieve( Comments[ 2 ][ 0 ], OFFSET_COMMENTS + ( 2 * COMMENTMAX ), COMMENTMAX );
    retrieve( Comments[ 3 ][ 0 ], OFFSET_COMMENTS + ( 3 * COMMENTMAX ), COMMENTMAX );
    retrieve( Comments[ 4 ][ 0 ], OFFSET_COMMENTS + ( 4 * COMMENTMAX ), COMMENTMAX );
    retrieve( geometric, OFFSET_GEOMETRIC );
    retrieve( xlabel[ 0 ], OFFSET_XLABEL, LABELMAX );
    retrieve( cleans, OFFSET_CLEANS );
    retrieve( NumSkpPerCln, OFFSET_NUMSKPPERCLN );
    retrieve( SpecMirrorPos[ 0 ], OFFSET_SPECMIRRORPOS, 4 );
    retrieve( SpecSlitPos[ 0 ], OFFSET_SPECSLITPOS, 16 );
    retrieve( AutoCleansActive, OFFSET_AUTOCLEANSACTIVE );
    retrieve( UseContCleansInst, OFFSET_USECONTCLEANSINST );
    retrieve( AbsorbStripNum, OFFSET_ABSORBSTRIPNUM );
    retrieve( SpecSlitPosUnits, OFFSET_SPECSLITPOSUNITS );
    retrieve( SpecGrooves, OFFSET_SPECGROOVES );
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
    SpecGlueFinalResNm = 0.0;
    PulserType = 0;
    CustomChipFlag = 0;
    XPrePixels = 0;
    XPostPixels = 0;
    YPrePixels = 0;
    YPostPixels = 0;
    asynen = 0;
    m_datatype = 0;
    PulserMode = 0;
    PulserOnChipAccums = 0;
    PulserRepeatExp = 0;
    PulseRepWidth = 0.0;
    PulseRepDelay = 0.0;
    PulseSeqStartWidth = 0.0;
    PulseSeqEndWidth = 0.0;
    PulseSeqStartDelay = 0.0;
    PulseSeqEndDelay = 0.0;
    PulseSeqIncMode = 0;
    PImaxUsed = 0;
    PImaxMode = 0;
    PImaxGain = 0;
    BackGrndApplied = 0;
    PImax2nsBrdUsed = 0;
    minblk = 0;
    numminblk = 0;
    SpecMirrorLocation = std::vector<std::int16_t>( 2, 0 );
    SpecSlitLocation = std::vector<std::int16_t>( 4, 0 );
    CustomTimingFlag = 0;
    ExperimentTimeLocal = "hhmmss\0";
    ExperimentTimeUTC = "hhmmss\0";
    ExposUnits = 0;
    ADCoffset = 0;
    ADCrate = 0;
    ADCtype = 0;
    ADCresolution = 0;
    ADCbitAdjust = 0;
    gain = 0;
    Comments = std::vector<std::string>( 5, std::string( std::string( COMMENTMAX - 1, ' ' ) + '\0' ) );
    geometric = 0;
    xlabel = std::string( std::string( LABELMAX - 1, ' ' ) + '\0' );
    cleans = 0;
    NumSkpPerCln = 0;
    SpecMirrorPos = std::vector<std::int16_t>( 2, 0 );
    SpecSlitPos = std::vector<float>( 4, 0.0 );
    AutoCleansActive = 0;
    UseContCleansInst = 0;
    AbsorbStripNum = 0;
    SpecSlitPosUnits = 0;
    SpecGrooves = 0.0;
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
    out << std::setw( MAXWIDTH ) << "SpecGlueFinalResNm" << '\t' << metadata.SpecGlueFinalResNm << '\n';
    out << std::setw( MAXWIDTH ) << "PulserType" << '\t' << metadata.PulserType << '\n';
    out << std::setw( MAXWIDTH ) << "CustomChipFlag" << '\t' << metadata.CustomChipFlag << '\n';
    out << std::setw( MAXWIDTH ) << "XPrePixels" << '\t' << metadata.XPrePixels << '\n';
    out << std::setw( MAXWIDTH ) << "XPostPixels" << '\t' << metadata.XPostPixels << '\n';
    out << std::setw( MAXWIDTH ) << "YPrePixels" << '\t' << metadata.YPrePixels << '\n';
    out << std::setw( MAXWIDTH ) << "YPostPixels" << '\t' << metadata.YPostPixels << '\n';
    out << std::setw( MAXWIDTH ) << "asynen" << '\t' << metadata.asynen << '\n';
    out << std::setw( MAXWIDTH ) << "datatype" << '\t' << metadata.datatype() << '\n';
    out << std::setw( MAXWIDTH ) << "PulserMode" << '\t' << metadata.PulserMode << '\n';
    out << std::setw( MAXWIDTH ) << "PulserOnChipAccums" << '\t' << metadata.PulserOnChipAccums << '\n';
    out << std::setw( MAXWIDTH ) << "PulserRepeatExp" << '\t' << metadata.PulserRepeatExp << '\n';
    out << std::setw( MAXWIDTH ) << "PulseRepWidth" << '\t' << metadata.PulseRepWidth << '\n';
    out << std::setw( MAXWIDTH ) << "PulseRepDelay" << '\t' << metadata.PulseRepDelay << '\n';
    out << std::setw( MAXWIDTH ) << "PulseSeqStartWidth" << '\t' << metadata.PulseSeqStartWidth << '\n';
    out << std::setw( MAXWIDTH ) << "PulseSeqEndWidth" << '\t' << metadata.PulseSeqEndWidth << '\n';
    out << std::setw( MAXWIDTH ) << "PulseSeqStartDelay" << '\t' << metadata.PulseSeqStartDelay << '\n';
    out << std::setw( MAXWIDTH ) << "PulseSeqEndDelay" << '\t' << metadata.PulseSeqEndDelay << '\n';
    out << std::setw( MAXWIDTH ) << "PulseSeqIncMode" << '\t' << metadata.PulseSeqIncMode << '\n';
    out << std::setw( MAXWIDTH ) << "PImaxUsed" << '\t' << metadata.PImaxUsed << '\n';
    out << std::setw( MAXWIDTH ) << "PImaxMode" << '\t' << metadata.PImaxMode << '\n';
    out << std::setw( MAXWIDTH ) << "PImaxGain" << '\t' << metadata.PImaxGain << '\n';
    out << std::setw( MAXWIDTH ) << "BackGrndApplied" << '\t' << metadata.BackGrndApplied << '\n';
    out << std::setw( MAXWIDTH ) << "PImax2nsBrdUsed" << '\t' << metadata.PImax2nsBrdUsed << '\n';
    out << std::setw( MAXWIDTH ) << "minblk" << '\t' << metadata.minblk << '\n';
    out << std::setw( MAXWIDTH ) << "numminblk" << '\t' << metadata.numminblk << '\n';
    out << std::setw( MAXWIDTH ) << "SpecMirrorLocation" << "\t{" << metadata.SpecMirrorLocation.at( 0 ) << ", " << metadata.SpecMirrorLocation.at( 1 ) << "}\n";
    out << std::setw( MAXWIDTH ) << "SpecSlitLocation" << "\t{" << metadata.SpecSlitLocation.at( 0 ) << ", " << metadata.SpecSlitLocation.at( 1 ) << ", " << metadata.SpecSlitLocation.at( 2 ) << ", " << metadata.SpecSlitLocation.at( 3 ) << "}\n";
    out << std::setw( MAXWIDTH ) << "CustomTimingFlag" << '\t' << metadata.CustomTimingFlag << '\n';
    out << std::setw( MAXWIDTH ) << "ExperimentTimeLocal" << '\t' << metadata.ExperimentTimeLocal << '\n';
    out << std::setw( MAXWIDTH ) << "ExperimentTimeUTC" << '\t' << metadata.ExperimentTimeUTC << '\n';
    out << std::setw( MAXWIDTH ) << "ExposUnits" << '\t' << metadata.ExposUnits << '\n';
    out << std::setw( MAXWIDTH ) << "ADCoffset" << '\t' << metadata.ADCoffset << '\n';
    out << std::setw( MAXWIDTH ) << "ADCrate" << '\t' << metadata.ADCrate << '\n';
    out << std::setw( MAXWIDTH ) << "ADCtype" << '\t' << metadata.ADCtype << '\n';
    out << std::setw( MAXWIDTH ) << "ADCresolution" << '\t' << metadata.ADCresolution << '\n';
    out << std::setw( MAXWIDTH ) << "ADCbitAdjust" << '\t' << metadata.ADCbitAdjust << '\n';
    out << std::setw( MAXWIDTH ) << "gain" << '\t' << metadata.gain << '\n';
    out << std::setw( MAXWIDTH ) << "Comments" << "\t{\"" << metadata.Comments.at( 0 ) << "\", \"" << metadata.Comments.at( 1 ) << "\", \"" << metadata.Comments.at( 2 ) << "\", \"" << metadata.Comments.at( 3 ) << "\", \"" << metadata.Comments.at( 4 ) << "\"}\n";
    out << std::setw( MAXWIDTH ) << "geometric" << '\t' << metadata.geometric << '\n';
    out << std::setw( MAXWIDTH ) << "xlabel" << '\t' << metadata.xlabel << '\n';
    out << std::setw( MAXWIDTH ) << "cleans" << '\t' << metadata.cleans << '\n';
    out << std::setw( MAXWIDTH ) << "NumSkpPerCln" << '\t' << metadata.NumSkpPerCln << '\n';
    out << std::setw( MAXWIDTH ) << "SpecMirrorPos" << "\t{" << metadata.SpecMirrorPos.at( 0 ) << ", " << metadata.SpecMirrorPos.at( 1 ) << "}\n";
    out << std::setw( MAXWIDTH ) << "SpecSlitPos" << "\t{" << metadata.SpecSlitPos.at( 0 ) << ", " << metadata.SpecSlitPos.at( 1 ) << ", " << metadata.SpecSlitPos.at( 2 ) << ", " << metadata.SpecSlitPos.at( 3 ) << "}\n";
    out << std::setw( MAXWIDTH ) << "AutoCleansActive" << '\t' << metadata.AutoCleansActive << '\n';
    out << std::setw( MAXWIDTH ) << "UseContCleansInst" << '\t' << metadata.UseContCleansInst << '\n';
    out << std::setw( MAXWIDTH ) << "AbsorbStripNum" << '\t' << metadata.AbsorbStripNum << '\n';
    out << std::setw( MAXWIDTH ) << "SpecSlitPosUnits" << '\t' << metadata.SpecSlitPosUnits << '\n';
    out << std::setw( MAXWIDTH ) << "SpecGrooves" << '\t' << metadata.SpecGrooves << '\n';
    out << std::setw( MAXWIDTH ) << "ydim" << '\t' << metadata.ydim() << '\n';
    out << std::setw( MAXWIDTH ) << "NumFrames" << '\t' << metadata.NumFrames() << '\n';

    return out;
}

