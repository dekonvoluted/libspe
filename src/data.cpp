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

#include "data.h"

namespace SPE {
Data::Data( const size_t fileOffset, const size_t dataLength ) : FILE_OFFSET( fileOffset ), DATA_LENGTH( dataLength ), stream( dataLength, 0 )
{}

void Data::read( std::ifstream& file )
{
    reset();
    file.seekg( FILE_OFFSET );
    file.read( stream.data(), DATA_LENGTH );
}

void Data::reset()
{
    stream.clear();
}
}

