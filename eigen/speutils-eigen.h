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

// Eigen utilities for spe files
// Needs <eigen2/Eigen/Core>
// Needs "spe.h"
// Needs <string>

#ifndef SPEUTILS_EIGEN_H
#define SPEUTILS_EIGEN_H

Eigen::MatrixXf readFrame( speFile*, long ); // Get one frame
Eigen::MatrixXf readFrame( speFile&, long ); // Get one frame

Eigen::MatrixXf readAverage( speFile* );    // Get average of all frames
Eigen::MatrixXf readAverage( speFile& );    // Get average of all frames
Eigen::MatrixXf readAverage( std::string ); // Get average of all frames 

#endif
