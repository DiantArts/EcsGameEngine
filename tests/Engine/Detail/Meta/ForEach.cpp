#include <pch.hpp>
#include <Engine/Core/Detail/Meta/ForEach.hpp>



#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE(Engine)
BOOST_AUTO_TEST_SUITE(Core)
BOOST_AUTO_TEST_SUITE(Detail)
BOOST_AUTO_TEST_SUITE(Meta)
BOOST_AUTO_TEST_SUITE(ForEach)



BOOST_AUTO_TEST_CASE(run)
{
    int value{ 0 };
    ::engine::core::detail::meta::ForEach<int, float>::run<[]<typename>(int& value){ value++; }>(value);
    BOOST_TEST(value == 2);
    ::engine::core::detail::meta::ForEach<int, float, int>::run<[]<typename>(int& value){ value++; }>(value);
    BOOST_TEST(value == 5);
}

BOOST_AUTO_TEST_CASE(compare)
{
    bool value;

    value = ::engine::core::detail::meta::ForEach<int, short, long>::compare<[]<typename T>(){
        return ::std::is_integral<T>();
    }>();
    BOOST_TEST(value);

    value = ::engine::core::detail::meta::ForEach<float, int, char>::compare<[]<typename T>(){
        return ::std::is_integral<T>();
    }>();
    BOOST_TEST(!value);

    value = ::engine::core::detail::meta::ForEach<int, float, char>::compare<[]<typename T>(){
        return ::std::is_integral<T>();
    }>();
    BOOST_TEST(!value);
}



BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
