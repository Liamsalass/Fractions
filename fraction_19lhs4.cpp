/*
 *
 *      Liam Salass
 *      20229595
 *
 */
#include "fraction_19lhs4.h"
#include <string>
#include<iostream>
#include <sstream>


using namespace std;

char *ZeroDenominator::what() {
    return (char *) "Zero Denominator";
}

Fraction::Fraction(){
    num = 0;
    den = 1;
}
Fraction::Fraction(int n) {
    num = n;
    den = 1;
}
Fraction::Fraction(int n, int d) {
    if (d<0){
        d = abs(d);
        n * -1;
    }
    num = n;
    den = d;
    reduce_fraction();
}

int Fraction::getNum() const{ return num;}
int Fraction::getDen() const{ return den;}

int Fraction::find_gcd(int a, int b){
    if (b<= a && (a%b)==0)
        return b;
    else if (a < b) find_gcd(b, a);
    else find_gcd(b, a%b);
}

void Fraction::reduce_fraction() {
    int neg = 1;
    if (num < 0) {
        neg = -1;
        num *= neg;
    }
    int gcd = find_gcd(num,den);
    if (gcd ==0) return;
    else {
        num /= gcd;
        den /= gcd;
    }
    num *= neg;
    return;
}

//+= operator functions for dealing with fractions and ints
Fraction& Fraction::operator +=(const Fraction& frac){
    *this = frac + *this;
    return *this;
}

Fraction& Fraction::operator +=(const int& i){
    Fraction temp(i);
    *this = temp + *this;
    return *this;
}


//Uniary Arithmatic operator overloads.
Fraction& Fraction::operator-() {
    num *= -1;
    return *this;
}

Fraction& Fraction::operator++() {
    num += den;
    return *this;
}

Fraction& Fraction::operator++(int n) {
    Fraction temp = *this;
    ++*this;
    return temp;
}


//Addition operator overload functions. Works with ints or fractions on either side.
Fraction operator+(const Fraction& left, const Fraction& right){
    if (right.getDen() == left.getDen()) return Fraction (left.getNum() + right.getNum(), right.getDen());
    else{
        Fraction newFrac(left.getNum() * right.getDen() + left.getDen() * right.getNum(), left.getDen() * right.getDen());
        return newFrac;
    }
}

Fraction operator+(const int& i, const Fraction& rhs){
    Fraction temp(i);
    return temp + rhs;
}

Fraction operator+(const Fraction& lhs, const int& i){
    Fraction temp(i);
    return temp + lhs;
}


//Subtraction operator overload
Fraction operator-(const Fraction& left, const Fraction& right){
    if (right.getDen() == left.getDen()) return Fraction (left.getNum() - right.getNum(), right.getDen());
    else{
        Fraction newFrac(left.getNum() * right.getDen() - left.getDen() * right.getNum(), left.getDen() * right.getDen());
        return newFrac;
    }
}

Fraction operator-(const int& i, const Fraction& rhs){
    Fraction temp(i);
    return temp - rhs;
}

Fraction operator-(const Fraction& lhs, const int& i){
    Fraction temp(i);
    return lhs - temp;
}


//Multiplication operator overload
Fraction operator*(const Fraction& left, const Fraction& right) {
    return Fraction(left.getNum() * right.getNum(), left.getDen() * right.getDen());
}

Fraction operator*(const int& i, const Fraction& rhs){
    Fraction temp(i);
    return temp * rhs;
}

Fraction operator*(const Fraction& lhs, const int& i){
    Fraction temp(i);
    return lhs * temp;
}

//Division operator overload funcitons.
Fraction operator/(const Fraction& left, const Fraction& right){
    return Fraction(left.getNum()*right.getDen(),left.getDen()*right.getNum());
}

Fraction operator/(const int& i, const Fraction& rhs){
    Fraction temp(i);
    return rhs/temp;
}

Fraction operator/(const Fraction& lhs, const int& i){
    Fraction temp(i);
    return lhs/temp;
}




ostream& operator<<(ostream& out, const Fraction& frac){
    out << frac.getNum() + "/" + frac.getDen();
    return out;
}



