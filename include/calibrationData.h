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

#ifndef SPE_CALIBRATIONDATA_H
#define SPE_CALIBRATIONDATA_H

#include <fstream>
#include <cstdint>
#include <string>
#include <vector>
#include <iostream>

#include "data.h"

namespace SPE {
/*! \brief Binary data present in a Calibration data block
 *
 * This struct contains all the data present in a calibration data block.
 */
struct CalibrationData : public Data
{
    public:
    /*! \brief Create an empty Calibration data block
     *
     * An empty instance of CalibrationData is created.
     * All fields of the CalibrationData default to zero (when applicable).
     */
    CalibrationData( const std::size_t );
    ~CalibrationData() = default;

    /*! \brief Read data from an opened SPE file
     *
     * This method extracts the binary data comprising a calibration data block from an opened SPE file.
     * The extracted bytes are stored internally for further processing.
     */
    void read( std::ifstream& );

    //! \brief offset for absolute data scaling
    double offset = 0.0;

    //! \brief factor for absolute data scaling
    double factor = 0.0;

    //! \brief selected scaling unit
    std::int8_t current_unit = 0;

    /*!
     * \brief special string for scaling
     *
     * This field is very unfortunately named in the specification, but compiles without error.
     */
    std::string string = std::string( std::string( 39, ' ' ) + '\0' );

    //! \brief flag if calibration is valid
    std::int8_t calib_valid = 0;

    //! \brief current input units for "calib_value"
    std::int8_t input_unit = 0;

    //! \brief linear UNIT and used in the "polynom_coeff"
    std::int8_t polynom_unit = 0;

    //! \brief ORDER of calibration POLYNOM
    std::int8_t polynom_order = 0;

    //! \brief valid calibration data pairs
    std::int8_t calib_count = 0;

    //! \brief pixel pos. of calibration data
    std::vector<double> pixel_position = std::vector<double>( 10, 0.0 );

    //! \brief calibration VALUE at above pos
    std::vector<double> calib_value = std::vector<double>( 10, 0.0 );

    //! \brief polynom COEFFICIENTS
    std::vector<double> polynom_coeff = std::vector<double>( 6, 0.0 );

    //! \brief laser wavenumber for relativ WN
    double laser_position = 0.0;

    //! \brief If set to 200, valid label below
    std::uint8_t new_calib_flag = 0;

    //! \brief Calibration label (NULL term'd)
    std::string calib_label = std::string( std::string( 80, ' ' ) + '\0' );

    virtual void reset();
};
}

/*! \brief Output a calibration block
 *
 * This method prints out the available info to an output stream
 */
std::ostream& operator<<( std::ostream&, const SPE::CalibrationData& );

#endif

