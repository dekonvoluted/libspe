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
#include <iostream>
#include <string>
#include <vector>

#include "data.h"

namespace SPE {
/*! \brief Binary data present in an SPE file header
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

    //! \brief Hardware Version
    std::int16_t ControllerVersion = 0;

    //! \brief Definition of Output BNC
    std::int16_t LogicOutput = 0;

    //! \brief Amp Switching Mode
    std::uint16_t AmpHiCapLowNoise = 0;

    //! \brief Detector x dimension of chip
    std::uint16_t xDimDet = 0;

    //! \brief timing mode
    std::int16_t mode = 0;

    //! \brief alternative exposure, in sec
    float exp_sec = 0.0;

    //! \brief Virtual Chip X dim
    std::int16_t VChipXdim = 0;

    //! \brief Virtual Chip Y dim
    std::int16_t VChipYdim = 0;

    //! \brief y dimension of CCD of detector
    std::uint16_t yDimDet = 0;

    //! \brief date
    std::string date = "ddmmmyyyy\0";

    //! \brief On/Off
    std::int16_t VirtualChipFlag = 0;

    //! \brief Old number of scans - should always be -1
    std::int16_t noscan = 0;

    //! \brief Detector Temperature Set
    float DetTemperature = 0.0;

    //! \brief CCD/DiodeArray type
    std::int16_t DetType = 0;

    /*! \brief The number of columns in the image
     *
     * This is an important value and any changes made to it can break things.
     * Hence, it is being exposed through a read-only interface.
     */
    std::uint16_t xdim() const;

    //! \brief trigger diode
    std::int16_t stdiode = 0;

    //! \brief Used with Async Mode
    float DelayTime = 0.0;

    //! \brief Normal, Disabled Open, Disabled Closed
    std::uint16_t ShutterControl = 0;

    //! \brief On/Off
    std::int16_t AbsorbLive = 0;

    //! \brief Reference Strip or File
    std::uint16_t AbsorbMode = 0;

    //! \brief T/F Cont/Chip able to do Virtual Chip
    std::int16_t CanDoVirtualChipFlag = 0;

    //! \brief On/Off
    std::int16_t ThresholdMinLive = 0;

    //! \brief Threshold Minimum Value
    float ThresholdMinVal = 0.0;

    //! \brief On/Off
    std::int16_t ThresholdMaxLive = 0;

    //! \brief Threshold Maximum Value
    float ThresholdMaxVal = 0.0;

    //! \brief T/F Spectrograph Used
    std::int16_t SpecAutoSpectroMode = 0;

    //! \brief Center Wavelength in Nm
    float SpecCenterWlNm = 0.0;

    //! \brief T/F File is Glued
    std::int16_t SpecGlueFlag = 0;

    //! \brief Starting Wavelength in Nm
    float SpecGlueStartWlNm = 0.0;

    /*! \brief Ending Wavelength in Nm
     *
     * Note that the specification states that this is the "Starting Wavelength in Nm", which is incorrect.
     */
    float SpecGlueEndWlNm = 0.0;

    //! \brief Minimum Overlap in Nm
    float SpecGlueMinOvrlpNm = 0.0;

    //! \brief Final Resolution in Nm
    float SpecGlueFinalResNm = 0.0;

    //! \brief 0=None, PG200=1, PTG=2, DG535=3
    std::int16_t PulserType = 0;

    //! \brief T/F Custom Chip Used
    std::int16_t CustomChipFlag = 0;

    //! \brief Pre Pixels in X direction
    std::int16_t XPrePixels = 0;

    //! \brief Post Pixels in X direction
    std::int16_t XPostPixels = 0;

    //! \brief Pre Pixels in Y direction
    std::int16_t YPrePixels = 0;

    //! \brief Post Pixels in Y direction
    std::int16_t YPostPixels = 0;

    //! \brief asynchron enable flag 0 = off
    std::int16_t asynen = 0;

    /*! \brief The datatype of intensity of each pixel in the image
     *
     * This is the internal representation of the intensity of each pixel in the image.
     * The possible values are:
     * - 0 = floating point, 4 bytes per pixel
     * - 1 = long integer, 4 bytes per pixel
     * - 2 = short integer, 2 bytes per pixel
     * - 3 = unsigned short integer, 2 bytes per pixel
     *
     * This is an important value and any changes made to it can break things.
     * Hence, it is being exposed through a read-only interface.
     */
    std::int16_t datatype() const;

    //! \brief Repetitive/Sequential
    std::int16_t PulserMode = 0;

    //! \brief Num PTG On-Chip Accums
    std::uint16_t PulserOnChipAccums = 0;

    //! \brief Num Exp Repeats (Pulser SW Accum)
    std::int32_t PulserRepeatExp = 0;

    //! \brief Width Value for Repetitive pulse (usec)
    float PulseRepWidth = 0.0;

    /*! \brief Delay Value for Repetitive pulse (usec)
     *
     * Note that the specification states that this is the "Width Value for Repetitive pulse (usec)", which is incorrect.
     */
    float PulseRepDelay = 0.0;

    //! \brief Start Width for Sequential pulse (usec)
    float PulseSeqStartWidth = 0.0;

    //! \brief End Width for Sequential pulse (usec)
    float PulseSeqEndWidth = 0.0;

    //! \brief Start Delay for Sequential pulse (usec)
    float PulseSeqStartDelay = 0.0;

    //! \brief End Delay for Sequential pulse (usec)
    float PulseSeqEndDelay = 0.0;

    //! \brief Increments: 1=Fixed, 2=Exponential
    std::int16_t PulseSeqIncMode = 0;

    //! \brief PI-Max type controller flag
    std::int16_t PImaxUsed = 0;

    //! \brief PI-Max mode
    std::int16_t PImaxMode = 0;

    //! \brief PI-Max Gain
    std::int16_t PImaxGain = 0;

    //! \brief 1 if background subtraction done
    std::int16_t BackGrndApplied = 0;

    //! \brief T/F PI-Max 2ns Board Used
    std::int16_t PImax2nsBrdUsed = 0;

    //! \brief min. # of strips per skips
    std::uint16_t minblk = 0;

    //! \brief \# of min-blocks before geo skps
    std::uint16_t numminblk = 0;

    //! \brief Spectro Mirror Location, 0=Not Present
    std::vector<std::int16_t> SpecMirrorLocation = std::vector<std::int16_t>( 2, 0 );

    //! \brief Spectro Slit Location, 0=Not Present
    std::vector<std::int16_t> SpecSlitLocation = std::vector<std::int16_t>( 4, 0 );

    //! \brief T/F Custom Timing Used
    std::int16_t CustomTimingFlag = 0;

    //! \brief Experiment Local Time as hhmmss\0
    std::string ExperimentTimeLocal = "hhmmss\0";

    //! \brief Experiment UTC Time as hhmmss\0
    std::string ExperimentTimeUTC = "hhmmss\0";

    //! \brief User Units for Exposure
    std::int16_t ExposUnits = 0;

    //! \brief ADC offset
    std::uint16_t ADCoffset = 0;

    //! \brief ADC rate
    std::uint16_t ADCrate = 0;

    //! \brief ADC type
    std::uint16_t ADCtype = 0;

    //! \brief ADC resolution
    std::uint16_t ADCresolution = 0;

    //! \brief ADC bit adjust
    std::uint16_t ADCbitAdjust = 0;

    //! \brief gain
    std::uint16_t gain = 0;

    //! \brief File Comments
    std::vector<std::string> Comments = std::vector<std::string>( 5, std::string( std::string( 79, ' ' ) + '\0' ) );

    //! \brief geometric ops: rotate 0x01, reverse 0x02, flip 0x04
    std::uint16_t geometric = 0;

    //! \brief intensity display string
    std::string xlabel = std::string( std::string( 15, ' ' ) + '\0' );

    //! \brief cleans
    std::uint16_t cleans = 0;

    //! \brief number of skips per clean
    std::uint16_t NumSkpPerCln = 0;

    //! \brief Spectrograph Mirror Positions
    std::vector<std::int16_t> SpecMirrorPos = std::vector<std::int16_t>( 2, 0 );

    //! \brief Spectrograph Slit Positions
    std::vector<float> SpecSlitPos = std::vector<float>( 4, 0.0 );

    //! \brief T/F
    std::int16_t AutoCleansActive = 0;

    //! \brief T/F
    std::int16_t UseContCleansInst = 0;

    //! \brief Absorbance Strip Number
    std::int16_t AbsorbStripNum = 0;

    //! \brief Spectrograph Slit Position Units
    std::int16_t SpecSlitPosUnits = 0;

    /*! \brief The number of rows in the image
     *
     * This is an important value and any changes made to it can break things.
     * Hence, it is being exposed through a read-only interface.
     */
    std::uint16_t ydim() const;

    /*! \brief The number of frames present in the SPE file
     *
     * This is an important value and any changes made to it can break things.
     * Hence, it is being exposed through a read-only interface.
     */
    std::int32_t NumFrames() const;

    private:
    std::uint16_t m_xdim = 0;
    std::int16_t m_datatype = 0;
    std::uint16_t m_ydim = 0;
    std::int32_t m_NumFrames = 0;

    const std::size_t DATEMAX = 10; // String length of file creation data string as ddmmmyyyy\0
    const std::size_t TIMEMAX = 7; // Max time store as hhmmss\0
    const std::size_t COMMENTMAX = 80; // User comment string max length (5 comments)
    const std::size_t LABELMAX = 16; // Label string max length

    virtual void reset();
};
}

/*! \brief Output all available metadata
 *
 * This method prints out all available metadata fields to an output stream.
 */
std::ostream& operator<< ( std::ostream&, const SPE::Metadata& );

#endif

