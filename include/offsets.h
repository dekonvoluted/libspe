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
const std::size_t OFFSET_DATATYPE               = 0x006C;   // experiment datatype
                                                            // 0 = float (4 bytes)
                                                            // 1 = long (4 bytes)
                                                            // 2 = short (2 bytes)
                                                            // 3 = unsigned short (2 bytes)
const std::size_t OFFSET_YDIM                   = 0x0290;   // y dimension of raw data
const std::size_t OFFSET_NUMFRAMES              = 0x05A6;   // number of frames in file
const std::size_t OFFSET_DATA                   = 0x1004;   // Start of data

#endif

