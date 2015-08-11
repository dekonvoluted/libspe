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

#ifndef SPE_DATA_H
#define SPE_DATA_H

#include <cstddef>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

namespace SPE {
class Data
{
    public:
    Data( const std::size_t, const std::size_t );
    ~Data() = default;

    virtual void read( std::ifstream& );
    virtual void reset();

    template<class T> void retrieve( T& value, const std::size_t BYTE_OFFSET = 0, std::size_t DATA_LENGTH = 0 )
    {
        if ( DATA_LENGTH == 0 ) DATA_LENGTH = sizeof( value );

        const std::string slice( stream.begin() + BYTE_OFFSET, stream.begin() + BYTE_OFFSET + DATA_LENGTH );
        std::stringstream( slice ).read( reinterpret_cast<char*>( &value ), DATA_LENGTH );
    }

    private:
    const std::size_t FILE_OFFSET;
    const std::size_t DATA_LENGTH;
    std::vector<char> stream;
};
}

#endif

