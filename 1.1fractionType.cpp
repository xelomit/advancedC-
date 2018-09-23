//
// Created by timo on 22.09.18.
//

#include <iostream>

using namespace std;

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

    friend ostream &operator<<(ostream &os, fraction f) {
        os << '(' << f.get_counter() << '/' << f.get_denominator() << ')';
    }

    static void check_char(istream &is, char ch) {
        char c;
        is >> c;
        if(c!=ch) {
            is.putback(c);
            is.setstate(ios::badbit);
        }
    }

    friend istream &operator>>(istream &is, fraction &f) {
        fraction g;
        check_char(is, '('); is >> g.c;
        check_char(is, '/'); is >> g.d;
        check_char(is, ')');

        if (is) f=g;
        return is;
    }
};

void staticExample(){
    cout << "Welcome! The following example is based on the following two fractions:" << endl;

    fraction fr1 = fraction(12, 9);
    fraction fr2 = fraction(7, 3);

    cout << "fraction 1: " << fr1 << endl;
    cout << "fraction 2: " << fr2 << endl;

    cout << endl;

    cout << "Addition: " << endl;
    cout << fr1 << " + " << fr2 << " = " << fr1 + fr2 << endl;

    cout << endl;


    cout << "Subtraction: " << endl;
    cout << fr1 << " - " << fr2 << " = " << fr1 - fr2 << endl;

    cout << endl;

    cout << "Addition: " << endl;
    cout << fr1 << " + " << fr2 << " = " << fr1 + fr2 << endl;

    cout << endl;

    cout << "Multiplication: " << endl;
    cout << fr1 << " * " << fr2 << " = " << fr1 * fr2 << endl;

    cout << endl;

    cout << "Division: " << endl;
    cout << fr1 << " / " << fr2 << " = " << fr1 / fr2 << endl;
}


void interactiveExample(char operation){
    fraction fr1;
    fraction fr2;

    cout << "Please, enter a 1st fraction in format (int/int): ";
    cin >> fr1;
    cout << "Please, enter a 2nd fraction: in format (int/int): ";
    cin >> fr2;
    cout << endl;
    cout << "1st fraction: " << fr1 << endl;
    cout << "2nd fraction: " << fr2 << endl;
    cout << endl;
    cout << "Operation result: " << endl;
    cout << endl;

    switch(operation) {
        case 'a':
            cout << fr1 << " + " << fr2 << " = " << fr1 + fr2 << endl;
            break;

        case 's':
            cout << fr1 << " - " << fr2 << " = " << fr1 - fr2 << endl;
            break;

        case 'm':
            cout << fr1 << " * " << fr2 << " = " << fr1 * fr2 << endl;
            break;

        case 'd':
            cout << fr1 << " / " << fr2 << " = " << fr1 / fr2 << endl;
            break;

        default: cout << "Unknown operation, please specify next time." << endl;
    }
}

void printDisclaimer() {
    cout << "Welcome to the fraction calculator!" << endl;
    cout << endl;
    cout << "Usage: " << endl;
    cout << "-   For running a static demonstration, enter param 's'." << endl;
    cout << "-   For running an demonstration example, enter param 'i' as well as a 2nd param for the operation, i.e. "
               "'a' for addition, 's' for subtraction, 'm' for multiplication and 'd' for division." << endl;
    cout << endl;
    cout <<"Examples: "<< endl;
    cout <<" - $ ./1.1fractionType s"<< endl;
    cout <<" - $ ./1.1fractionType i m"<< endl;
    cout << endl;
}

int main(int argc, char** argv) {

    if(argc > 1) {
        switch (*argv[1]) {
            case 's':
                staticExample();
                break;
            case 'i':
                interactiveExample(*argv[2]);
                break;
            default: printDisclaimer();
        }
    }

    if(argc == 1) printDisclaimer();
    return 0;
};
