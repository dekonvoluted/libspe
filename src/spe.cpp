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

#include "spe.h"
#include "../spe.h"

// Byte offsets for header elements
const unsigned short OFFSET_CONTROLLERVERSION     = 0x0000;
const unsigned short OFFSET_LOGICOUTPUT           = 0x0002;
const unsigned short OFFSET_AMPHICAPLOWNOISE      = 0x0004;
const unsigned short OFFSET_XDIMDET               = 0x0006;
const unsigned short OFFSET_MODE                  = 0x0008;
const unsigned short OFFSET_EXP_SEC               = 0x000A;
const unsigned short OFFSET_VCHIPXDIM             = 0x000E;
const unsigned short OFFSET_VCHIPYDIM             = 0x0010;
const unsigned short OFFSET_YDIMDET               = 0x0012;
const unsigned short OFFSET_DATE                  = 0x0014;
const unsigned short OFFSET_VIRTUALCHIPFLAG       = 0x001E;
const unsigned short OFFSET_SPARE_1               = 0x0020;
const unsigned short OFFSET_NOSCAN                = 0x0022;
const unsigned short OFFSET_DETTEMPERATURE        = 0x0024;
const unsigned short OFFSET_DETTYPE               = 0x0028;
const unsigned short OFFSET_XDIM                  = 0x002A;
const unsigned short OFFSET_STDIODE               = 0x002C;
const unsigned short OFFSET_DELAYTIME             = 0x002E;
const unsigned short OFFSET_SHUTTERCONTROL        = 0x0032;
const unsigned short OFFSET_ABSORBLIVE            = 0x0034;
const unsigned short OFFSET_ABSORBMODE            = 0x0036;
const unsigned short OFFSET_CANDOVIRTUALCHIPFLAG  = 0x0038;
const unsigned short OFFSET_THRESHOLDMINLIVE      = 0x003A;
const unsigned short OFFSET_THRESHOLDMINVAL       = 0x003C;
const unsigned short OFFSET_THRESHOLDMAXLIVE      = 0x0040;
const unsigned short OFFSET_THRESHOLDMAXVAL       = 0x0042;
const unsigned short OFFSET_SPECAUTOSPECTROMODE   = 0x0046;
const unsigned short OFFSET_SPECCENTERWLNM        = 0x0048;
const unsigned short OFFSET_SPECGLUEFLAG          = 0x004C;
const unsigned short OFFSET_SPECGLUESTARTWLNM     = 0x004E;
const unsigned short OFFSET_SPECGLUEENDWLNM       = 0x0052;
const unsigned short OFFSET_SPECGLUEMINOVRLPNM    = 0x0056;
const unsigned short OFFSET_SPECGLUEFINALRESNM    = 0x005A;
const unsigned short OFFSET_PULSERTYPE            = 0x005E;
const unsigned short OFFSET_CUSTOMCHIPFLAG        = 0x0060;
const unsigned short OFFSET_XPREPIXELS            = 0x0062;
const unsigned short OFFSET_XPOSTPIXELS           = 0x0064;
const unsigned short OFFSET_YPREPIXELS            = 0x0066;
const unsigned short OFFSET_YPOSTPIXELS           = 0x0068;
const unsigned short OFFSET_ASYNEN                = 0x006A;
const unsigned short OFFSET_DATATYPE              = 0x006C;
const unsigned short OFFSET_PULSERMODE            = 0x006E;
const unsigned short OFFSET_PULSERONCHIPACCUMS    = 0x0070;
const unsigned short OFFSET_PULSEREPEATEXP        = 0x0072;
const unsigned short OFFSET_PULSEREPWIDTH         = 0x0076;
const unsigned short OFFSET_PULSEREPDELAY         = 0x007A;
const unsigned short OFFSET_PULSESEQSTARTWIDTH    = 0x007E;
const unsigned short OFFSET_PULSESEQENDWIDTH      = 0x0082;
const unsigned short OFFSET_PULSESEQSTARTDELAY    = 0x0086;
const unsigned short OFFSET_PULSESEQENDDELAY      = 0x008A;
const unsigned short OFFSET_PULSESEQINCMODE       = 0x008E;
const unsigned short OFFSET_PIMAXUSED             = 0x0090;
const unsigned short OFFSET_PIMAXMODE             = 0x0092;
const unsigned short OFFSET_PIMAXGAIN             = 0x0094;
const unsigned short OFFSET_BACKGRNDAPPLIED       = 0x0096;
const unsigned short OFFSET_PIMAX2NSBRDUSED       = 0x0098;
const unsigned short OFFSET_MINBLK                = 0x009A;
const unsigned short OFFSET_NUMMINBLK             = 0x009C;
const unsigned short OFFSET_SPECMIRRORLOCATION    = 0x009E;
const unsigned short OFFSET_SPECSLITLOCATION      = 0x00A2;
const unsigned short OFFSET_CUSTOMTIMINGFLAG      = 0x00AA;
const unsigned short OFFSET_EXPERIMENTTIMELOCAL   = 0x00AC;
const unsigned short OFFSET_EXPERIMENTTIMEUTC     = 0x00B3;
const unsigned short OFFSET_EXPOSUNITS            = 0x00BA;
const unsigned short OFFSET_ADCOFFSET             = 0x00BC;
const unsigned short OFFSET_ADCRATE               = 0x00BE;
const unsigned short OFFSET_ADCTYPE               = 0x00C0;
const unsigned short OFFSET_ADCRESOLUTION         = 0x00C2;
const unsigned short OFFSET_ADCBITADJUST          = 0x00C4;
const unsigned short OFFSET_GAIN                  = 0x00C6;
const unsigned short OFFSET_COMMENTS              = 0x00C8;
const unsigned short OFFSET_GEOMETRIC             = 0x0258;
const unsigned short OFFSET_XLABEL                = 0x025A;
const unsigned short OFFSET_CLEANS                = 0x026A;
const unsigned short OFFSET_NUMSKPPERCLN          = 0x026C;
const unsigned short OFFSET_SPECMIRRORPOS         = 0x026E;
const unsigned short OFFSET_SPECSLITPOS           = 0x0272;
const unsigned short OFFSET_AUTOCLEANSACTIVE      = 0x0282;
const unsigned short OFFSET_USECONTCLEANSINST     = 0x0284;
const unsigned short OFFSET_ABSORBSTRIPNUM        = 0x0286;
const unsigned short OFFSET_SPECSLITPOSUNITS      = 0x0288;
const unsigned short OFFSET_SPECGROOVES           = 0x028A;
const unsigned short OFFSET_SRCCMP                = 0x028E;
const unsigned short OFFSET_YDIM                  = 0x0290;
const unsigned short OFFSET_SCRAMBLE              = 0x0292;
const unsigned short OFFSET_CONTINUOUSCLEANSFLAG  = 0x0294;
const unsigned short OFFSET_EXTERNALTRIGGERFLAG   = 0x0296;
const unsigned short OFFSET_LNOSCAN               = 0x0298;
const unsigned short OFFSET_LAVGEXP               = 0x029C;
const unsigned short OFFSET_READOUTTIME           = 0x02A0;
const unsigned short OFFSET_TRIGGEREDMODEFLAG     = 0x02A4;
const unsigned short OFFSET_SPARE_2               = 0x02A6;
const unsigned short OFFSET_SW_VERSION            = 0x02B0;
const unsigned short OFFSET_TYPE                  = 0x02C0;
const unsigned short OFFSET_FLATFIELDAPPLIED      = 0x02C2;
const unsigned short OFFSET_SPARE_3               = 0x02C4;
const unsigned short OFFSET_KIN_TRIG_MODE         = 0x02D4;
const unsigned short OFFSET_DLABEL                = 0x02D6;
const unsigned short OFFSET_SPARE_4               = 0x02E6;
const unsigned short OFFSET_PULSEFILENAME         = 0x049A;
const unsigned short OFFSET_ABSORBFILENAME        = 0x0512;
const unsigned short OFFSET_NUMEXPREPEATS         = 0x058A;
const unsigned short OFFSET_NUMEXPACCUMS          = 0x058E;
const unsigned short OFFSET_YT_FLAG               = 0x0592;
const unsigned short OFFSET_CLKSPD_US             = 0x0594;
const unsigned short OFFSET_HWACCUMFLAG           = 0x0598;
const unsigned short OFFSET_STORESYNC             = 0x059A;
const unsigned short OFFSET_BLEMISHAPPLIED        = 0x059C;
const unsigned short OFFSET_COSMICAPPLIED         = 0x059E;
const unsigned short OFFSET_COSMICTYPE            = 0x05A0;
const unsigned short OFFSET_COSMICTHRESHOLD       = 0x05A2;
const unsigned short OFFSET_NUMFRAMES             = 0x05A6;
const unsigned short OFFSET_MAXINTENSITY          = 0x05AA;
const unsigned short OFFSET_MININTENSITY          = 0x05AE;
const unsigned short OFFSET_YLABEL                = 0x05B2;
const unsigned short OFFSET_SHUTTERTYPE           = 0x05C2;
const unsigned short OFFSET_SHUTTERCOMP           = 0x05C4;
const unsigned short OFFSET_READOUTMODE           = 0x05C8;
const unsigned short OFFSET_WINDOWSIZE            = 0x05CA;
const unsigned short OFFSET_CLKSPD                = 0x05CC;
const unsigned short OFFSET_INTERFACE_TYPE        = 0x05CE;
const unsigned short OFFSET_NUMROISINEXPERIMENT   = 0x05D0;
const unsigned short OFFSET_SPARE_5               = 0x05D2;
const unsigned short OFFSET_CONTROLLERNUM         = 0x05E2;
const unsigned short OFFSET_SWMADE                = 0x05E4;
const unsigned short OFFSET_NUMROI                = 0x05E6;
const unsigned short OFFSET_ROIINFOBLK_1          = 0x05E8;
const unsigned short OFFSET_ROIINFOBLK_2          = 0x05F4;
const unsigned short OFFSET_ROIINFOBLK_3          = 0x0600;
const unsigned short OFFSET_ROIINFOBLK_4          = 0x060C;
const unsigned short OFFSET_ROIINFOBLK_5          = 0x0618;
const unsigned short OFFSET_ROIINFOBLK_6          = 0x0624;
const unsigned short OFFSET_ROIINFOBLK_7          = 0x0630;
const unsigned short OFFSET_ROIINFOBLK_8          = 0x063C;
const unsigned short OFFSET_ROIINFOBLK_9          = 0x0648;
const unsigned short OFFSET_ROIINFOBLK_10         = 0x0654;
const unsigned short OFFSET_FLATFIELD             = 0x0660;
const unsigned short OFFSET_BACKGROUND            = 0x06D8;
const unsigned short OFFSET_BLEMISH               = 0x0750;
const unsigned short OFFSET_FILE_HEADER_VER       = 0x07C8;
const unsigned short OFFSET_YT_INFO               = 0x07CC;
const unsigned short OFFSET_WINVIEW_ID            = 0x0BB4;
const unsigned short OFFSET_XCALIBRATION          = 0x0BB8;
const unsigned short OFFSET_YCALIBRATION          = 0x0DA1;
const unsigned short OFFSET_ISTRING               = 0x0F8A;
const unsigned short OFFSET_SPARE_6               = 0x0FB2;
const unsigned short OFFSET_SPECTYPE              = 0x0FCB;
const unsigned short OFFSET_SPECMODEL             = 0x0FCC;
const unsigned short OFFSET_PULSEBURSTUSED        = 0x0FCD;
const unsigned short OFFSET_PULSEBURSTCOUNT       = 0x0FCE;
const unsigned short OFFSET_PULSEBURSTPERIOD      = 0x0FD2;
const unsigned short OFFSET_PULSEBRACKETUSED      = 0x0FDA;
const unsigned short OFFSET_PULSEBRACKETTYPE      = 0x0FDB;
const unsigned short OFFSET_PULSETIMECONSTFAST    = 0x0FDC;
const unsigned short OFFSET_PULSEAMPLITUDEFAST    = 0x0FE4;
const unsigned short OFFSET_PULSETIMECONSTSLOW    = 0x0FEC;
const unsigned short OFFSET_PULSEAMPLITUDESLOW    = 0x0FF4;
const unsigned short OFFSET_ANALOGGAIN            = 0x0FFC;
const unsigned short OFFSET_AVGAINUSED            = 0x0FFE;
const unsigned short OFFSET_AVGAIN                = 0x1000;
const unsigned short OFFSET_LASTVALUE             = 0x1002;

speFile::speFile( const std::string& filePath )
{
  setFilePath( filePath );
}

speFile::~speFile()
{
  if( infile.is_open() ) infile.close();
}

bool speFile::setFilePath( const std::string& filePath )
{
  if( infile.is_open() ) infile.close();
  infile.open( filePath.c_str(), std::ios::in | std::ios::binary );
  if( infile.fail() ) infile.close();

  // Retrieve some basic metadata TODO: Expand to cover all pertinent fields
  retrieve( xdim, OFFSET_XDIM );
  retrieve( ydim, OFFSET_YDIM );
  retrieve( NumFrames, OFFSET_NUMFRAMES );
}

void speFile::printInfo() const
{
  std::cout << xdim << " rows x " << ydim << " cols x " << NumFrames << " frames." << std::endl;
}

