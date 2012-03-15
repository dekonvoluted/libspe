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

// Methods to read from SPE files
// Needs <string>

// WinView manual p.254
// Version 1.6 header
//                Type              Byte offset
// xdim (cols)    unsigned int      42
// ydim (rows)    unsigned int      656
// datatype       int               108
// NumFrames      long int          1446
// <data>                           4100

#ifndef SPE_H
#define SPE_H

class speFile {
  std::string m_filePath;           // Path to file
  long m_frames;                    // Number of frames in the image
  unsigned short m_rows;            // X-dimension of a frame
  unsigned short m_cols;            // Y-dimension of a frame
  int m_dataType;                   //-1: invalid
                                    // 0: float
                                    // 1: long
                                    // 2: int
                                    // 3: unsigned
    
  void init( std::string );         // Retrieves metadata for given filepath
public:
  speFile();                        // Create default spe object through create()
  speFile( std::string );           // Create default spe object through create()
                                    // Retrieve metadata for valid filepath

  void setFilePath( std::string );  // Retrieve metadata for valid filepath
    
  std::string filePath();           // Returns the filepath or ""
  long frames();                    // Returns the number of frames or 0
  unsigned short rows();            // Returns the number of rows or 0
  unsigned short cols();            // Returns the number of columns or 0
  int dataType();                   // Returns data type + 1 (i.e., 0 = invalid)
};

#endif
