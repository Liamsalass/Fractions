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

    void reduce_fraction();
public:
    Fraction();
    Fraction(int);
    Fraction(int, int);

    int find_gcd(int, int);

    int getNum() const;
    int getDen() const;

    //Addition and assignment
    Fraction& operator += (const Fraction& frac);
    Fraction& operator += (const int& i);

    //Unary Arithmatic
    Fraction& operator -(); //negation
    Fraction& operator ++(); //++ prefix
    Fraction& operator ++(int); //++ suffix
//++ postfix

};


//Binary Arithmatic
Fraction operator +(const Fraction& lhs, const Fraction& rhs);
Fraction operator +(const int& i, const Fraction& rhs);
Fraction operator +(const Fraction& lhs, const int& i);
Fraction operator -(const Fraction& lhs, const Fraction& rhs);
Fraction operator -(const int& i, const Fraction& rhs);
Fraction operator -(const Fraction& lhs, const int& i);
Fraction operator *(const Fraction& lhs, const Fraction& rhs);
Fraction operator *(const int& i, const Fraction& rhs);
Fraction operator *(const Fraction& lhs, const int& i);
Fraction operator /(const Fraction& lhs, const Fraction& rhs) ;
Fraction operator /(const int& i, const Fraction& rhs);
Fraction operator /(const Fraction& lhs, const int& i);



//Comparison operators
bool operator < (const Fraction&,const Fraction&);
bool operator < (const int& i,const Fraction&);
bool operator < (const Fraction&,const int& i);
bool operator <= (const Fraction&,const Fraction&);
bool operator <= (const int& i,const Fraction&);
bool operator <= (const Fraction&,const int& i);
bool operator == (const Fraction&,const Fraction&);
bool operator == (const int& i,const Fraction&);
bool operator == (const Fraction&,const int& i);
bool operator != (const Fraction&,const Fraction&);
bool operator != (const int& i,const Fraction&);
bool operator != (const Fraction&,const int& i);
bool operator >= (const Fraction&,const Fraction&);
bool operator >= (const int& i,const Fraction&);
bool operator >= (const Fraction&,const int& i);
bool operator > (const Fraction&,const Fraction&);
bool operator > (const int& i,const Fraction&);
bool operator > (const Fraction&,const int& i);

//input output stream
ostream& operator << (ostream& out, const Fraction& frac);
istream& operator >> (istream& out, const Fraction& frac);

