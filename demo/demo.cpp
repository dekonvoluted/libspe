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

#include <vector>
#include "utils/speutils.h"

#include <Eigen/Core>
#include "eigen/speutils-eigen.h"

#include <fstream>

using namespace std;
using namespace Eigen;

int main()
{
  // Get all spe files in the current directory
  vector<string> files = lsspe( "./" );
  if ( files.size() == 0 ) {
    cout << "No SPE files found." << endl;
    return 1;
  }
  cout << files.size() << " SPE file(s) found." << endl;
  for( unsigned count = 0; count < files.size(); count++ ) {
    cout << files[ count ] << endl;
  }
  
  // Read the first spe file, output metadata
  speFile* imageFile;
  imageFile = new speFile( files[ 0 ] );
  cout << "Metadata from " << files[ 0 ] << endl;
  cout << "path: " << imageFile->filePath() << endl;
  cout << "rows: " << imageFile->rows() << " pixels" << endl;
  cout << "cols: " << imageFile->cols() << " pixels" << endl;
  cout << "frames: " << imageFile->frames() << " frames" << endl;
  cout << "dataType: " << imageFile->dataType() << endl;
  cout << "Summary of metadata: " << *imageFile << endl;
  
  // Read the average of all frames in an image
  MatrixXf image;
  image.setZero( imageFile->rows(), imageFile->cols() );
  image = readAverage( imageFile );
  
  // Write average to data file
  ofstream outFile;
  outFile.open( "image.dat" );
  outFile << image << endl;
  outFile.close();
  
  delete imageFile;
  
  return 0;
}
