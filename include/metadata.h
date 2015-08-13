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

#ifndef SPE_METADATA_H
#define SPE_METADATA_H

#include <fstream>
#include <cstdint>

#include "data.h"

namespace SPE {
struct Metadata : public Data
{
    public:
    Metadata();
    ~Metadata() = default;

    void read( std::ifstream& );

    std::uint16_t xdim;
    std::uint16_t ydim;
    std::int16_t datatype;
    std::int32_t NumFrames;

    private:
    virtual void reset();
};
}

#endif

