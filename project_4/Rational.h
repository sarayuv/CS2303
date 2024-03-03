#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::ostream;
using std::string;

class Rational
{
public:
    Rational() = default;
    Rational(const int n, const int d);
    Rational(const int wholeNum);
    Rational(const Rational &a);
    int gcd(int a, int b);
    void simplify(int &n, int &d);

    int getNumerator() const;
    int getDenominator() const;
    Rational operator+(const Rational &a);
    Rational operator-(const Rational &a);
    Rational operator*(const Rational &a);
    Rational operator/(const Rational &a);
    bool operator==(const Rational &a);
    bool operator!=(const Rational &a);

    bool operator<(const Rational &a);
    bool operator>(const Rational &a);
    bool operator>=(const Rational &a);
    bool operator<=(const Rational &a);

    friend ostream &operator<<(ostream &out, const Rational &a);
    friend istream &operator>>(istream &out, Rational &a);

private:
    int num;
    int denom;
};
