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

struct gcd_constexpr {

    constexpr int gcd(int a, int b) {
        if (b==0) return a;
        return gcd(b, a%b);
    }

};

#endif //L5_4METAPROGRAMMING_GCD_META_H
