#include <pch.hpp>
#include <Engine/Detail/Meta/UniqueTypes.hpp>



#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE(Engine)
BOOST_AUTO_TEST_SUITE(Detail)
BOOST_AUTO_TEST_SUITE(Meta)
BOOST_AUTO_TEST_SUITE(UniqueTypes)



BOOST_AUTO_TEST_CASE(base1Arg)
{
    BOOST_TEST((::engine::detail::meta::UniqueTypes<int>::value));
}

BOOST_AUTO_TEST_CASE(true2Args)
{
    BOOST_TEST((::engine::detail::meta::UniqueTypes<int, float>::value));
}

BOOST_AUTO_TEST_CASE(true3Args)
{
    BOOST_TEST((::engine::detail::meta::UniqueTypes<int, float, double>::value));
}

BOOST_AUTO_TEST_CASE(trueMultipleArgs)
{
    BOOST_TEST((::engine::detail::meta::UniqueTypes<short, int, long, float, double, char>::value));
}



BOOST_AUTO_TEST_CASE(false2Args)
{
    BOOST_TEST((!::engine::detail::meta::UniqueTypes<int, int>::value));
}

BOOST_AUTO_TEST_CASE(false3Args1)
{
    BOOST_TEST((!::engine::detail::meta::UniqueTypes<int, double, int>::value));
}

BOOST_AUTO_TEST_CASE(false3Args2)
{
    BOOST_TEST((!::engine::detail::meta::UniqueTypes<double, int, int>::value));
}

BOOST_AUTO_TEST_CASE(false3Args3)
{
    BOOST_TEST((!::engine::detail::meta::UniqueTypes<int, int, double>::value));
}

BOOST_AUTO_TEST_CASE(falseMultipleArgs1)
{
    BOOST_TEST((!::engine::detail::meta::UniqueTypes<int, float, double, long, short, char, int>::value));
}

BOOST_AUTO_TEST_CASE(falseMultipleArgs2)
{
    BOOST_TEST((!::engine::detail::meta::UniqueTypes<float, double, long, int, short, char, int>::value));
}

BOOST_AUTO_TEST_CASE(falseMultipleArgs3)
{
    BOOST_TEST((!::engine::detail::meta::UniqueTypes<float, double, int, long, short, int, char>::value));
}



BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
