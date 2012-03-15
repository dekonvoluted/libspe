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

// Utilities to work with spe files
// Needs <vector>
// Needs <string>
// Needs "spe.h"

#ifndef SPEUTILS_H
#define SPEUTILS_H

std::vector<std::string> lsspe( std::string ); // List spe files in a directory
std::ostream& operator<< (std::ostream&, speFile& ); // Sends out metadata

#endif
