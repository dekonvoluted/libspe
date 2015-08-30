// This file is part of libSPE, a C++ library to interface with SPE files.
//
// Copyright (c) 2012,2013,2014,2015 Karthik Periagaram <dekonvoluted@gmail.com>
//
// libSPE is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libSPE is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libSPE. If not, see <http://www.gnu.org/licenses/>.

#include "data.h"

namespace SPE {
/*!
 * \param fileOffset The number of bytes from the start of the file where the data begins
 * \param dataLength The number of bytes of data to read into the stream
 */
Data::Data( const std::size_t fileOffset, const std::size_t dataLength ) : FILE_OFFSET( fileOffset ), DATA_LENGTH( dataLength ), stream( dataLength, 0 )
{}

/*!
 * \param file The file stream to read data from
 * \return void
 */
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

