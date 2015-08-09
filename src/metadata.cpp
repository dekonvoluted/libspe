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

#include <string>

#include "metadata.h"
#include "offsets.h"

namespace SPE {

Metadata::Metadata() : header( OFFSET_DATA, 0 )
{}

void Metadata::read( std::ifstream& file )
{
    reset();
    file.seekg( 0 );
    file.read( header.data(), OFFSET_DATA );

    retrieve( xdim, OFFSET_XDIM );
    retrieve( ydim, OFFSET_YDIM );
    retrieve( NumFrames, OFFSET_NUMFRAMES );
}

void Metadata::reset()
{
    header.clear();

    xdim = 0;
    ydim = 0;
    NumFrames = 0;
}

unsigned Metadata::rows() const
{
    return ydim;
}

unsigned Metadata::columns() const
{
    return xdim;
}

long Metadata::frames() const
{
    return NumFrames;
}
}

