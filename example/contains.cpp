/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/contains.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/set.hpp>
#include <boost/hana/tuple.hpp>
#include <boost/hana/type.hpp>
namespace hana = boost::hana;


BOOST_HANA_CONSTANT_CHECK(hana::contains(hana::make_tuple(2, hana::int_<2>, hana::int_<3>, 'x'), hana::int_<3>));

BOOST_HANA_CONSTANT_CHECK(hana::contains(hana::make_set(hana::int_<3>, hana::type<void>), hana::type<void>));

// contains can be applied in infix notation
BOOST_HANA_CONSTANT_CHECK(
    hana::make_tuple(2, hana::int_<2>, hana::int_<3>, 'x') ^hana::contains^ hana::int_<2>
);

int main() { }