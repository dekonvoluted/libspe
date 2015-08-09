# This file is part of libspe, a C++ library to interface with spe files.
# Copyright (c) 2012,2013,2014,2015 Karthik Periagaram <dekonvoluted@gmail.com>
#
# libspe is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# libspe is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with libspe.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required( VERSION 3.3 )

include_directories( ${PROJECT_SOURCE_DIR}/include )

set( SPE_SOURCES spe.cpp data.cpp metadata.cpp )

add_library( spe SHARED ${SPE_SOURCES} )

