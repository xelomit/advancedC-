#ifndef FRACTION
#define FRACTION

#include <iostream>

int gcf(int a, int b) {
    return b == 0 ? a : gcf(b, a % b);
}

int lcm(int a, int b) {
    return (a*b) / gcf(a, b);
}

class fraction {
    int c;
    int d;

public:
    fraction(int cntr=0, int denom=1) : c(cntr), d(denom) {}

    int get_counter()  {
        return c;
    }

    int get_denominator()  {
        return d;
    }

    fraction operator+(fraction b){
        int denom = lcm(d, b.get_denominator());
        int count = (c*denom/d) + (b.get_counter()*denom/b.get_denominator());

        return fraction(count, denom);
    }

    fraction operator-(fraction b){
        fraction subtrahend = fraction (0-b.get_counter(), b.get_denominator());

        return subtrahend + (*this);
    }

    fraction operator*(fraction b) {
        int f1 = gcf(c, b.get_denominator());
        int f2 = gcf(b.get_counter(), d);

        return fraction((c/f1) * (b.c/f2),
                        (d/f2) * (b.d/f1));
    }

    fraction operator/(fraction bRev) {
        fraction b = fraction(bRev.get_denominator(), bRev.get_counter());
        return (*this) * b;
    }

    bool operator<(const fraction b){
      int dnm = lcm(d, b.d);
      return c * dnm / d < b.c * dnm / b.d;
    }

    bool operator>(const fraction b){
      int dnm = lcm(d, b.d);
      return c * dnm / d > b.c * dnm / b.d;
    }

    friend std::ostream &operator<<(std::ostream &os, fraction f) {
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

    friend std::istream &operator>>(std::istream &is, fraction &f) {
        fraction g;
        check_char(is, '('); is >> g.c;
        check_char(is, '/'); is >> g.d;
        check_char(is, ')');

        if (is) f=g;
        return is;
    }
};

#endif