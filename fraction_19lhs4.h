/*
 *
 *      Liam Salass
 *      20229595
 *
 */
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

class ZeroDenominator : public std::exception {
public:
    char *what();
};

class Fraction {
private:
    int num;
    int den;
    int find_gcd(int, int);
    void reduce_fraction(int, int);
public:
    Fraction();

    Fraction(int);

    Fraction(int, int);

    std::string to_string();

    int numerator();

    int denominator();

    //Unary Arithmatic
    //void operator -() const; //negation
    void operator ++() const; //++ prefix
    void operator ++(int) const;//++ postfix

    //Binary Arithmatic
    Fraction& operator +(const Fraction&);
    Fraction& operator -(const Fraction&);
    Fraction& operator *(const Fraction&);
    Fraction& operator /(const Fraction&);

    //Addition and assignment
    Fraction& operator +=(const Fraction&);

    //Comparison operators
    friend bool operator < (const Fraction&,const Fraction&);
    friend bool operator <= (const Fraction&,const Fraction&);
    friend bool operator == (const Fraction&,const Fraction&);
    friend bool operator != (const Fraction&,const Fraction&);
    friend bool operator >= (const Fraction&,const Fraction&);
    friend bool operator > (const Fraction&,const Fraction&);

    //input output stream
    friend ostream& operator << (ostream, const Fraction&);
    friend istream& operator >> (istream, const Fraction&);














};


