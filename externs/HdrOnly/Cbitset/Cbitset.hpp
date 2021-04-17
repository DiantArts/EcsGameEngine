// BITSET2
//
//  Copyright Claas Bontus
//
//  Use, modification and distribution is subject to the
//  Boost Software License, Version 1.0. (See accompanying
//  file LICENSE.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// Project home: https://github.com/ClaasBontus/Cbitset
//


#ifndef BITSET2_CB_HPP
#define BITSET2_CB_HPP


#include "detail/hex_params.hpp"
#include "detail/select_base_t.hpp"
#include "detail/hash.hpp"
#include "detail/array_access.hpp"
#include "detail/array_funcs.hpp"
#include "detail/array_add.hpp"
#include "detail/array_ops.hpp"
#include "detail/array_complement2.hpp"
#include "detail/array2array.hpp"
#include "detail/bitset2_impl.hpp"

#include <bitset>
#include <climits>
#include <cstdint>
#include <array>
#include <stdexcept>
#include <utility>
#include <string>
#include <functional>
#include <type_traits>



namespace cbitset
{



template<size_t N,
         class T= cbitset::detail::select_base_t<N>,
         class Enabled=void> class Cbitset;

template<size_t N,class T>
class Cbitset<N,T,
              typename std::enable_if<   std::is_integral<T>::value
                                      && std::is_unsigned<T>::value>::type>
: public detail::Cbitset_impl<N,T>
{
  enum : size_t { base_t_n_bits= detail::Cbitset_impl<N,T>::base_t_n_bits };
public:
  using array_t=  typename detail::Cbitset_impl<N,T>::array_t;
  using ULLONG_t= typename detail::Cbitset_impl<N,T>::ULLONG_t;
  using base_t=   T;
  using detail::Cbitset_impl<N,T>::n_array;

  enum : size_t { npos= detail::h_types<T>::npos };

  class reference
  {
    friend class Cbitset;
    reference() noexcept {}
    reference( Cbitset<N,T> *ptr, size_t bit ) noexcept
    : m_ptr( ptr )
    , m_bit( bit )
    {}
    Cbitset<N,T> *m_ptr= nullptr;
    size_t       m_bit;
  public:
    ~reference() noexcept {}
    reference& operator=( bool x ) noexcept
    {
      m_ptr->set_noexcept( m_bit, x );
      return *this;
    }
    reference& operator=( reference const & r ) noexcept
    {
      m_ptr->set_noexcept( m_bit, bool( r ) );
      return *this;
    }
    reference& flip() noexcept
    {
      m_ptr->flip_noexcept( m_bit );
      return *this;
    }
    operator bool() const noexcept
    { return m_ptr->test_noexcept(m_bit); }
    bool operator~() const noexcept
    { return !bool(*this); }
  }; // class reference


  /* ------------------------------------------------------------- */
  constexpr
  Cbitset() noexcept
  : detail::Cbitset_impl<N,T>()
  {}

  constexpr
  Cbitset( Cbitset const & ) noexcept= default;

  constexpr
  Cbitset( Cbitset && ) noexcept= default;

  constexpr
  Cbitset &
  operator=( Cbitset const & ) noexcept= default;

  constexpr
  Cbitset &
  operator=( Cbitset && ) noexcept= default;

  explicit
  Cbitset( const std::bitset<N> &bs ) noexcept
  : detail::Cbitset_impl<N,T>( bs )
  {}

  explicit
  constexpr
  Cbitset( ULLONG_t v ) noexcept
  : detail::Cbitset_impl<N,T>( v )
  {}

  template<size_t n,class Tsrc>
  explicit
  constexpr
  Cbitset( std::array<Tsrc,n> const & value ) noexcept
  : detail::Cbitset_impl<N,T>( value )
  {}

  template< class CharT, class Traits, class Alloc >
  explicit
  Cbitset( std::basic_string<CharT,Traits,Alloc> const
                    & str,
           typename std::basic_string<CharT,Traits,Alloc>::size_type
                    pos = 0,
           typename std::basic_string<CharT,Traits,Alloc>::size_type
                    n = std::basic_string<CharT,Traits,Alloc>::npos,
           CharT    zero= CharT('0'),
           CharT    one=  CharT('1') )
  : detail::Cbitset_impl<N,T>( str, pos, n, zero, one )
  {}


  template< class CharT >
  explicit
  Cbitset( const CharT        *str,
           typename std::basic_string<CharT>::size_type
                              n=     std::basic_string<CharT>::npos,
           CharT              zero=  CharT('0'),
           CharT              one=   CharT('1') )
  : detail::Cbitset_impl<N,T>( n == std::basic_string<CharT>::npos
                               ? std::basic_string<CharT>( str )
                               : std::basic_string<CharT>( str, n ),
                               0, n, zero, one )
  {}
  /* ------------------------------------------------------------- */


  //****************************************************

  /// Bitwise NOT
  constexpr
  Cbitset
  operator~() const noexcept
  { return Cbitset(detail::array_ops<N,T>( 0 ).flip(this->data())); }

  constexpr
  bool
  operator[]( size_t bit ) const noexcept
  { return detail::Cbitset_impl<N,T>::operator[]( bit ); }

  reference
  operator[]( size_t bit ) noexcept
  { return reference( this, bit ); }

  constexpr
  Cbitset &
  operator<<=( size_t n_shift ) noexcept
  {
    detail::array_ops<N,T>( n_shift ).shift_left_assgn( this->get_data() );
    return *this;
  }

  constexpr
  Cbitset &
  operator>>=( size_t n_shift ) noexcept
  {
    detail::array_ops<N,T>( n_shift ).shift_right_assgn( this->get_data() );
    return *this;
  }

  constexpr
  Cbitset &
  rotate_left( size_t n_rot ) noexcept
  {
    this->get_data()= detail::array_ops<N,T>(n_rot).rotate_left( this->data() );
    return *this;
  }

  constexpr
  Cbitset &
  rotate_right( size_t n_rot ) noexcept
  {
    this->get_data()= detail::array_ops<N,T>( N - ( n_rot % N ) )
                                        .rotate_left( this->data() );
    return *this;
  }

  constexpr
  Cbitset &
  reverse() noexcept
  {
    this->get_data()= detail::array_ops<N,T>( 0 ).reverse( this->data() );
    return *this;
  }

  /// Computes two's complement
  constexpr
  Cbitset &
  complement2() noexcept
  {
    detail::array_complement2<N,T>().comp2_assgn( this->get_data() );
    return *this;
  }

  constexpr
  Cbitset &
  operator+=( Cbitset const &bs2 ) noexcept
  {
    detail::array_add<N,T>().add_assgn(this->get_data(), bs2.data());
    return *this;
  }

  constexpr
  Cbitset &
  operator++() noexcept
  {
    detail::array_ops<N,T>(0).increment( this->get_data() );
    return *this;
  }

  constexpr
  Cbitset
  operator++(int) noexcept
  {
    Cbitset tmp( *this );
    operator++();
    return tmp;
  }

  constexpr
  Cbitset &
  operator--() noexcept
  {
    detail::array_ops<N,T>(0).decrement( this->get_data() );
    return *this;
  }

  constexpr
  Cbitset
  operator--(int) noexcept
  {
    Cbitset tmp( *this );
    operator--();
    return tmp;
  }

  constexpr
  Cbitset &
  operator|=( Cbitset const & v2 ) noexcept
  {
    detail::array_funcs<Cbitset::n_array,T>()
             .bitwise_or_assgn(this->get_data(), v2.data() );
    return *this;
  }

  constexpr
  Cbitset &
  operator&=( Cbitset const & v2 ) noexcept
  {
    detail::array_funcs<Cbitset::n_array,T>()
              .bitwise_and_assgn( this->get_data(), v2.data() );
    return *this;
  }

  constexpr
  Cbitset &
  operator^=( Cbitset const & v2 ) noexcept
  {
    detail::array_funcs<Cbitset::n_array,T>()
              .bitwise_xor_assgn( this->get_data(), v2.data() );
    return *this;
  }

  /// Computes the set difference, i.e. *this &= ~v2
  constexpr
  Cbitset &
  difference( Cbitset const & v2 ) noexcept
  {
    detail::array_funcs<Cbitset::n_array,T>()
              .bitwise_setdiff_assgn( this->get_data(), v2.data() );
    return *this;
  }

  constexpr
  Cbitset &
  set() noexcept
  { detail::Cbitset_impl<N,T>::set(); return *this; }

  constexpr
  Cbitset &
  set( size_t bit, bool value= true )
  { detail::Cbitset_impl<N,T>::set( bit, value ); return *this; }

  constexpr
  Cbitset &
  reset() noexcept
  { detail::Cbitset_impl<N,T>::reset(); return *this; }

  constexpr
  Cbitset &
  reset( size_t bit )
  {
    if( bit >= N  ) throw std::out_of_range( "Cbitset: reset out of range" );
   return set( bit, false );
 }

 /// \brief Sets the specified bit if value==true,
 /// clears it otherwise. Returns the previous state of the bit.
 constexpr
 bool
 test_set( size_t bit, bool value= true )
 { return detail::Cbitset_impl<N,T>::test_set( bit, value ); }

 constexpr
 Cbitset &
 flip() noexcept
 { detail::Cbitset_impl<N,T>::flip(); return *this; }

 constexpr
 Cbitset &
 flip( size_t bit )
 { detail::Cbitset_impl<N,T>::flip( bit ); return *this; }

 constexpr std::size_t size() const noexcept { return N; }

 template<class CharT = char,
          class Traits = std::char_traits<CharT>,
          class Allocator = std::allocator<CharT> >
 std::basic_string<CharT,Traits,Allocator>
 to_string( CharT zero = CharT('0'), CharT one = CharT('1') ) const
 {
   std::basic_string<CharT,Traits,Allocator> ret_val;
   ret_val.reserve( N );
   for( size_t ct= N; ct > 0; )
   {
     --ct;
     ret_val += this->operator[]( ct ) ? one : zero;
   }
   return ret_val;
 } // to_string

 template<class CharT = char,
          class Traits = std::char_traits<CharT>,
          class Allocator = std::allocator<CharT>,
          typename std::enable_if<base_t_n_bits % 4 == 0>::type* = nullptr >
 std::basic_string<CharT,Traits,Allocator>
 to_hex_string( hex_params<CharT,Traits,Allocator> const &params=
                hex_params<CharT,Traits,Allocator>{} ) const
 {
   using arr_acc=  detail::array_access<N,T>;
   arr_acc         a_a;
   constexpr auto  div_four= arr_acc::div_four;
   constexpr auto  mod_four= arr_acc::mod_four;
   constexpr auto  n_char= div_four + ( mod_four > 0 );

   auto const      zeroCh= params.zeroCh;
   auto const      aCh=    params.aCh;

   std::basic_string<CharT,Traits,Allocator> ret_val;
   ret_val.reserve( n_char + params.prefix.size() );
   ret_val= params.prefix;
   size_t ct= n_char;
   if( !params.leadingZeroes )
   {
     for( ; ct > 0; --ct )
     {
       auto  const val= a_a.get_four_bits( this->data(), 4 * ct - 1 );
       if( val != 0 ) break;
     }
   }
   if( ct == 0 && params.nonEmpty ) ret_val += zeroCh;
   for( ; ct > 0; --ct )
   {
     auto  const val= a_a.get_four_bits( this->data(), 4 * ct - 1 );
     CharT const c=
     ( val < 10 ) ? ( zeroCh + val ) : ( aCh + ( val - 10 ) );
     ret_val += c;
   }
   return ret_val;
 } // to_hex_string

}; // class Cbitset


template<size_t N, class T>
constexpr
Cbitset<N,T>
rotate_left( Cbitset<N,T> const & bs, size_t n_rot ) noexcept
{
  return
    Cbitset<N,T>( detail::array_ops<N,T>( n_rot ).rotate_left( bs.data() ) );
}


template<size_t N, class T>
constexpr
Cbitset<N,T>
rotate_right( Cbitset<N,T> const & bs, size_t n_rot ) noexcept
{
  return
    Cbitset<N,T>( detail::array_ops<N,T>( N - ( n_rot % N ) ).
                                               rotate_left( bs.data() ) );
}


/// Computes the set difference, i.e. bs1 & ~bs2
template<size_t N, class T>
constexpr
Cbitset<N,T>
difference( Cbitset<N,T> const & bs1, Cbitset<N,T> const & bs2 ) noexcept
{
  return
    Cbitset<N,T>( detail::array_funcs<Cbitset<N,T>::n_array,T>()
                            .bitwise_setdiff( bs1.data(), bs2.data() ) );
}


/// Returns bs with bits reversed
template<size_t N, class T>
constexpr
Cbitset<N,T>
reverse( Cbitset<N,T> const & bs ) noexcept
{ return Cbitset<N,T>( detail::array_ops<N,T>( 0 ).reverse( bs.data() ) ); }


/// Computes the two's complement
template<size_t N, class T>
constexpr
Cbitset<N,T>
complement2( Cbitset<N,T> const & bs ) noexcept
{ return Cbitset<N,T>( detail::array_complement2<N,T>().comp2(bs.data()) ); }


/// Converts an M-bit Cbitset to an N-bit Cbitset.
template<size_t N,class T1,size_t M, class T2>
constexpr
Cbitset<N,T1>
convert_to( Cbitset<M,T2> const & bs ) noexcept
{
  using a2a=
    detail::array2array<Cbitset<N,T1>::n_array,Cbitset<M,T2>::n_array,T1,T2>;
  return
    Cbitset<N,T1>(a2a()(detail::bit_chars<N,T1>::hgh_bit_pattern, bs.data()));
}


/// Converts an M-bit Cbitset to an N-bit Cbitset.
template<size_t N,size_t M, class T>
constexpr
Cbitset<N,T>
convert_to( Cbitset<M,T> const & bs ) noexcept
{ return Cbitset<N,T>( bs.data() ); }


/// \brief Returns true if f returns true for each pair
/// of base_t=T values in bs1 and bs2. f should be a binary function
/// taking two base_t values and returning bool.
/// zip_fold_and does short circuit if possible.
template<size_t N, class F, class T>
constexpr
bool
zip_fold_and( Cbitset<N,T> const & bs1, Cbitset<N,T> const & bs2,
              F f ) noexcept(noexcept( f( T(0), T(0) ) ))
{
  return
    detail::array_funcs<Cbitset<N,T>::n_array,T>().zip_fold_and(bs1.data(),
                                                                bs2.data(), f);
}


/// \brief Returns true if f returns true for at least one pair
/// of base_t=T values in bs1 and bs2. f should be a binary function
/// taking two base_t values and returning bool.
/// zip_fold_or does short circuit if possible.
template<size_t N, class F,class T>
constexpr
bool
zip_fold_or( Cbitset<N,T> const & bs1, Cbitset<N,T> const & bs2,
             F f ) noexcept(noexcept( f( T(0), T(0) ) ))
{
  return
    detail::array_funcs<Cbitset<N,T>::n_array,T>().zip_fold_or( bs1.data(),
                                                                bs2.data(), f );
}


} // namespace cbitset




/// Stream output
template <class CharT, class Traits, size_t N,class T>
std::basic_ostream<CharT, Traits>&
operator<<( std::basic_ostream<CharT, Traits> & os,
            cbitset::Cbitset<N,T> const & x )
{
  for( size_t ct= N; ct > 0; )
  {
     --ct;
     os << ( x[ct] ? "1" : "0" );
  }
  return os;
}

/// Stream input
template <class CharT, class Traits, size_t N,class T>
std::basic_istream<CharT, Traits>&
operator>>( std::basic_istream<CharT, Traits> & is,
            cbitset::Cbitset<N,T> & x )
{
  std::bitset<N>  bs;
  is >> bs;
  x= cbitset::Cbitset<N,T>( bs );
  return is;
}



/// Shift left
template<size_t N,class T>
constexpr
cbitset::Cbitset<N,T>
operator<<( cbitset::Cbitset<N,T> const & bs, size_t n_shift ) noexcept
{
  return
    cbitset::Cbitset<N,T>( cbitset::detail::array_ops<N,T>( n_shift )
                                                 .shift_left( bs.data() ) );
}


/// Shift right
template<size_t N,class T>
constexpr
cbitset::Cbitset<N,T>
operator>>( cbitset::Cbitset<N,T> const & bs, size_t n_shift ) noexcept
{
  return
    cbitset::Cbitset<N,T>( cbitset::detail::array_ops<N,T>( n_shift )
                                                 .shift_right( bs.data() ) );
}


template<size_t N,class T>
constexpr
cbitset::Cbitset<N,T>
operator|( cbitset::Cbitset<N,T> const & bs1,
           cbitset::Cbitset<N,T> const & bs2 ) noexcept
{
  return
    cbitset::Cbitset<N,T>(
      cbitset::detail::array_funcs<cbitset::Cbitset<N,T>::n_array,T>()
                                    .bitwise_or( bs1.data(), bs2.data() ) );
}


template<size_t N,class T>
constexpr
cbitset::Cbitset<N,T>
operator&( cbitset::Cbitset<N,T> const & bs1,
           cbitset::Cbitset<N,T> const & bs2 ) noexcept
{
  return
    cbitset::Cbitset<N,T>(
      cbitset::detail::array_funcs<cbitset::Cbitset<N,T>::n_array,T>()
                                  .bitwise_and( bs1.data(), bs2.data() ) );
}


template<size_t N,class T>
constexpr
cbitset::Cbitset<N,T>
operator^( cbitset::Cbitset<N,T> const & bs1,
           cbitset::Cbitset<N,T> const & bs2 ) noexcept
{
  return
    cbitset::Cbitset<N,T>(
      cbitset::detail::array_funcs<cbitset::Cbitset<N,T>::n_array,T>()
                                 .bitwise_xor( bs1.data(), bs2.data() ) );
}


template<size_t N,class T>
constexpr
cbitset::Cbitset<N,T>
operator+( cbitset::Cbitset<N,T> const & bs1,
           cbitset::Cbitset<N,T> const & bs2 ) noexcept
{
  return
    cbitset::Cbitset<N,T>(
      cbitset::detail::array_add<N,T>().add( bs1.data(), bs2.data() ) );
}


namespace std
{
  template<size_t N,class T>
  struct hash<cbitset::Cbitset<N,T> >
  {
  private:
    enum : size_t
    { n_array= cbitset::detail::Cbitset_impl<N,T>::n_array };

    cbitset::detail::hash_impl<n_array,T>   m_func;

  public:
    using argument_type= cbitset::Cbitset<N,T>;
    using result_type=
          typename cbitset::detail::hash_impl<n_array,T>::result_type;

    result_type operator()( argument_type const& bs ) const
    { return m_func( bs.data() ); }
  }; // struct hash

} // namespace std


#endif // BITSET2_CB_HPP
