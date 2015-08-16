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
/*! \brief Binary data present in an SPE file
 *
 * This parent class provides methods to read and extract information from binary data present in an SPE file.
 */
class Data
{
    public:
    /*! \brief Create an empty instance of data
     *
     * An empty instance of data is created by specifying two values---the offset from the start of the file where the data begins and the amount of data present.
     * Both values are specified in bytes.
     */
    Data( const std::size_t, const std::size_t );
    ~Data() = default;

    /*! \brief Read data from an opened SPE file
     *
     * This method extracts binary data from an open SPE file.
     * The extracted bytes are stored internally for further processing.
     */
    virtual void read( std::ifstream& );

    /*! \brief Extract meaningful information from binary data
     *
     * This template method will reinterpret the binary data read from the SPE file into a usable datatype.
     * The binary data will be transfered to the location in memory where the given value is stored.
     * Optionally, a byte offset from the start of the binary data can be specified.
     * By default, data will be read from the beginning of the binary stream.
     * Also, the length of data to be reinterpreted can be specified.
     * The default is to use the size of the value variable.
     *
     * \param value The value to be retrieved
     * \param BYTE_OFFSET The start of the value in the binary stream
     * \param DATA_LENGTH The length of the binary stream to convert into the value
     */
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

    protected:
    virtual void reset();
};
}

#endif

