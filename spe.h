// This file is part of libspe, a C++ library to interface with spe files.
// Copyright (c) 2012 Karthik Periagaram <karthik.periagaram@gmail.com>
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

#ifndef SPE_H
#define SPE_H

#include <cstdint>
#include <string>
#include <ostream>
#include <fstream>
#include <Eigen/Core>

// Definition of array sizes
const int HDRNAMEMAX  = 120;  // Max char str length for file name
const int USERINFOMAX = 1000; // User information space
const int COMMENTMAX  = 80;   // User comment string max length (5 comments)
const int LABELMAX    = 16;   // Label string max length
const int FILEVERMAX  = 16;   // File version string max length
const int DATEMAX     = 10;   // String length of file creation date string as ddmmyyyy\0
const int ROIMAX      = 10;   // Max size of roi array of structures
const int TIMEMAX     = 7;    // Max time store as hhmmss\0

class speFile
// Represents an SPE image
// Implements Version 2.5 Header (3/23/04)
{
  // Data structure of the header
  int16_t ControllerVersion;              // Hardware Version
  int16_t LogicOutput;                    // Definition of Output BNC
  uint16_t AmpHiCapLowNoise;                // Amp Switching Mode
  uint16_t xDimDet;                         // Detector x dimension of chip
  int16_t mode;                           // timing mode
  float exp_sec;                        // alternative exposure, in sec
  int16_t VChipXdim;                      // Virtual Chip X dim
  int16_t VChipYdim;                      // Virtual Chip Y dim
  uint16_t yDimDet;                         // y dimension of CCD or detector
  char date[ DATEMAX ];                 // date
  int16_t VirtualChipFlag;                // On/Off
  //char Spare_1[ 2 ];                    //
  int16_t noscan;                         // Old number of scans - should always be -1
  float DetTemperature;                 // Detector Temperature Set
  int16_t DetType;                        // CCD/DiodeArray type
  uint16_t xdim;                            // actual # of pixels on x axis
  int16_t stdiode;                        // trigger diode
  float DelayTime;                      // Used with Async Mode
  uint16_t ShutterControl;                  // Normal, Disabled Open, Disabled Closed
  int16_t AbsorbLive;                     // On/Off
  uint16_t AbsorbMode;                      // Reference Strip or File
  int16_t CanDoVirtualChipFlag;           // T/F Cont/Chip able to do Virtual Chip
  int16_t ThresholdMinLive;               // On/Off
  float ThresholdMinVal;                // Threshold Minimum Value
  int16_t ThresholdMaxLive;               // On/Off
  float ThresholdMaxVal;                // Threshold Maximum Value
  int16_t SpecAutoSpectroMode;            // T/F Spectrograph Used
  float SpecCenterWlNm;                 // Center Wavelength in nm
  int16_t SpecGlueFlag;                   // T/F File is Glued
  float SpecGlueStartWlNm;              // Starting Wavelength in nm
  float SpecGlueEndWlNm;                // Ending Wavelength in nm
  float SpecGlueMinOvrlpNm;             // Minimum Overlap in nm
  float SpecGlueFinalResNm;             // Final Resolution in nm
  int16_t PulserType;                     // 0 = None, 1 = PG200, 2 = PTG, 3 = DG535
  int16_t CustomChipFlag;                 // T/F Custom Chip Used
  int16_t XPrePixels;                     // Pre Pixels in X direction
  int16_t XPostPixels;                    // Post Pixels in X direction
  int16_t YPrePixels;                     // Pre Pixels in Y direction
  int16_t YPostPixels;                    // Post Pixels in Y direction
  int16_t asynen;                         // asynchron enable flag 0 = off
  int16_t datatype;                       // experiment datatype, 0 = float (4 bytes), 1 = int32_t (4 bytes), 2 = int16_t (2 bytes), 3 = uint16_t (2 bytes)
  int16_t PulserMode;                     // Repetitive/Sequential
  uint16_t PulserOnChipAccums;              // Num PTG On-Chip Accums
  uint32_t PulseRepeatExp;                 // Num Exp Repeats (Pulser SW Accum)
  float PulseRepWidth;                  // Width Value for Repetitive pulse (usec)
  float PulseRepDelay;                  // Width Value for Repetitive pulse (usec)
  float PulseSeqStartWidth;             // Start Width for Sequential pulse (usec)
  float PulseSeqEndWidth;               // End Width for Sequential pulse (usec)
  float PulseSeqStartDelay;             // Start Delay for Sequential pulse (usec)
  float PulseSeqEndDelay;               // End Delay for Sequential pulse (usec)
  int16_t PulseSeqIncMode;                // Increments: 1 = Fixed, 2 = Exponential
  int16_t PImaxUsed;                      // PI-Max type controller flag
  int16_t PImaxMode;                      // PI-Max mode
  int16_t PImaxGain;                      // PI-Max Gain
  int16_t BackGrndApplied;                // 1 if background subtraction done
  int16_t PImax2nsBrdUsed;                // T/F PI-Max 2 ns Board Used
  uint16_t minblk;                          // min. # of strips per skips
  uint16_t numminblk;                       // # of min-blocks before geo skps
  int16_t SpecMirrorLocation[ 2 ];        // Spectro Mirror Location, 0 = Not Present
  int16_t SpecSlitLocation[ 4 ];          // Spectro Slit Location, 0 = Not Present
  int16_t CustomTimingFlag;               // T/F Custom Timing Used
  char ExperimentTimeLocal[ TIMEMAX ];  // Experiment Local Time as hhmmss\0
  char ExperimentTimeUTC[ TIMEMAX ];    // Experiment UTC Time as hhmmss\0
  int16_t ExposUnits;                     // User Units for Exposure
  uint16_t ADCoffset;                       // ADC offset
  uint16_t ADCrate;                         // ADC rate
  uint16_t ADCtype;                         // ADC type
  uint16_t ADCresolution;                   // ADC resolution
  uint16_t ADCbitAdjust;                    // ADC bit adjust
  char Comments[ 5 ] [ COMMENTMAX ];    // File Comments
  uint16_t geometric;                       // geometric ops: 0x01 = rotate, 0x02 = reverse, 0x04 = flip
  char xlabel[ LABELMAX ];              // intensity display string
  uint16_t cleans;                          // cleans
  uint16_t NumSkpPerCln;                    // number of skips per clean
  int16_t SpecMirrorPos[ 2 ];             // Spectrograph Mirror Positions
  float SpecSlitPos[ 4 ];               // Spectrograph Slit Positions
  int16_t AutoCleansActive;               // T/F
  int16_t UseContCleansInst;              // T/F
  int16_t AbsorbStripNum;                 // Absorbance Strip Number
  int16_t SpecSlitPosUnits;               // Spectrograph Slit Position Units
  float SpecGrooves;                    // Spectrograph Grating Grooves
  int16_t srccmp;                         // number of source comp. diodes
  uint16_t ydim;                            // y dimension of raw data
  int16_t scramble;                       // 0 = scrambled, 1 = unscrambled
  int16_t ContinuousCleansFlag;           // T/F Continuous Cleans Timing Option
  int16_t ExternalTriggerFlag;            // T/F External Trigger Timing Option
  int32_t lnoscan;                         // Number of scans (Early WinX)
  int32_t lavgexp;                         // Number of Accumulations
  float ReadOutTime;                    // Experiment readout time
  int16_t TriggeredModeFlag;              // T/F Triggered Timing Option
  //char Spare_2[ 10 ];                   //
  char sw_version[ FILEVERMAX ];        // Version of SW creating this file
  int16_t type;                           // 1 = new120 (Type II), 2 = old120 (Type I), 3 = ST130, 4 = ST121, 5 = ST138, 6 = DC131 (PentaMax), 7 = ST133 (MicroMax/SpectroMax), 8 = ST135 (GPIB), 9 = VICCD, 10 = ST116 (GPIB), 11 = OMA3 (GPIB), 12 = OMA4
  int16_t flatFieldApplied;               // 1 if flat field was applied
  //char Spare_3[ 16 ];                   //
  int16_t kin_trig_mode;                  // Kinetics Trigger Mode
  char dlabel[ LABELMAX ];              // Data label
  //char Spare_4[ 436 ];                  //
  char PulseFileName[ HDRNAMEMAX ];     // Name of Pulser File with Pulse Widths/Delays (for Z-Slice)
  char AbsorbFileName[ HDRNAMEMAX ];    // Name of Absorbance File (if File Mode)
  uint32_t NumExpRepeats;                  // Number of Times experiment repeated
  uint32_t NumExpAccums;                   // Number of Times experiment accumulated
  int16_t YT_Flag;                        // Set to 1 if this file contains YT data
  float clkspd_us;                      // Vert Clock Speed in usec
  int16_t HWaccumFlag;                    // set to 1 if accum done by Hardware
  int16_t StoreSync;                      // set to 1 if store sync used
  int16_t BlemishApplied;                 // set to 1 if blemish removal applied
  int16_t CosmicApplied;                  // set to 1 if cosmic ray removal applied
  int16_t CosmicType;                     // if cosmic ray applied, this is type
  float CosmicThreshold;                // Threshold of cosmic ray removal
  int32_t NumFrames;                       // number of frames in file
  float MaxIntensity;                   // max intensity of data (future)
  float MinIntensity;                   // min intensity of data (future)
  char ylabel[ LABELMAX ];              // y axis label
  uint16_t ShutterType;                     // shutter type
  float shutterComp;                    // shutter compensation time
  uint16_t readoutMode;                     // readout mode, full, kinetics, etc
  uint16_t WindowSize;                      // window size for kinetics only
  uint16_t clkspd;                          // clock speed for kinetics & frame transfer
  uint16_t interface_type;                  // computer interface (isa-taxi, pci, eisa, etc)
  int16_t NumROIsInExperiment;            // May be more than the 10 allowed in this header (if 0, assume 1)
  //char Spare_5[ 16 ];                   //
  uint16_t controllerNum;                   // if multiple controller system will have controller data came from, this is a future item
  uint16_t SWmade;                          // Which software package created this file
  int16_t NumROI;                         // number of ROIs used, if 0 assume 1
  struct ROI
  {
    uint16_t startx;                        // left x start value
    uint16_t endx;                          // right x value
    uint16_t groupx;                        // amount x is binned/grouped in hw
    uint16_t starty;                        // top y start value
    uint16_t endy;                          // bottom y value
    uint16_t groupy;                        // amount y is binned/grouped in hw
  } ROIinfoblk[ ROIMAX ];               // ROI info blocks
  char FlatField[ HDRNAMEMAX ];         // Flat field file name
  char background[ HDRNAMEMAX ];        // background sub file name
  char blemish[ HDRNAMEMAX ];           // blemish file name
  float file_header_ver;                // version of this file header
  char YT_info[ 1000 ];                 // Reserved for YT information
  int32_t WinView_id;                      // 0x01234567L if file created by WinX
  struct calibration
  {
    double offset;                      // offset for absolute data scaling
    double factor;                      // factor for absolute data scaling
    char current_unit;                  // selected scaling unit
    char reserved1;                     // reserved
    char string[ 40 ];                  // special string for scaling
    char reserved2[ 40 ];               // reserved
    char calib_valid;                   // flag if calibration is valid
    char input_unit;                    // current inputunits for "calib_value"
    char polynom_unit;                  // linear unit and used in "polynom_coeff"
    char polynom_order;                 // order of calibration polynom
    char calib_count;                   // valid calibration data pairs
    double pixel_position[ 10 ];        // pixel pos of calibration data
    double calib_value[ 10 ];           // calibration value at above pos
    double polynom_coeff[ 6 ];          // polynom coefficients
    double laser_position;              // laser wavenumber for relative WN
    char reserved3;                     // reserved
    unsigned char new_calib_flag;                // If set to 200, valid label below
    char calib_label[ 81 ];             // Calibration label (null term'd)
    char expansion[ 87 ];               // Calibration Expansion area
  } xcalibration, ycalibration;         // x and y axis calibration
  char Istring[ 40 ];                   // special intensity scaling string
  //char Spare_6[ 25 ];                   //
  unsigned char SpecType;                        // spectrometer type (acton, spex, etc)
  unsigned char SpecModel;                       // spectrometer model (type dependent)
  unsigned char PulseBurstUsed;                  // pulser burst mode on/off
  uint32_t PulseBurstCount;                // pulser triggers per burst
  double PulseBurstPeriod;              // pulser burst period (in usec)
  unsigned char PulseBracketUsed;                // pulser bracket pulsing on/off
  unsigned char PulseBracketType;                // pulser bracket pulsing type
  double PulseTimeConstFast;            // pulser fast exponential time constant (in usec)
  double PulseAmplitudeFast;            // pulser fast exponential amplitude constant
  double PulseTimeConstSlow;            // pulser slow exponential time constant (in usec)
  double PulseAmplitudeSlow;            // pulser slow exponential amplitude constant
  int16_t AnalogGain;                     // analog gain
  int16_t AvGainUsed;                     // avalanche gain was used
  int16_t AvGain;                         // avalanche gain value
  int16_t lastvalue;                      // Always the last value in the header

  std::ifstream infile;                 // Path to the SPE file, empty = file is invalid

  template<class T> void retrieve( T& value, const unsigned short BYTE_OFFSET = -0x0001 )
  {
    if( BYTE_OFFSET != -0x0001 ) infile.seekg( BYTE_OFFSET );
    if( infile.good() ) infile.read( reinterpret_cast<char*>( &value ), sizeof( value ) );
  }

public:
  speFile( const std::string& );
  ~speFile();

  bool setFilePath( const std::string& );                            // Returns true if file was found and valid

  void printInfo() const;                                           // Outputs basic information from file header
  void printMetadata() const;                                       // Outputs detailed information from file header (verbose!)
  friend std::ostream& operator<<( std::ostream&, const speFile& ); // Print file contents to screen (gnuplot-friendly)
  Eigen::MatrixXf getFrame( const unsigned& ) const;                       // Gets one frame from image
  Eigen::MatrixXf getAverage() const;                               // Gets average of all frames from image
};

#endif

