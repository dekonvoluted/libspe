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
#include "../spe.h"

#include <Eigen/Core>
#include "speutils-eigen.h"

#include <fstream>

Eigen::MatrixXf readFrame( speFile* imageFile, long frameNumber )
{
  if( !imageFile->dataType() ) return Eigen::MatrixXf::Zero( 1, 1 ); // Invalid file
  
  Eigen::MatrixXf frame;
  frame.setZero( imageFile->rows(), imageFile->cols() );
  if( frameNumber >= imageFile->frames() ) return frame; // Invalid frameNumber  
  
  std::ifstream inFile;
  inFile.open( imageFile->filePath().c_str(), std::ios::in | std::ios::binary );
  
  switch( imageFile->dataType() ) {
    case 1: // float
    {// Block to use pixel variable
      float pixel[ imageFile->rows() * imageFile->cols() ]; // 4 bytes
      inFile.seekg( 4100 + 4 * frameNumber * imageFile->rows() * imageFile->cols() );
      inFile.read( reinterpret_cast<char*>( &pixel ), 4 * imageFile->rows() * imageFile->cols() );
      frame = Eigen::MatrixXf::Map( pixel, imageFile->cols(), imageFile->rows() ).transpose(); // Map populates cols first
    }// pixel is out-of-scope now
    break;
    case 2: // long
    {// Block to use pixel variable
      unsigned pixel[ imageFile->rows() * imageFile->cols() ]; //uint32_t, 4 bytes
      inFile.seekg( 4100 + 4 * frameNumber * imageFile->rows() * imageFile->cols() );
      inFile.read( reinterpret_cast<char*>( &pixel ), 4 * imageFile->rows() * imageFile->cols() );
      for( int r = 0; r < imageFile->rows(); r++ ) {
        for( int c = 0; c < imageFile->cols(); c++ ) {
          frame( r, c ) = pixel[ r * imageFile->cols() + c ];
        }
      }
    }// pixel is out-of-scope now
    break;
    default: // int and unsigned
    {
      unsigned short pixel[ imageFile->rows() * imageFile->cols() ]; // uint16_t, 2 bytes
      inFile.seekg( 4100 + 2 * frameNumber * imageFile->rows() * imageFile->cols() );
      inFile.read( reinterpret_cast<char*>( &pixel ), 2 * imageFile->rows() * imageFile->cols() );
      for( int r = 0; r < imageFile->rows(); r++ ) {
        for( int c = 0; c < imageFile->cols(); c++ ) {
          frame( r, c ) = pixel[ r * imageFile->cols() + c ];
        }
      }
    }// pixel is out-of-scope now
  }
  
  inFile.close();
  return frame;
}

Eigen::MatrixXf readFrame( speFile& imageFile, long frameNumber )
{
  speFile* spePtr = &imageFile;
  Eigen::MatrixXf speFrame = readFrame( spePtr, frameNumber );
  delete spePtr;
  return speFrame;
}
 
Eigen::MatrixXf readAverage( speFile* imageFile )
{
  Eigen::MatrixXf average;
  if( !imageFile->dataType() ) {// Invalid file
    average.setZero( 1, 1 );
    return average;
  }

  average.setZero( imageFile->rows(), imageFile->cols() );
  for( int f = 0; f < imageFile->frames(); f++ ) {
    average += readFrame( imageFile, f );
  }
  average /= imageFile->frames();
  
  return average;
}

Eigen::MatrixXf readAverage( speFile& imageFile )
{
  speFile* spePtr = &imageFile;
  Eigen::MatrixXf speAverage = readAverage( spePtr );
  delete spePtr;
  return speAverage;
}

Eigen::MatrixXf readAverage( std::string filePath )
{
  speFile* spePtr = new speFile( filePath );
  Eigen::MatrixXf speAverage = readAverage( spePtr );
  delete spePtr;
  return speAverage;
}
