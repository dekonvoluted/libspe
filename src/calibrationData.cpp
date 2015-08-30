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

#include <iomanip>

#include "calibrationData.h"

namespace SPE {
//! \param OFFSET The offset at which the current calibration data block begins
CalibrationData::CalibrationData( const std::size_t OFFSET ) : Data( OFFSET, 489 )
{}

/*!
 * \param file The file stream to read data from
 * \return void
 */
void CalibrationData::read( std::ifstream& file )
{
    Data::read( file );

    retrieve( offset, 0 );
    retrieve( factor, 8 );
    retrieve( current_unit, 16 );
    retrieve( string[ 0 ], 18, 40 );
    retrieve( calib_valid, 98 );
    retrieve( input_unit, 99 );
    retrieve( polynom_unit, 100 );
    retrieve( polynom_order, 101 );
    retrieve( calib_count, 102 );
    retrieve( pixel_position[ 0 ], 103, 80 );
    retrieve( calib_value[ 0 ], 183, 80 );
    retrieve( polynom_coeff[ 0 ], 263, 48 );
    retrieve( laser_position, 311 );
    retrieve( new_calib_flag, 320 );
    retrieve( calib_label[ 0 ], 321, 81 );
}

void CalibrationData::reset()
{
    Data::reset();

    offset = 0.0;
    factor = 0.0;
    current_unit = 0;
    string = std::string( std::string( 39, ' ' ) + '\0' );
    calib_valid = 0;
    input_unit = 0;
    polynom_unit = 0;
    polynom_order = 0;
    calib_count = 0;
    pixel_position = std::vector<double>( 10, 0.0 );
    calib_value = std::vector<double>( 10, 0.0 );
    polynom_coeff = std::vector<double>( 6, 0.0 );
    laser_position = 0.0;
    new_calib_flag = 0;
    calib_label = std::string( std::string( 80, ' ' ) + '\0' );
}
}

/*!
 * \param out An output stream
 * \param calibrationData An instance of SPE Calibration data
 */
std::ostream& operator<<( std::ostream& out, const SPE::CalibrationData& calibrationData )
{
    const int MAXWIDTH = 20;
    out << std::setw( MAXWIDTH ) << "offset" << '\t' << calibrationData.offset << '\n';
    out << std::setw( MAXWIDTH ) << "factor" << '\t' << calibrationData.factor << '\n';
    out << std::setw( MAXWIDTH ) << "current_unit" << '\t' << static_cast<std::int16_t>( calibrationData.current_unit ) << '\n';
    out << std::setw( MAXWIDTH ) << "string" << "\t\"" << calibrationData.string << "\"\n";
    out << std::setw( MAXWIDTH ) << "calib_valid" << '\t' << static_cast<std::int16_t>( calibrationData.calib_valid ) << '\n';
    out << std::setw( MAXWIDTH ) << "input_unit" << '\t' << static_cast<std::int16_t>( calibrationData.input_unit ) << '\n';
    out << std::setw( MAXWIDTH ) << "polynom_unit" << '\t' << static_cast<std::int16_t>( calibrationData.polynom_unit ) << '\n';
    out << std::setw( MAXWIDTH ) << "polynom_order" << '\t' << static_cast<std::int16_t>( calibrationData.polynom_order ) << '\n';
    out << std::setw( MAXWIDTH ) << "calib_count" << '\t' << static_cast<std::int16_t>( calibrationData.calib_count ) << '\n';
    out << std::setw( MAXWIDTH ) << "pixel_position" << "\t{" << calibrationData.pixel_position.at( 0 ) << ", " << calibrationData.pixel_position.at( 1 ) << ", " << calibrationData.pixel_position.at( 2 ) << ", " << calibrationData.pixel_position.at( 3 ) << ", " << calibrationData.pixel_position.at( 4 ) << ", " << calibrationData.pixel_position.at( 5 ) << ", " << calibrationData.pixel_position.at( 6 ) << ", " << calibrationData.pixel_position.at( 7 ) << ", " << calibrationData.pixel_position.at( 8 ) << ", " << calibrationData.pixel_position.at( 9 ) << "}\n";
    out << std::setw( MAXWIDTH ) << "calib_value" << "\t{" << calibrationData.calib_value.at( 0 ) << ", " << calibrationData.calib_value.at( 1 ) << ", " << calibrationData.calib_value.at( 2 ) << ", " << calibrationData.calib_value.at( 3 ) << ", " << calibrationData.calib_value.at( 4 ) << ", " << calibrationData.calib_value.at( 5 ) << ", " << calibrationData.calib_value.at( 6 ) << ", " << calibrationData.calib_value.at( 7 ) << ", " << calibrationData.calib_value.at( 8 ) << ", " << calibrationData.calib_value.at( 9 ) << "}\n";
    out << std::setw( MAXWIDTH ) << "polynom_coeff" << "\t{" << calibrationData.polynom_coeff.at( 0 ) << ", " << calibrationData.polynom_coeff.at( 1 ) << ", " << calibrationData.polynom_coeff.at( 2 ) << ", " << calibrationData.polynom_coeff.at( 3 ) << ", " << calibrationData.polynom_coeff.at( 4 ) << ", " << calibrationData.polynom_coeff.at( 5 ) << "}\n";
    out << std::setw( MAXWIDTH ) << "laser_position" << '\t' << calibrationData.laser_position << '\n';
    out << std::setw( MAXWIDTH ) << "new_calib_flag" << '\t' << static_cast<std::uint16_t>( calibrationData.new_calib_flag ) << '\n';
    out << std::setw( MAXWIDTH ) << "calib_label" << "\t\"" << calibrationData.calib_label << "\"";

    return out;
}

