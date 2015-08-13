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

const std::size_t OFFSET_XDIM = 0x002A;
const std::size_t OFFSET_YDIM = 0x0290;
const std::size_t OFFSET_DATATYPE = 0x006C;
const std::size_t OFFSET_NUMFRAMES = 0x05A6;
const std::size_t OFFSET_DATA = 0x1004;

#endif

