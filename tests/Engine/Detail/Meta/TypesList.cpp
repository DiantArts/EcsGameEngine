#include <pch.hpp>
#include <Engine/Detail/Meta/TypesList.hpp>



#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE(Engine)
BOOST_AUTO_TEST_SUITE(Detail)
BOOST_AUTO_TEST_SUITE(Meta)
BOOST_AUTO_TEST_SUITE(TypeListContains)


BOOST_AUTO_TEST_CASE(True2ArgsBeg)
{
    BOOST_TEST((::engine::detail::meta::TypeList<int, float>::contains<int>() == true));
}

BOOST_AUTO_TEST_CASE(True2ArgsEnd)
{
    BOOST_TEST((::engine::detail::meta::TypeList<float, int>::contains<int>() == true));
}

BOOST_AUTO_TEST_CASE(TrueMultipleArgsBeg)
{
    BOOST_TEST((::engine::detail::meta::TypeList<short, float, double, long, char>::contains<short>() == true));
}

BOOST_AUTO_TEST_CASE(TrueMultipleArgsMid)
{
    BOOST_TEST((::engine::detail::meta::TypeList<float, double, short, long, char>::contains<short>() == true));
}

BOOST_AUTO_TEST_CASE(TrueMultipleArgsEnd)
{
    BOOST_TEST((::engine::detail::meta::TypeList<float, double, long, char, short>::contains<short>() == true));
}

BOOST_AUTO_TEST_CASE(False2Args)
{
    BOOST_TEST((::engine::detail::meta::TypeList<float, double>::contains<int>() == false));
}

BOOST_AUTO_TEST_CASE(FalseMultipleArgs)
{
    BOOST_TEST((::engine::detail::meta::TypeList<float, double, short, long, char>::contains<int>() == false));
}



BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
