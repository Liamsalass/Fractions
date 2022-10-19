/*
 *
 *      Liam Salass
 *      20229595
 *
 */
#include "fraction_19lhs4.h"

using namespace std;

char *ZeroDenominator::what() {
    return (char *) "Zero Denominator";
}

Fraction::Fraction() {
    num = 0, den = 1;
};

Fraction::Fraction(int n) {
    num = n, den = 1;
};

Fraction::Fraction(int n, int d) {
    num = n, den = d;
}


