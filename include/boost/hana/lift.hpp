/*!
@file
Defines `boost::hana::lift`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_LIFT_HPP
#define BOOST_HANA_LIFT_HPP

#include <boost/hana/fwd/lift.hpp>

#include <boost/hana/core/datatype.hpp>
#include <boost/hana/core/default.hpp>
#include <boost/hana/core/models.hpp>
#include <boost/hana/core/when.hpp>
#include <boost/hana/detail/dispatch_if.hpp>


namespace boost { namespace hana {
    template <typename A>
    struct lift_t {
    #ifndef BOOST_HANA_CONFIG_DISABLE_CONCEPT_CHECKS
        static_assert(_models<Applicative, A>::value,
        "hana::lift<A> requires 'A' to be an Applicative");
    #endif

        template <typename X>
        constexpr auto operator()(X&& x) const {
            using Lift = BOOST_HANA_DISPATCH_IF(lift_impl<A>,
                _models<Applicative, A>::value
            );

            return Lift::apply(static_cast<X&&>(x));
        }
    };

    template <typename A, bool condition>
    struct lift_impl<A, when<condition>> : default_ {
        template <typename ...Args>
        static constexpr auto apply(Args&& ...args) = delete;
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_LIFT_HPP