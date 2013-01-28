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

#include <string>
#include <ostream>
#include <fstream>
#include <Eigen/Core>

// Custom data types used in the structure
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;

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
  short ControllerVersion;              // Hardware Version
  short LogicOutput;                    // Definition of Output BNC
  WORD AmpHiCapLowNoise;                // Amp Switching Mode
  WORD xDimDet;                         // Detector x dimension of chip
  short mode;                           // timing mode
  float exp_sec;                        // alternative exposure, in sec
  short VChipXdim;                      // Virtual Chip X dim
  short VChipYdim;                      // Virtual Chip Y dim
  WORD yDimDet;                         // y dimension of CCD or detector
  char date[ DATEMAX ];                 // date
  short VirtualChipFlag;                // On/Off
  char Spare_1[ 2 ];                    //
  short noscan;                         // Old number of scans - should always be -1
  float DetTemperature;                 // Detector Temperature Set
  short DetType;                        // CCD/DiodeArray type
  WORD xdim;                            // actual # of pixels on x axis
  short stdiode;                        // trigger diode
  float DelayTime;                      // Used with Async Mode
  WORD ShutterControl;                  // Normal, Disabled Open, Disabled Closed
  short AbsorbLive;                     // On/Off
  WORD AbsorbMode;                      // Reference Strip or File
  short CanDoVirtualChipFlag;           // T/F Cont/Chip able to do Virtual Chip
  short ThresholdMinLive;               // On/Off
  float ThresholdMinVal;                // Threshold Minimum Value
  short ThresholdMaxLive;               // On/Off
  float ThresholdMaxVal;                // Threshold Maximum Value
  short SpecAutoSpectroMode;            // T/F Spectrograph Used
  float SpecCenterWlNm;                 // Center Wavelength in nm
  short SpecGlueFlag;                   // T/F File is Glued
  float SpecGlueStartWlNm;              // Starting Wavelength in nm
  float SpecGlueEndWlNm;                // Ending Wavelength in nm
  float SpecGlueMinOvrlpNm;             // Minimum Overlap in nm
  float SpecGlueFinalResNm;             // Final Resolution in nm
  short PulserType;                     // 0 = None, 1 = PG200, 2 = PTG, 3 = DG535
  short CustomChipFlag;                 // T/F Custom Chip Used
  short XPrePixels;                     // Pre Pixels in X direction
  short XPostPixels;                    // Post Pixels in X direction
  short YPrePixels;                     // Pre Pixels in Y direction
  short YPostPixels;                    // Post Pixels in Y direction
  short asynen;                         // asynchron enable flag 0 = off
  short datatype;                       // experiment datatype -1 = invalid, 0 = float (4 bytes), 1 = long (4 bytes), 2 = short (2 bytes), 3 = unsigned short (2 bytes)
  short PulserMode;                     // Repetitive/Sequential
  WORD PulserOnChipAccums;              // Num PTG On-Chip Accums
  DWORD PulseRepeatExp;                 // Num Exp Repeats (Pulser SW Accum)
  float PulseRepWidth;                  // Width Value for Repetitive pulse (usec)
  float PulseRepDelay;                  // Width Value for Repetitive pulse (usec)
  float PulseSeqStartWidth;             // Start Width for Sequential pulse (usec)
  float PulseSeqEndWidth;               // End Width for Sequential pulse (usec)
  float PulseSeqStartDelay;             // Start Delay for Sequential pulse (usec)
  float PulseSeqEndDelay;               // End Delay for Sequential pulse (usec)
  short PulseSeqIncMode;                // Increments: 1 = Fixed, 2 = Exponential
  short PImaxUsed;                      // PI-Max type controller flag
  short PImaxMode;                      // PI-Max mode
  short PImaxGain;                      // PI-Max Gain
  short BackGrndApplied;                // 1 if background subtraction done
  short PImax2nsBrdUsed;                // T/F PI-Max 2 ns Board Used
  WORD minblk;                          // min. # of strips per skips
  WORD numminblk;                       // # of min-blocks before geo skps
  short SpecMirrorLocation[ 2 ];        // Spectro Mirror Location, 0 = Not Present
  short SpecSlitLocation[ 4 ];          // Spectro Slit Location, 0 = Not Present
  short CustomTimingFlag;               // T/F Custom Timing Used
  char ExperimentTimeLocal[ TIMEMAX ];  // Experiment Local Time as hhmmss\0
  char ExperimentTimeUTC[ TIMEMAX ];    // Experiment UTC Time as hhmmss\0
  short ExposUnits;                     // User Units for Exposure
  WORD ADCoffset;                       // ADC offset
  WORD ADCrate;                         // ADC rate
  WORD ADCtype;                         // ADC type
  WORD ADCresolution;                   // ADC resolution
  WORD ADCbitAdjust;                    // ADC bit adjust
  char Comments[ 5 ] [ COMMENTMAX ];    // File Comments
  WORD geometric;                       // geometric ops: 0x01 = rotate, 0x02 = reverse, 0x04 = flip
  char xlabel[ LABELMAX ];              // intensity display string
  WORD cleans;                          // cleans
  WORD NumSkpPerCln;                    // number of skips per clean
  short SpecMirrorPos[ 2 ];             // Spectrograph Mirror Positions
  float SpecSlitPos[ 4 ];               // Spectrograph Slit Positions
  short AutoCleansActive;               // T/F
  short UseContCleansInst;              // T/F
  short AbsorbStripNum;                 // Absorbance Strip Number
  short SpecSlitPosUnits;               // Spectrograph Slit Position Units
  float SpecGrooves;                    // Spectrograph Grating Grooves
  short srccmp;                         // number of source comp. diodes
  WORD ydim;                            // y dimension of raw data
  short scramble;                       // 0 = scrambled, 1 = unscrambled
  short ContinuousCleansFlag;           // T/F Continuous Cleans Timing Option
  short ExternalTriggerFlag;            // T/F External Trigger Timing Option
  long lnoscan;                         // Number of scans (Early WinX)
  long lavgexp;                         // Number of Accumulations
  float ReadOutTime;                    // Experiment readout time
  short TriggeredModeFlag;              // T/F Triggered Timing Option
  char Spare_2[ 10 ];                   //
  char sw_version[ FILEVERMAX ];        // Version of SW creating this file 1 = new120 (Type II), 2 = old120 (Type I), 3 = ST130, 4 = ST121, 5 = ST138, 6 = DC131 (PentaMax), 7 = ST133 (MicroMax/SpectroMax), 8 = ST135 (GPIB), 9 = VICCD, 10 = ST116 (GPIB), 11 = OMA3 (GPIB), 12 = OMA4
  short flatFieldApplied;               // 1 if flat field was applied
  char Spare_3[ 16 ];                   //
  short kin_trig_mode;                  // Kinetics Trigger Mode
  char dlabel[ LABELMAX ];              // Data label
  char Spare_4[ 436 ];                  //
  char PulseFileName[ HDRNAMEMAX ];     // Name of Pulser File with Pulse Widths/Delays (for Z-Slice)
  char AbsorbFileName[ HDRNAMEMAX ];    // Name of Absorbance File (if File Mode)
  DWORD NumExpRepeats;                  // Number of Times experiment repeated
  DWORD NumExpAccums;                   // Number of Times experiment accumulated
  short YT_Flag;                        // Set to 1 if this file contains YT data
  float clkspd_us;                      // Vert Clock Speed in usec
  short HWaccumFlag;                    // set to 1 if accum done by Hardware
  short StoreSync;                      // set to 1 if store sync used
  short BlemishApplied;                 // set to 1 if blemish removal applied
  short CosmicApplied;                  // set to 1 if cosmic ray removal applied
  short CosmicType;                     // if cosmic ray applied, this is type
  float CosmicThreshold;                // Threshold of cosmic ray removal
  long NumFrames;                       // number of frames in file
  float MaxIntensity;                   // max intensity of data (future)
  float MinIntensity;                   // min intensity of data (future)
  char ylabel[ LABELMAX ];              // y axis label
  WORD ShutterType;                     // shutter type
  float shutterComp;                    // shutter compensation time
  WORD readoutMode;                     // readout mode, full, kinetics, etc
  WORD WindowSize;                      // window size for kinetics only
  WORD clkspd;                          // clock speed for kinetics & frame transfer
  WORD interface_type;                  // computer interface (isa-taxi, pci, eisa, etc)
  short NumROIsInExperiment;            // May be more than the 10 allowed in this header (if 0, assume 1)
  char Spare_5[ 16 ];                   //
  WORD controllerNum;                   // if multiple controller system will have controller data came from, this is a future item
  WORD SWmade;                          // Which software package created this file
  short NumROI;                         // number of ROIs used, if 0 assume 1
  struct ROI
  {
    WORD startx;                        // left x start value
    WORD endx;                          // right x value
    WORD groupx;                        // amount x is binned/grouped in hw
    WORD starty;                        // top y start value
    WORD endy;                          // bottom y value
    WORD groupy;                        // amount y is binned/grouped in hw
  } ROIinfoblk[ ROIMAX ];               // ROI info blocks
  char FlatField[ HDRNAMEMAX ];         // Flat field file name
  char background[ HDRNAMEMAX ];        // background sub file name
  char blemish[ HDRNAMEMAX ];           // blemish file name
  float file_header_ver;                // version of this file header
  char YT_info[ 1000 ];                 // Reserved for YT information
  long WinView_id;                      // 0x01234567L if file created by WinX
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
    BYTE new_calib_flag;                // If set to 200, valid label below
    char calib_label[ 81 ];             // Calibration label (null term'd)
    char expansion[ 87 ];               // Calibration Expansion area
  } xcalibration, ycalibration;         // x and y axis calibration
  char Istring[ 40 ];                   // special intensity scaling string
  char Spare_6[ 25 ];                   //
  BYTE SpecType;                        // spectrometer type (acton, spex, etc)
  BYTE SpecModel;                       // spectrometer model (type dependent)
  BYTE PulseBurstUsed;                  // pulser burst mode on/off
  DWORD PulseBurstCount;                // pulser triggers per burst
  double PulseBurstPeriod;              // pulser burst period (in usec)
  BYTE PulseBracketUsed;                // pulser bracket pulsing on/off
  BYTE PulseBracketType;                // pulser bracket pulsing type
  double PulseTimeConstFast;            // pulser fast exponential time constant (in usec)
  double PulseAmplitudeFast;            // pulser fast exponential amplitude constant
  double PulseTimeConstSlow;            // pulser slow exponential time constant (in usec)
  double PulseAmplitudeSlow;            // pulser slow exponential amplitude constant
  short AnalogGain;                     // analog gain
  short AvGainUsed;                     // avalanche gain was used
  short AvGain;                         // avalanche gain value
  short lastvalue;                      // Always the last value in the header

  std::ifstream infile;                 // Path to the SPE file, empty = file is invalid

  template<class T> void retrieve( T& value, const unsigned short BYTE_OFFSET )
  {
    if( infile.good() ) {
      infile.seekg( BYTE_OFFSET );
      infile.read( reinterpret_cast<char*>( &value ), sizeof( value ) );
    }
  }

public:
  speFile( std::string );
  ~speFile();

  bool setfilePath( const std::string );                            // Returns true if file was found and valid

  void printInfo() const;                                           // Outputs basic information from file header
  void printMetadata() const;                                       // Outputs detailed information from file header (verbose!)
  friend std::ostream& operator<<( std::ostream&, const speFile& ); // Print file contents to screen (gnuplot-friendly)
  Eigen::MatrixXf getFrame( unsigned ) const;                       // Gets one frame from image
  Eigen::MatrixXf getAverage() const;                               // Gets average of all frames from image
};

#endif

