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

//Exception classes for zero denominators and if an incorrect fraction is entered.
char *FractionException::what() {
    return (char *) "Zero Denominator";
}
char *InputException::what() {
    return (char *) "Incorrect Fraction entered";
}

//Constructors
Fraction::Fraction(){
    num = 0;
    den = 1;
}
Fraction::Fraction(int n) {
    num = n;
    den = 1;
}
Fraction::Fraction(int n, int d) {
    if (d==0) throw FractionException();
    if (d<0){
        d *= -1;
        n *= -1;
    }
    num = n;
    den = d;
    reduce_fraction();
}

//Getters
int Fraction::numerator() const{ return num;}
int Fraction::denominator() const{ return den;}

//GCD function
int Fraction::find_gcd(int a, int b) const{
    if (b<= a && (a%b)==0)
        return b;
    else if (a < b) return find_gcd(b, a);
    else return find_gcd(b, a%b);
}

//Function to reduce the fraction
void Fraction::reduce_fraction() {
    int neg = 1;
    if (num == 0) return;
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
Fraction Fraction::operator++(int n) {
    Fraction temp(num, den);
    ++*this;
    return temp;
}


//Addition operator overload functions. Works with ints or fractions on either side.
Fraction operator+(const Fraction& left, const Fraction& right){
    if (right.denominator() == left.denominator()) return Fraction (left.numerator() + right.numerator(), right.denominator());
    else{
        Fraction newFrac(left.numerator() * right.denominator() + left.denominator() * right.numerator(), left.denominator() * right.denominator());
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
    if (right.denominator() == left.denominator()) return Fraction (left.numerator() - right.numerator(), right.denominator());
    else{
        Fraction newFrac(left.numerator() * right.denominator() - left.denominator() * right.numerator(), left.denominator() * right.denominator());
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
    return Fraction(left.numerator() * right.numerator(), left.denominator() * right.denominator());
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
    return Fraction(left.numerator()*right.denominator(),left.denominator()*right.numerator());
}
Fraction operator/(const int& i, const Fraction& rhs){
    Fraction temp(i);
    return rhs/temp;
}
Fraction operator/(const Fraction& lhs, const int& i){
    Fraction temp(i);
    return lhs/temp;
}

//Comparison operators
bool operator < (const Fraction& lhs, const Fraction& rhs){
    Fraction temp(1,1);
    temp = rhs - lhs;
    if (temp.numerator()<=0) return false;
    else return true;
}
bool operator < (const int& i, const Fraction& rhs){
    Fraction temp(1,1);
    temp = rhs - i;
    if (temp.numerator()<=0) return false;
    else return true;
}
bool operator < (const Fraction& lhs, const int& i){
    Fraction temp(1,1);
    temp = i - lhs;
    if (temp.numerator()<=0) return false;
    else return true;
}
bool operator <= (const Fraction& lhs, const Fraction& rhs){
    Fraction temp(1,1);
    temp = rhs - lhs;
    if (temp.numerator()<0) return false;
    else return true;
}
bool operator <= (const int& i, const Fraction& rhs){
    Fraction temp(1,1);
    temp = rhs - i;
    if (temp.numerator()<0) return false;
    else return true;
}
bool operator <= (const Fraction& lhs, const int& i){
    Fraction temp(1,1);
    temp = i - lhs;
    if (temp.numerator()<0) return false;
    else return true;
}
bool operator == (const Fraction& lhs, const Fraction& rhs){
    Fraction temp;
    temp = lhs - rhs;
    if (temp.numerator()!=0) return false;
    else return true;
}
bool operator == (const int& i, const Fraction& rhs){
    Fraction temp(1,1);
    temp = i - rhs;
    if (temp.numerator()!=0) return false;
    else return true;
}
bool operator == (const Fraction& lhs, const int& i){
    Fraction temp(1,1);
    temp = lhs - i;
    if (temp.numerator()!=0) return false;
    else return true;
}
bool operator != (const Fraction& lhs, const Fraction& rhs){
    Fraction temp(1,1);
    temp = lhs - rhs;
    if (temp.numerator()==0) return false;
    else return true;
}
bool operator != (const int& i, const Fraction& rhs){
    Fraction temp(1,1);
    temp = i - rhs;
    if (temp.numerator()==0) return false;
    else return true;
}
bool operator != (const Fraction& lhs, const int& i){
    Fraction temp(1,1);
    temp = lhs - i;
    if (temp.numerator()==0) return false;
    else return true;
}
bool operator >= (const Fraction& lhs, const Fraction& rhs){
    Fraction temp(1,1);
    temp = lhs - rhs;
    if (temp.numerator()<0) return false;
    else return true;
}
bool operator >= (const int& i, const Fraction& rhs){
    Fraction temp(1,1);
    temp = i - rhs;
    if (temp.numerator()<0) return false;
    else return true;
}
bool operator >= (const Fraction& lhs, const int& i){
    Fraction temp(1,1);
    temp = lhs - i;
    if (temp.numerator()<0) return false;
    else return true;
}
bool operator > (const Fraction& lhs, const Fraction& rhs){
    Fraction temp(1,1);
    temp = lhs - rhs;
    if (temp.numerator()<=0) return false;
    else return true;
}
bool operator > (const int& i, const Fraction& rhs){
    Fraction temp(1,1);
    temp = i - rhs;
    if (temp.numerator()<=0) return false;
    else return true;
}
bool operator > (const Fraction& lhs, const int& i){
    Fraction temp(1,1);
    temp = lhs - i;
    if (temp.numerator()<=0) return false;
    else return true;
}

//out stream operator overload method
ostream& operator<<(ostream& out, const Fraction& frac){
    out << frac.numerator() << '/' << frac.denominator();
    return out;
}

//in stream operator overload method
istream& operator >> (istream &input, Fraction& frac){
    string is;
    input >> is; // store the user input in is

    size_t slash = is.find('/'); //Used to find index of slash in input string

    if (slash == string::npos){ //If no / is used, the case that a whole number is entered.
        try{
            int n = stoi(is);
            frac = Fraction(n);
            return input;
        } catch (exception& e){}
        throw InputException();
    } else {
        if (slash + 1 >= is.size()){ //In the case the slash is at the end but nothing else is entered after.
            throw InputException();
        }
        try { //Store numerator and denominator left and right of the slash in the string is.
            int n =stoi(is.substr(0,slash));
            int d = stoi(is.substr(slash + 1, is.size() - slash - 1));
            frac = Fraction(n, d); //set frac to the new fraction
            return input;
        } catch (exception& e){
            throw InputException();
        }
    }
}