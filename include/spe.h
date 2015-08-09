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

#ifndef SPE_FILE_H
#define SPE_FILE_H

#include <string>
#include <fstream>

#include "metadata.h"

namespace SPE {
class File
{
    public:
    File() = default;
    File( const std::string& );
    ~File();

    void read( const std::string& );

    unsigned short rows() const;
    unsigned short columns() const;
    long frames() const;

    Metadata metadata;

    private:
    std::ifstream file;
};
}

#endif

