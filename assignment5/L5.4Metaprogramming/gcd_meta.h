//
// Created by timo on 27.11.18.
//

#ifndef L5_4METAPROGRAMMING_GCD_META_H
#define L5_4METAPROGRAMMING_GCD_META_H

template <int A, int B>
struct gcd_meta {
    static const int gcd = gcd_meta<B, A%B>::gcd;
};

template <int A>
struct gcd_meta <A, 0> {
    static const int gcd = A;
};

#endif //L5_4METAPROGRAMMING_GCD_META_H
