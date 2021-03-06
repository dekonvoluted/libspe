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

#ifndef SPE_METADATA_H
#define SPE_METADATA_H

#include <fstream>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#include "data.h"
#include "roiData.h"
#include "calibrationData.h"

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

    //! \brief Spectrograph Grating Grooves
    float SpecGrooves = 0.0;

    //! \brief number of source comp. diodes
    std::int16_t srccmp = 0;

    /*! \brief The number of rows in the image
     *
     * This is an important value and any changes made to it can break things.
     * Hence, it is being exposed through a read-only interface.
     */
    std::uint16_t ydim() const;

    //! \brief 0=scrambled, 1=unscrambled
    std::int16_t scramble = 0;

    //! \brief T/F Continuous Cleans Timing Option
    std::int16_t ContinuousCleansFlag = 0;

    //! \brief T/F External Trigger Timing Option
    std::int16_t ExternalTriggerFlag = 0;

    //! \brief Number of scans (Early WinX)
    std::int32_t lnoscan = 0;

    //! \brief Number of Accumulations
    std::int32_t lavgexp = 0;

    //! \brief Experiment readout time
    float ReadoutTime = 0.0;

    //! \brief T/F Triggered Timing Option
    std::int16_t TriggeredModeFlag = 0;

    //! \brief Version of SW creating this file
    std::string sw_version = std::string( std::string( 15, ' ' ) + '\0' );

    /*! \brief The type of controller
     *
     * 1 = new120 (Type II)
     * 2 = old120 (Type I)
     * 3 = ST130
     * 4 = ST121
     * 5 = ST138
     * 6 = DC131 (PentaMax)
     * 7 = ST133 (MicroMax/SpectroMax)
     * 8 = ST135 (GPIB)
     * 9 = VICCD
     * 10 = ST116 (GPIB)
     * 11 = OMA3 (GPIB)
     * 12 = OMA4
     */
    std::int16_t type = 0;

    //! \brief 1 if flat field was applied
    std::int16_t flatFieldApplied = 0;

    //! \brief Kinetics Trigger Mode
    std::int16_t kin_trig_mode = 0;

    //! \brief Data label
    std::string dlabel = std::string( std::string( 15, ' ' ) + '\0' );

    //! \brief Name of Pulser File with Pulse Widths/Delays (for Z-Slice)
    std::string PulseFileName = std::string( std::string( 119, ' ' ) + '\0' );

    //! \brief Name of Absorbance File (if File Mode)
    std::string AbsorbFileName = std::string( std::string( 119, ' ' )  + '\0' );

    //! \brief Number of Times experiment repeated
    std::int32_t NumExpRepeats = 0;

    //! \brief Number of Times experiment accumulated
    std::int32_t NumExpAccums = 0;

    //! \brief Set to 1 if this file contains YT data
    std::int16_t YT_Flag = 0;

    //! \brief Vert Clock Speed in micro-sec
    float clkspd_us = 0.0;

    //! \brief set to 1 if accum done by Hardware
    std::int16_t HWaccumFlag = 0;

    //! \brief set to 1 if store sync used
    std::int16_t StoreSync = 0;

    //! \brief set to 1 if blemish removal applied
    std::int16_t BlemishApplied = 0;

    //! \brief set to 1 if cosmic ray removal applied
    std::int16_t CosmicApplied = 0;

    //! \brief if cosmic ray applied, this is type
    std::int16_t CosmicType = 0;

    //! \brief Threshold of cosmic ray removal
    float CosmicThreshold = 0.0;

    /*! \brief The number of frames present in the SPE file
     *
     * This is an important value and any changes made to it can break things.
     * Hence, it is being exposed through a read-only interface.
     */
    std::int32_t NumFrames() const;

    //! \brief max intensity of data (future)
    float MaxIntensity = 0.0;

    //! \brief min intensity of data (future)
    float MinIntensity = 0.0;

    //! \brief y axis label
    std::string ylabel = std::string( std::string( 15, ' ' ) + '\0' );

    //| \brief shutter type
    std::uint16_t ShutterType = 0;

    //! \brief shutter compensation time
    float shutterComp = 0.0;

    //! \brief readout mode, full, kinetics, etc.
    std::uint16_t readoutMode = 0;

    //! \brief window size for kinetics only
    std::uint16_t WindowSize = 0;

    //! \brief clock speed for kinetics & frame transfer
    std::uint16_t clkspd = 0;

    //! \brief computer interface (isa-taxi, pci, eisa, etc.)
    std::uint16_t interface_type = 0;

    //! \brief May be more than the 10 allowed in this header (if 0, assume 1)
    std::int16_t NumROIsInExperiment = 0;

    //! \brief if multiple controller system will have controller number data came from. This is a future item.
    std::uint16_t controllerNum = 0;

    //! \brief Which software package created this file
    std::uint16_t SWmade = 0;

    //! \brief number of ROIs used. if 0 assume 1.
    std::int16_t NumROI = 0;

    //! \brief ROI info blocks
    std::vector<ROIData> ROIinfoblk;

    //! \brief Flat field file name
    std::string FlatField = std::string( std::string( 119, ' ' ) + '\0' );

    //! \brief background sub. file name
    std::string background = std::string( std::string( 119, ' ' ) + '\0' );

    //! \brief blemish file name
    std::string blemish = std::string( std::string( 119, ' ' ) + '\0' );

    //! \brief version of this file header
    float file_header_ver = 0.0;

    //! \brief Reserved for YT information
    std::string YT_Info = std::string( std::string( 999, ' ' ) + '\0' );

    //! \brief == 0x01234567L if file created by WinX
    std::int32_t WinView_id = 0;

    //! \brief x axis calibration
    CalibrationData xcalibration;

    //! \brief y axis calibration
    CalibrationData ycalibration;

    //! \brief special intensity scaling string
    std::string Istring = std::string( std::string( 39, ' ' ) + '\0' );

    //! \brief spectrometer type (acton, spex, etc.)
    std::uint8_t SpecType = 0;

    //! \brief spectrometer model (type dependent)
    std::uint8_t SpecModel = 0;

    //! \brief pulser burst mode on/off
    std::uint8_t PulseBurstUsed = 0;

    //! \brief pulser triggers per burst
    std::int32_t PulseBurstCount = 0;

    //! \brief pulser burst period (in usec)
    double PulseBurstPeriod = 0.0;

    //! \brief pulser bracket pulsing on/off
    std::uint8_t PulseBracketUsed = 0;

    //! \brief pulser bracket pulsing type
    std::uint8_t PulseBracketType = 0;

    /*!
     * \brief pulser fast exponential time constant (in usec)
     *
     * Note that the specification states that this is the "pulser slow exponential time constant (in usec)", which is incorrect.
     */
    double PulseTimeConstFast = 0.0;

    //! \brief pulser fast exponential amplitude constant
    double PulseAmplitudeFast = 0.0;

    //! \brief pulser slow exponential time constant (in usec)
    double PulseTimeConstSlow = 0.0;

    //! \brief pulser slow exponential amplitude constant
    double PulseAmplitudeSlow = 0.0;

    //! \brief analog gain
    std::int16_t AnalogGain = 0;

    //! \brief avalanche gain was used
    std::int16_t AvGainUsed = 0;

    //! \brief avalanche gain value
    std::int16_t AvGain = 0;

    //! \brief Always the last value in the header
    std::int16_t lastvalue = 0;

    private:
    std::uint16_t m_xdim = 0;
    std::int16_t m_datatype = 0;
    std::uint16_t m_ydim = 0;
    std::int32_t m_NumFrames = 0;

    const std::size_t DATEMAX = 10; // String length of file creation data string as ddmmmyyyy\0
    const std::size_t TIMEMAX = 7; // Max time store as hhmmss\0
    const std::size_t COMMENTMAX = 80; // User comment string max length (5 comments)
    const std::size_t LABELMAX = 16; // Label string max length
    const std::size_t FILEVERMAX = 16; // File version string max length
    const std::size_t HDRNAMEMAX = 120; // Max char str length for file name
    const std::size_t ROIMAX = 10; // Max size of roi array of structures

    virtual void reset();
};
}

/*! \brief Output all available metadata
 *
 * This method prints out all available metadata fields to an output stream.
 */
std::ostream& operator<<( std::ostream&, const SPE::Metadata& );

#endif

