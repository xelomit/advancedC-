//
// Created by timo on 25.10.18.
//

#ifndef INC_1_1FRACTIONTYPE_FRACTION_H
#define INC_1_1FRACTIONTYPE_FRACTION_H

#include <iostream>

class fraction {
    int c;
    int d;

public:
    fraction(int cntr=0, int denom=1);

    int get_counter();

    int get_denominator();

    fraction operator+(fraction b);

    fraction operator-(fraction b);

    fraction operator*(fraction b);

    fraction operator/(fraction bRev);


    friend std::ostream &operator<<(std::ostream &os, fraction f);
    friend std::istream &operator>>(std::istream &is, fraction &f);

};

#endif //INC_1_1FRACTIONTYPE_FRACTION_H
