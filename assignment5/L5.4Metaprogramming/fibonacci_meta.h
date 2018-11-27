//
// Created by timo on 27.11.18.
//

#ifndef L5_4METAPROGRAMMING_FIBONACCI_META_H
#define L5_4METAPROGRAMMING_FIBONACCI_META_H


template <int N>
struct fibonacci_meta {
    static const int fib = fibonacci_meta<N-1>::fib + fibonacci_meta<N-2>::fib;
};

template <>
struct fibonacci_meta <0> {
    static const int fib = 0;
};

template <>
struct fibonacci_meta <1> {
    static const int fib = 1;
};

#endif //L5_4METAPROGRAMMING_FIBONACCI_META_H
