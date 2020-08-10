#ifndef FE_POINT_H
#define FE_POINT_H

#include <vector>
#include <numeric>

#include "utils/fp.h"

namespace fe
{
  template<std::size_t n, typename T>
  struct point
  {
    enum : std::size_t { dimension = n };

    struct point_tag;

    std::vector<T> impl;

    using const_iterator = typename std::vector<T>::const_iterator;
    using value_type = typename std::vector<T>::value_type;

    point(): impl(n, T()) {}
    explicit point(T t): impl(n, t) {}
    point(point&&) = default;
    point(const point&) = default;
    point& operator=(const point&) = default;
    point& operator=(point&&) = default;

    template<typename ArgType0, typename ...ArgTypes>
    constexpr point(ArgType0&& arg0, ArgTypes&&... args);

    template<typename F>
    constexpr point(F&& f, typename std::enable_if
      <
        std::is_invocable<F, point&, std::size_t>::value,
        void
      >::type* = nullptr):
      point{}
    {
      write(*this, std::forward<F>(f));
    }

    constexpr T& operator[](std::size_t i)              { return impl[i]; }
    constexpr const T& operator[](std::size_t i)  const { return impl[i]; }

    static constexpr std::size_t size()         { return n; }
    const_iterator cbegin() const               { return impl.cbegin(); }
    const_iterator cend() const                 { return impl.cend(); }

    template<typename F>
    static constexpr void write(point& p, F&& f);

    template<typename ArgType0, typename ...ArgTypes>
    static constexpr void write(point& p, ArgType0&& arg0, ArgTypes&&... args);

  public:
    static constexpr point nan()  { return point(fp::constants::nan<T>); }
    static constexpr point zero() { return point((T)0); }
    static constexpr point one()  { return point((T)1); }
  };


  namespace impl
  {
    template<typename P, typename F, std::size_t ...Indices>
    constexpr void write(P& p, F&& f, std::index_sequence<Indices...>)
    {
      ( f(p, std::integral_constant<std::size_t, Indices>{}), ... );
    }
    template<typename P, typename ...ArgTypes, std::size_t ...Indices>
    constexpr void write(P& p, std::index_sequence<Indices...>, ArgTypes&&... args)
    {
      ( ( p[std::integral_constant<std::size_t, Indices>{}] = (typename P::value_type)(std::forward<ArgTypes>(args)) ), ... );
    }
  }

  template<std::size_t n, typename T>
  template<typename F>
  constexpr void point<n, T>::write(point<n, T>& p, F&& f)
  {
    impl::write(p, f, std::make_index_sequence<n>{});
  }

  template<std::size_t n, typename T>
  template<typename ArgType0, typename ...ArgTypes>
  constexpr void point<n, T>::write(point<n, T>& p, ArgType0&& arg0, ArgTypes&&... args)
  {
    impl::write(p, std::make_index_sequence<n>{}, std::forward<ArgType0>(arg0), std::forward<ArgTypes>(args)...);
  }

  template<std::size_t n, typename T>
  template<typename ArgType0, typename ...ArgTypes>
  constexpr point<n, T>::point(ArgType0&& arg0, ArgTypes&&... args): point(fp::constants::nan<T>)
  {
    using value_type = typename std::remove_cv<typename std::remove_reference<ArgType0>::type>::type;

    // construct from `point` instance
    if constexpr(sizeof ...(args) == 0 && std::is_same<value_type, point>::value)
    {
      write(*this, [&arg0](auto& impl, std::size_t i){ impl[i] = arg0[i]; });
    }

    // construct from component sequence
    else
    {
      static_assert(sizeof ...(args) == n - 1);
      write(*this, std::forward<ArgType0>(arg0), std::forward<ArgTypes>(args)...);
    }
  }

  template<std::size_t n, typename T>
  double distance_sq(const point<n, T>& a, const point<n, T>& b)
  {
    double acc = 0.;
    for(std::size_t i=0; i<n; ++i)
    {
      const double di = a[i] - b[i];
      acc += di * di;
    }

    return acc;
  }

  template<std::size_t n, typename T>
  double norm_sq(const point<n, T>& a)
  {
    return std::accumulate(a.cbegin(), a.cend(), 0., [](const T& acc, const T& t) { return acc + t*t; });
  }

  template<std::size_t n, typename T>
  double norm_1(const point<n, T>& a)
  {
    return std::accumulate(a.cbegin(), a.cend(), 0., [](const T& acc, const T& t) { return acc + (t < 0 ? -t : t); });
  }

}

#endif

