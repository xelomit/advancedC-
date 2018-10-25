//
// Created by timo on 25.10.18.
//

#include "fraction.h"
#include <iostream>

int gcf(int a, int b) {
    return b == 0 ? a : gcf(b, a % b);
}

int lcm(int a, int b) {
    return (a*b) / gcf(a, b);
}

fraction::fraction(int cntr, int denom) : c(cntr), d(denom) {}

int fraction::get_counter()  {
    return c;
}

int fraction::get_denominator()  {
    return d;
}

fraction fraction::operator+(fraction b){
    int denom = lcm(d, b.get_denominator());
    int count = (c*denom/d) + (b.get_counter()*denom/b.get_denominator());

    return fraction(count, denom);
}

fraction fraction::operator-(fraction b){
    fraction subtrahend = fraction (0-b.get_counter(), b.get_denominator());

    return subtrahend + (*this);
}

fraction fraction::operator*(fraction b) {
    int f1 = gcf(c, b.get_denominator());
    int f2 = gcf(b.get_counter(), d);

    return fraction((c/f1) * (b.c/f2),
                    (d/f2) * (b.d/f1));
}

fraction fraction::operator/(fraction bRev) {
    fraction b = fraction(bRev.get_denominator(), bRev.get_counter());
    return (*this) * b;
}

std::ostream &operator<<(std::ostream &os, fraction f) {
    os << '(' << f.get_counter() << '/' << f.get_denominator() << ')';
}

inline static void check_char(std::istream &is, char ch) {
    char c;
    is >> c;
    if(c!=ch) {
        is.putback(c);
        is.setstate(std::ios::badbit);
    }
}

std::istream &operator>>(std::istream &is, fraction &f) {
    fraction g;
    check_char(is, '('); is >> g.c;
    check_char(is, '/'); is >> g.d;
    check_char(is, ')');

    if (is) f=g;
    return is;
}
