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

#include <string>
#include "spe.h"

#include <fstream>

void speFile::init( std::string path )
{
  m_filePath = "";
  m_frames = 0;
  m_rows = 0;
  m_cols = 0;
  m_dataType = -1;
  if( path.empty() ) return; // Empty path

  std::ifstream infile( path.c_str(), std::ios::in | std::ios::binary );
  if( !infile ) return; // Invalid file

  m_filePath = path;

  infile.seekg( 42 );
  infile.read( reinterpret_cast<char*>( &m_cols ), sizeof( m_cols ) );

  infile.seekg( 108 );
  infile.read( reinterpret_cast<char*>( &m_dataType ), sizeof( m_dataType ) );

  infile.seekg( 656 );
  infile.read( reinterpret_cast<char*>( &m_rows ), sizeof( m_rows ) );

  infile.seekg( 1446 );
  infile.read( reinterpret_cast<char*>( &m_frames ), sizeof( m_frames ) );

  infile.close();
}

speFile::speFile()
{
  init( "" );
}

speFile::speFile( std::string path )
{
  init( path );
}

void speFile::setFilePath( std::string path )
{
  init( path );
}

std::string speFile::filePath()
{  
  return m_filePath;
}

long speFile::frames()
{
  return m_frames;
}

unsigned short speFile::rows()
{
  return m_rows;
}

unsigned short speFile::cols()
{
  return m_cols;
}

int speFile::dataType()
{
  return ( m_dataType + 1 );
}
