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

#ifndef SPE_OFFSETS_H
#define SPE_OFFSETS_H

#include <cstddef>

// Offsets and description from SPE 2.5 specification

const std::size_t OFFSET_CONTROLLERVERSION      = 0x0000;   // Hardware Version
const std::size_t OFFSET_LOGICOUTPUT            = 0x0002;   // Definition of Output BNC
const std::size_t OFFSET_AMPHICAPLOWNOISE       = 0x0004;   // Amp Switching Mode
const std::size_t OFFSET_XDIMDET                = 0x0006;   // Detector x dimension of chip
const std::size_t OFFSET_MODE                   = 0x0008;   // timing mode
const std::size_t OFFSET_EXP_SEC                = 0x000A;   // alternative exposure, in sec
const std::size_t OFFSET_VCHIPXDIM              = 0x000E;   // Virtual Chip X dim
const std::size_t OFFSET_VCHIPYDIM              = 0x0010;   // Virtual Chip Y dim
const std::size_t OFFSET_YDIMDET                = 0x0012;   // y dimension of CCD or detector
const std::size_t OFFSET_DATE                   = 0x0014;   // date
const std::size_t OFFSET_VIRTUALCHIPFLAG        = 0x001E;   // On/Off
const std::size_t OFFSET_SPARE_1                = 0x0020;   //
const std::size_t OFFSET_NOSCAN                 = 0x0022;   // Old number of scans - should always be -1
const std::size_t OFFSET_DETTEMPERATURE         = 0x0024;   // Detector Temperature Set
const std::size_t OFFSET_DETTYPE                = 0x0028;   // CCD/DiodeArray type
const std::size_t OFFSET_XDIM                   = 0x002A;   // actual # of pixels on x axis
const std::size_t OFFSET_STDIODE                = 0x002C;   // trigger diode
const std::size_t OFFSET_DELAYTIME              = 0x002E;   // Used with Async Mode
const std::size_t OFFSET_SHUTTERCONTROL         = 0x0032;   // Normal, Disabled Open, Disabled Closed
const std::size_t OFFSET_ABSORBLIVE             = 0x0034;   // On/Off
const std::size_t OFFSET_ABSORBMODE             = 0x0036;   // Reference Strip or File
const std::size_t OFFSET_CANDOVIRTUALCHIPFLAG   = 0x0038;   // T/F Cont/Chip able to do Virtual Chip
const std::size_t OFFSET_THRESHOLDMINLIVE       = 0x003A;   // On/Off
const std::size_t OFFSET_THRESHOLDMINVAL        = 0x003C;   // Threshold Minimum Value
const std::size_t OFFSET_THRESHOLDMAXLIVE       = 0x0040;   // On/Off
const std::size_t OFFSET_THRESHOLDMAXVAL        = 0x0042;   // Threshold Maximum Value
const std::size_t OFFSET_SPECAUTOSPECTROMODE    = 0x0046;   // T/F Spectrograph Used
const std::size_t OFFSET_SPECCENTERWLNM         = 0x0048;   // Center Wavelength in Nm
const std::size_t OFFSET_SPECGLUEFLAG           = 0x004C;   // T/F File is Glued
const std::size_t OFFSET_SPECGLUESTARTWLNM      = 0x004E;   // Starting Wavelength in Nm
const std::size_t OFFSET_SPECGLUEENDWLNM        = 0x0052;   // Ending Wavelength in Nm
const std::size_t OFFSET_SPECGLUEMINOVRLPNM     = 0x0056;   // Minimum OVerlap in Nm
const std::size_t OFFSET_SPECGLUEFINALRESNM     = 0x005A;   // Final Resolution in Nm
const std::size_t OFFSET_PULSERTYPE             = 0x005E;   // 0=None, PG200=1, PTG=2, DG535=3
const std::size_t OFFSET_CUSTOMCHIPFLAG         = 0x0060;   // T/F Custom Chip Used
const std::size_t OFFSET_XPREPIXELS             = 0x0062;   // Pre Pixels in X direction
const std::size_t OFFSET_XPOSTPIXELS            = 0x0064;   // Post Pixels in X direction
const std::size_t OFFSET_YPREPIXELS             = 0x0066;   // Pre Pixels in Y direction
const std::size_t OFFSET_YPOSTPIXELS            = 0x0068;   // Post Pixels in Y direction
const std::size_t OFFSET_ASYNEN                 = 0x006A;   // asynchron enable flag 0 = off
const std::size_t OFFSET_DATATYPE               = 0x006C;   // experiment datatype
                                                            // 0 = float (4 bytes)
                                                            // 1 = long (4 bytes)
                                                            // 2 = short (2 bytes)
                                                            // 3 = unsigned short (2 bytes)
const std::size_t OFFSET_PULSERMODE             = 0x006E;   // Repetitive/Sequential
const std::size_t OFFSET_PULSERONCHIPACCUMS     = 0x0070;   // Num PTG On-Chip Accums
const std::size_t OFFSET_PULSERREPEATEXP        = 0x0072;   // Num Exp Repeats (Pulser SW Accum)
const std::size_t OFFSET_PULSEREPWIDTH          = 0x0076;   // Width Value for Repetitive pulse (usec)
const std::size_t OFFSET_PULSEREPDELAY          = 0x007A;   // Delay Value for Repetitive pulse (usec)
const std::size_t OFFSET_PULSESEQSTARTWIDTH     = 0x007E;   // Start Width for Sequential pulse (usec)
const std::size_t OFFSET_PULSESEQENDWIDTH       = 0x0082;   // End Width for Sequential pulse (usec)
const std::size_t OFFSET_PULSESEQSTARTDELAY     = 0x0086;   // Start Delay for Sequential pulse (usec)
const std::size_t OFFSET_PULSESEQENDDELAY       = 0x008A;   // End Delay for Sequential pulse (usec)
const std::size_t OFFSET_PULSESEQINCMODE        = 0x008E;   // Increments: 1=Fixed, 2=Exponential
const std::size_t OFFSET_PIMAXUSED              = 0x0090;   // PI-Max type Controller flag
const std::size_t OFFSET_PIMAXMODE              = 0x0092;   // PI-Max mode
const std::size_t OFFSET_PIMAXGAIN              = 0x0094;   // PI-Max Gain
const std::size_t OFFSET_BACKGRNDAPPLIED        = 0x0096;   // 1 if background subtraction done
const std::size_t OFFSET_PIMAX2NSBRDUSED        = 0x0098;   // T/F PI-Max 2ns Board Used
const std::size_t OFFSET_MINBLK                 = 0x009A;   // min. # of strips per skips
const std::size_t OFFSET_NUMMINBLK              = 0x009C;   // # of min-blocks before geo skps
const std::size_t OFFSET_SPECMIRRORLOCATION     = 0x009E;   // Spectro Mirror Location, 0=Not Present
const std::size_t OFFSET_SPECSLITLOCATION       = 0x00A2;   // Spectro Slit Location, 0=Not Present
const std::size_t OFFSET_CUSTOMTIMINGFLAG       = 0x00AA;   // T/F Custom Timing Used
const std::size_t OFFSET_EXPERIMENTTIMELOCAL    = 0x00AC;   // Experiment Local Time as hhmmss\0
const std::size_t OFFSET_EXPERIMENTTIMEUTC      = 0x00B3;   // Experiment UTC Time as hhmmss\0
const std::size_t OFFSET_EXPOSUNITS             = 0x00BA;   // User Units for Exposure
const std::size_t OFFSET_ADCOFFSET              = 0x00BC;   // ADC offset
const std::size_t OFFSET_ADCRATE                = 0x00BE;   // ADC rate
const std::size_t OFFSET_ADCTYPE                = 0x00C0;   // ADC type
const std::size_t OFFSET_ADCRESOLUTION          = 0x00C2;   // ADC resolution
const std::size_t OFFSET_ADCBITADJUST           = 0x00C4;   // ADC bit adjust
const std::size_t OFFSET_GAIN                   = 0x00C6;   // gain
const std::size_t OFFSET_COMMENTS               = 0x00C8;   // File Comments
const std::size_t OFFSET_GEOMETRIC              = 0x0258;   // geometric ops: rotate 0x01, reverse 0x02, flip 0x04
const std::size_t OFFSET_XLABEL                 = 0x025A;   // intensity display string
const std::size_t OFFSET_CLEANS                 = 0x026A;   // cleans
const std::size_t OFFSET_NUMSKPPERCLN           = 0x026C;   // number of skips per clean
const std::size_t OFFSET_SPECMIRRORPOS          = 0x026E;   // Spectrograph Mirror Positions
const std::size_t OFFSET_SPECSLITPOS            = 0x0272;   // Spectrograph Slit Positions
const std::size_t OFFSET_AUTOCLEANSACTIVE       = 0x0282;   // T/F
const std::size_t OFFSET_USECONTCLEANSINST      = 0x0284;   // T/F
const std::size_t OFFSET_ABSORBSTRIPNUM         = 0x0286;   // Absorbance Strip Number
const std::size_t OFFSET_SPECSLITPOSUNITS       = 0x0288;   // Spectrograph Slit Position Units
const std::size_t OFFSET_SPECGROOVES            = 0x028A;   // Spectrograph Grating Grooves
const std::size_t OFFSET_SRCCMP                 = 0x028E;   // number of source comp. diodes
const std::size_t OFFSET_YDIM                   = 0x0290;   // y dimension of raw data
const std::size_t OFFSET_SCRAMBLE               = 0x0292;   // 0=scrambled, 1=unscrambled
const std::size_t OFFSET_NUMFRAMES              = 0x05A6;   // number of frames in file
const std::size_t OFFSET_DATA                   = 0x1004;   // Start of data

#endif

