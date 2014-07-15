/**
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef IO_POINT_HPP
#define IO_POINT_HPP

#include <iostream>
#include <bitcoin/bitcoin.hpp>
#include <sx/serializer/bitcoin256.hpp>

/* NOTE: don't declare 'using namespace foo' in headers. */

namespace sx {
namespace serializer {

#define SX_SERIALIZER_IO_POINT_DELIMITER ":"
#define SX_SERIALIZER_IO_POINT_DELIMITER_EXCEPTION \
    "Point must have two parts delimited by a colon."

/**
 * Serialization helper to convert between hex string and input_point and
 * output_point. These points should not be confused with points on a curve.
 */
class io_point
{
public:

    /**
     * Constructor.
     */
    io_point()
        : value_() {}

    /**
     * Initialization constructor.
     * 
     * @param[in]  hex  The value to initialize with.
     */
    io_point(const std::string& hex)
    {
        std::stringstream(hex) >> *this;
    }

    /**
     * Initialization constructor.
     * 
     * @param[in]  value  The value to initialize with.
     */
    io_point(const bc::output_point& value)
    {
        std::copy(value.hash.begin(), value.hash.end(), value_.hash.begin());
        value_.index = value.index;
    }

    /**
     * Copy constructor.
     *
     * @param[in]  other  The object to copy into self on construct.
     */
    io_point(const io_point& other)
        : io_point(other.value_) {}

    /**
     * Return a reference to the data member.
     *
     * @return  A reference to the object's internal data.
     */
    bc::output_point& data()
    {
        return value_;
    }

    /**
     * Overload cast to internal type.
     *
     * @return  This object's value cast to internal type.
     */
    operator const bc::output_point() const
    {
        return value_; 
    }

    /**
     * Overload stream in. Throws if input is invalid.
     *
     * @param[in]   input     The input stream to read the value from.
     * @param[out]  argument  The object to receive the read value.
     * @return                The input stream reference.
     */
    friend std::istream& operator>>(std::istream& input, io_point& argument)
    {
        std::string structure;
        input >> structure;

        // Note: there is no bc::uncat_point()
        std::vector<std::string> members;
        split(structure, members, SX_SERIALIZER_IO_POINT_DELIMITER);

        if (members.size() != 2)
            throw po::invalid_option_value(
                SX_SERIALIZER_IO_POINT_DELIMITER);

        parse(argument.value_.index, members[1]);
        bc::hash_digest hash = bitcoin256(members[0]);

        std::copy(hash.begin(), hash.end(), argument.value_.hash.begin());
        return input;
    }

    /**
     * Overload stream out.
     *
     * @param[in]   output    The output stream to write the value to.
     * @param[out]  argument  The object from which to obtain the value.
     * @return                The output stream reference.
     */
    friend std::ostream& operator<<(std::ostream& output, 
        const io_point& argument)
    {
        // See bc::concat_point()
        output << bitcoin256(argument.value_.hash) <<
            SX_SERIALIZER_IO_POINT_DELIMITER << argument.value_.index;
        return output;
    }

private:

    /**
     * The state of this object.
     */
    bc::output_point value_;
};

} // sx
} // serializer

#endif