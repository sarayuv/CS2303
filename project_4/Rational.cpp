#include "Rational.h"
#include <iostream>

// Constructors
Rational::Rational(const int n, const int d)
{
    num = n;
    denom = d;

    simplify(num, denom);
}

Rational::Rational(const int wholeNum)
{
    num = wholeNum;
    denom = 1;
}

Rational::Rational(const Rational &a)
{
    num = a.num;
    denom = a.denom;

    simplify(num, denom);
}

/*******************************************************************************
 * int Rational::gcd(int a, int b){
 * Calculates the greatest common denominator between two ints
 * Parameters:
 *  Int a
 *  Int b
 * Output:
 *   Returns the gcd
 ********************************************************************************/
int Rational::gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

/*******************************************************************************
 * void Rational::simplify(int &num, int &denom){
 * Stores the Rational's numerator and denominator in simplest form
 * Parameters:
 *  Int reference num
 *  Int reference denom
 ********************************************************************************/
void Rational::simplify(int &num, int &denom)
{
    int theGcd = gcd(num, denom);
    if (theGcd != 0)
    {
        num = num / theGcd;
        denom = denom / theGcd;
    }
}

/*******************************************************************************
 * int Rational::getNumerator() const {
 * Accesses the numerator of a Rational
 * Output:
 *   Returns num
 ********************************************************************************/
int Rational::getNumerator() const
{
    return num;
}

/*******************************************************************************
 * int Rational::getDenominator() const {
 * Accesses the denominator of a Rational
 * Output:
 *   Returns denom
 ********************************************************************************/
int Rational::getDenominator() const
{
    return denom;
}

/*******************************************************************************
 * Rational Rational::operator+(const Rational &a) {
 * Overloads the + operator for Rationals
 * Parameters:
 *   immutable reference to Rational a
 * Output:
 *   Returns Rational
 ********************************************************************************/
Rational Rational::operator+(const Rational &a)
{
    int common_denom = denom * a.denom;
    int new_num = (a.num * denom) + (num * a.denom);
    int new_denom = common_denom;
    return Rational(new_num, new_denom);
}

/*******************************************************************************
 * Rational Rational::operator-(const Rational &a) {
 * Overloads the - operator for Rationals
 * Parameters:
 *   immutable reference to Rational a
 * Output:
 *   Returns Rational
 ********************************************************************************/
Rational Rational::operator-(const Rational &a)
{
    int common_denom = denom * a.denom;
    int new_num = (a.num * denom) - (num * a.denom);
    int new_denom = common_denom;
    return Rational(new_num, new_denom);
}

/*******************************************************************************
 * Rational Rational::operator*(const Rational &a) {
 * Overloads the * operator for Rationals
 * Parameters:
 *   immutable reference to Rational a
 * Output:
 *   Returns Rational
 ********************************************************************************/
Rational Rational::operator*(const Rational &a)
{
    int new_num = num * a.num;
    int new_denom = denom * a.denom;
    return Rational(new_num, new_denom);
}

/*******************************************************************************
 * Rational Rational::operator/(const Rational &a) {
 * Overloads the / operator for Rationals
 * Parameters:
 *   immutable reference to Rational a
 * Output:
 *   Returns Rational
 ********************************************************************************/
Rational Rational::operator/(const Rational &a)
{
    int new_num = num * a.denom;
    int new_denom = denom * a.num;
    return Rational(new_num, new_denom);
}

/*******************************************************************************
 * bool Rational::operator==(const Rational &a) {
 * Overloads the == operator for Rationals
 * Parameters:
 *   immutable reference to Rational a
 * Output:
 *   Returns a bool
 ********************************************************************************/
bool Rational::operator==(const Rational &a)
{
    if ((num * a.denom) == (denom * a.num))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*******************************************************************************
 * bool Rational::operator!=(const Rational &a) {
 * Overloads the != operator for Rationals
 * Parameters:
 *   immutable reference to Rational a
 * Output:
 *   Returns a bool
 ********************************************************************************/
bool Rational::operator!=(const Rational &a)
{
    if ((num * a.denom) != (denom * a.num))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*******************************************************************************
 * bool Rational::operator<(const Rational &a) {
 * Overloads the < operator for Rationals
 * Parameters:
 *   immutable reference to Rational a
 * Output:
 *   Returns a bool
 ********************************************************************************/
bool Rational::operator<(const Rational &a)
{
    return (num * a.denom) < (a.num * denom);
}

/*******************************************************************************
 * bool Rational::operator>(const Rational &a) {
 * Overloads the > operator for Rationals
 * Parameters:
 *   immutable reference to Rational a
 * Output:
 *   Returns a bool
 ********************************************************************************/
bool Rational::operator>(const Rational &a)
{
    return (num * a.denom) > (a.num * denom);
}

/*******************************************************************************
 * bool Rational::operator>=(const Rational &a) {
 * Overloads the >= operator for Rationals
 * Parameters:
 *   immutable reference to Rational a
 * Output:
 *   Returns a bool
 ********************************************************************************/
bool Rational::operator>=(const Rational &a)
{
    if (((num * a.denom) > (a.num * denom)) || ((num * a.denom) == (denom * a.num)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*******************************************************************************
 * bool Rational::operator<=(const Rational &a) {
 * Overloads the <= operator for Rationals
 * Parameters:
 *   immutable reference to Rational a
 * Output:
 *   Returns a bool
 ********************************************************************************/
bool Rational::operator<=(const Rational &a)
{
    if (((num * a.denom) < (a.num * denom)) || ((num * a.denom) == (denom * a.num)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*******************************************************************************
 * istream &operator>>(istream &in1, Rational &a) {
 * Overloads the >> operator for Rationals
 * Parameters:
 *   reference to input stream in1
 *   reference to Rational a
 * Output:
 *   Returns an input stream
 ********************************************************************************/
istream &operator>>(istream &in1, Rational &a)
{
    int num1, denom2;
    string frac1;
    string delimiter = "/";
    in1 >> frac1;
    int end = frac1.find(delimiter, 0);
    if (end > 0)
    {
        num1 = std::stoi((frac1.substr(0, end)));
        denom2 = std::stoi(frac1.substr(end + 1, frac1.size()));
        a.simplify(num1, denom2);
        a.num = num1;
        a.denom = denom2;
    }
    else
    {
        if (frac1.size())
        {
            a.num = std::stoi((frac1));
            a.denom = 1;
        }
    }
    return in1;
}

/*******************************************************************************
 * ostream &operator<<(ostream &out, const Rational &a) {
 * Overloads the << operator for Rationals
 * Parameters:
 *   reference to output stream out
 *   reference to immutable Rational a
 * Output:
 *   Returns an output stream
 ********************************************************************************/
ostream &operator<<(ostream &out, const Rational &a)
{
    if (a.denom == 1)
    {
        out << a.num;
    }
    else
    {
        out << a.num << "/" << a.denom;
    }
    return out;
}
