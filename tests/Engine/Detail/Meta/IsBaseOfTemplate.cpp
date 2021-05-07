#include <pch.hpp>
#include <Engine/Core/Detail/Meta/IsBaseOfTemplate.hpp>



namespace test::detail {

template <
    typename
> class Base {};

class OtherBase {};

class DerivedPublic : public ::test::detail::Base<DerivedPublic> {};

class DerivedPrivate : private ::test::detail::Base<DerivedPrivate> {};

class DerivedDerived : public DerivedPublic {};

} // namespace test::detail



#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE(Engine)
BOOST_AUTO_TEST_SUITE(Core)
BOOST_AUTO_TEST_SUITE(Detail)
BOOST_AUTO_TEST_SUITE(Meta)
BOOST_AUTO_TEST_SUITE(IsBaseOfTemplate)



BOOST_AUTO_TEST_CASE(DerivedPublic)
{
    BOOST_TEST((::engine::core::detail::meta::IsBaseOfTemplate<
        ::test::detail::Base,
        ::test::detail::DerivedPublic
    >::value));
}

BOOST_AUTO_TEST_CASE(DerivedDerived)
{
    BOOST_TEST((::engine::core::detail::meta::IsBaseOfTemplate<
        ::test::detail::Base,
        ::test::detail::DerivedDerived
    >::value));
}

BOOST_AUTO_TEST_CASE(FalseDerivedPrivate)
{
    BOOST_TEST(!(::engine::core::detail::meta::IsBaseOfTemplate<
        ::test::detail::Base,
        ::test::detail::DerivedPrivate
    >::value));
}


BOOST_AUTO_TEST_CASE(False)
{
    BOOST_TEST(!(::engine::core::detail::meta::IsBaseOfTemplate<
        ::test::detail::Base,
        ::test::detail::OtherBase
    >::value));
}



BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
