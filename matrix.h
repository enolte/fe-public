#ifndef FE_MATRIX_H
#define FE_MATRIX_H

#include <vector>
#include <type_traits>

#include "utils/fp.h"

namespace fe
{
  template<std::size_t _nrows, std::size_t _ncols, typename T>
  struct matrix
  {
    struct matrix_tag;

    enum : std::size_t { nrows = _nrows, ncols = _ncols };

    using numeric_type = T;

  private:
    std::vector<T> impl;

  public:
    constexpr matrix(): impl(nrows * ncols, fp::constants::nan<T>) {}

    /*
     * Dense initialization
     *
     */
    constexpr matrix(std::initializer_list<std::initializer_list<numeric_type>>&& list);

    /*
     * Construct by evaluating a `void`-return function f(m, r, c)
     *
     */
    template<typename F, typename std::enable_if
      <
        std::is_invocable<F, matrix&, std::size_t, std::size_t>::value,
        void
      >::type* = nullptr>
    constexpr matrix(F&&);

    /*
     * Construct by evaluating a `T`-return function f : m[r][c] = f(r, c)
     *
     */
    template<typename F, typename std::enable_if
      <
        std::is_invocable<F, std::size_t, std::size_t>::value,
        void
      >::type* = nullptr>
    constexpr matrix(F&& f):
      matrix([&f](matrix& m, std::size_t r, std::size_t c) { m[r][c] = f(r, c); })
    {}

    /*
     * Copy from an arbitrary rank 2 object.
     *
     */
    template<typename M, typename std::enable_if
      <
        std::rank<typename std::remove_reference<M>::type>::value == 2,
        void
      >::type* = nullptr>
    constexpr matrix(M&&);

    matrix(const matrix&) = default;
    matrix(matrix&&) = default;

    matrix& operator=(const matrix&) = default;
    matrix& operator=(matrix&&) = default;

    struct row_reference
    {
      const std::size_t r;
      std::vector<T>& impl;
      constexpr T& operator[](std::size_t c) &&      { return impl[r*ncols + c]; }
      constexpr T operator[](std::size_t c) const && { return impl[r*ncols + c]; }
    };

    struct const_row_reference
    {
      const std::size_t r;
      const std::vector<T>& impl;
      constexpr T operator[](std::size_t c) const && { return impl[r*ncols + c]; }
    };

    constexpr row_reference operator[](std::size_t r)             { return {r, impl}; }
    constexpr const_row_reference operator[](std::size_t r) const { return {r, impl}; }
  };


  namespace impl
  {
    template<typename M, typename F, std::size_t ...Cs>
    constexpr void write(M& m, F&& f, std::size_t row, std::index_sequence<Cs...>)
    {
      ( f(m, row, std::integral_constant<std::size_t, Cs>{}), ... );
    }

    template<typename M, typename F, std::size_t ...Rs, std::size_t ...Cs>
    constexpr void write(M& m, F&& f, std::index_sequence<Rs...>&& rows, std::index_sequence<Cs...>&& cols)
    {
      ( write(m, f, std::integral_constant<std::size_t, Rs>{}, cols), ... );
    }

    template<std::size_t nrows, std::size_t ncols, typename M, typename F>
    constexpr void write(M& m, F&& f)
    {
      write(m, std::forward<F>(f), std::make_index_sequence<nrows>(), std::make_index_sequence<ncols>());
    }
  }

  template<std::size_t nrows, std::size_t ncols, typename T>
  template<typename F, typename std::enable_if
    <
      std::is_invocable<F, matrix<nrows, ncols, T>&, std::size_t, std::size_t>::value,
      void
    >::type*>
  constexpr matrix<nrows, ncols, T>::matrix(F&& f):
    matrix()
  {
    impl::write<nrows, ncols>(*this, std::forward<F>(f));
  }

  template<std::size_t nrows, std::size_t ncols, typename T>
  template<typename M, typename std::enable_if
    <
      std::rank<typename std::remove_reference<M>::type>::value == 2,
      void
    >::type*>
  constexpr matrix<nrows, ncols, T>::matrix(M&& _m):
    matrix
    {
      [&_m](auto&& m, std::size_t r, std::size_t c)
      {
        m[r][c] = _m[r][c];
      }
    }
  {}

  template<std::size_t nrows, std::size_t ncols, typename T>
  constexpr matrix<nrows, ncols, T>::matrix(std::initializer_list<std::initializer_list<numeric_type>>&& list)
  : matrix()
  {
    std::size_t r = 0, c = 0;
    for(auto ir = list.begin(); ir != list.end(); ++ir)
    {
      c = 0;
      for(auto irc = ir->begin(); irc != ir->end(); ++irc)
      {
        impl[ncols * r + c] = *irc;
        ++c;
      }
      ++r;
    }
  }

}


#endif


