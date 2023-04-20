#include "Fraction.hpp"
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <sstream>

using namespace ariel;
Fraction doubleToFraction(double d);
bool hasMoreThanThreeDigitsAfterDecimal(double num) {
    double intPart;
    num = num *1000;
   
    //cheack if intPart has no digits after the decimal point
    return(std::floor(num) == num);

}


Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}
Fraction::Fraction(double num) {
    //printf("num = %f \r",num);
    if (hasMoreThanThreeDigitsAfterDecimal(num) == 0) {
        throw std::invalid_argument("The number has more than 3 digits after the decimal point");
    }
   
    
    Fraction f = doubleToFraction(num);
    this->numerator = f.numerator;
    this->denominator = f.denominator;
}
Fraction::Fraction(int num, double den){
    if (hasMoreThanThreeDigitsAfterDecimal(den) == 0) {
        throw std::invalid_argument("The number has more than 3 digits after the decimal point");
    }
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be 0");
    }
    Fraction f = doubleToFraction(num);
    this->numerator = f.numerator;
    this->denominator = f.denominator;
    reduce();
}
Fraction :: 

Fraction::Fraction(double num, int den) {
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be 0");
    }
    Fraction f = doubleToFraction(num);
    this->numerator = f.numerator ;
    this->denominator = f.denominator*den;
    reduce();
}
Fraction::Fraction(double num, double den){
    if (hasMoreThanThreeDigitsAfterDecimal(num) == 0) {
        throw std::invalid_argument("The number has more than 3 digits after the decimal point");
    }
    if (hasMoreThanThreeDigitsAfterDecimal(den) == 0) {
        throw std::invalid_argument("The number has more than 3 digits after the decimal point");
    }
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be 0");
    }
    Fraction f = doubleToFraction(num);
    Fraction f2 = doubleToFraction(den);
    this->numerator = f.numerator * f2.denominator;
    this->denominator = f.denominator * f2.numerator;
    reduce();
}
Fraction::Fraction(int num, int den =1) {
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be 0");
    }
    if(den<0){
        num=-num;
        den=-den;
    }
    numerator = num;
    denominator = den;
    reduce();
}
Fraction::Fraction(const Fraction& other):numerator(other.numerator),denominator(other.denominator) {
   
}
Fraction& Fraction::operator=(const Fraction& other) {
    if (this == &other) {
        return *this;
    }
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}







bool Fraction:: operator!=(const Fraction& other) const{
    return numerator != other.numerator || denominator != other.denominator;
}
bool Fraction::operator==(const Fraction& other) const {
    return numerator == other.numerator && denominator == other.denominator;
}
bool Fraction::operator>(const Fraction& other) const {
    return numerator * other.denominator > other.numerator * denominator;
}
bool Fraction::operator<(const Fraction& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}
bool Fraction::operator>=(const Fraction& other) const {
    return numerator * other.denominator >= other.numerator * denominator;
}
bool Fraction::operator<=(const Fraction& other) const {
    return numerator * other.denominator <= other.numerator * denominator;
}
Fraction& Fraction::operator++() {
   
    numerator += denominator;
    return *this;
}
const Fraction Fraction::operator++(int) {
     //the const is for the return value of the function that will not change the object.
    Fraction result = *this;//copy the current object
    numerator += denominator;
    return result;//return the copy of the current object
}
Fraction& Fraction::operator--() {
    numerator -= denominator;
    return *this;
}
const Fraction Fraction::operator--(int) {
    Fraction result = *this;
    numerator -= denominator;
    return result;
}
//we changr the 
Fraction Fraction::operator+=(const Fraction& other){
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator = denominator * other.denominator;
    reduce();
    return *this;
}
Fraction Fraction::operator-=(const Fraction& other){
    numerator = numerator * other.denominator - other.numerator * denominator;
    denominator = denominator * other.denominator;
    reduce();
    return *this;
}
Fraction Fraction::operator*=(const Fraction& other){
    numerator = numerator * other.numerator;
    denominator = denominator * other.denominator;
    reduce();
    return *this;
}
Fraction Fraction::operator/=(const Fraction& other){
    numerator = numerator * other.denominator;
    denominator = denominator * other.numerator;
    reduce();
    return *this;
}

  

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
void Fraction::reduce() {
    if (numerator == 0) {
        denominator = 1;
    } else {
        int divisor = gcd(abs(numerator), abs(denominator));
        numerator /= divisor;
        denominator /= divisor;
    }
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}
int :: Fraction::getNumerator() const {
    return numerator;
}
int :: Fraction::getDenominator() const {
    return denominator;
}
/*this is for aall "+ - * / " operation*/
//its like "a + b" so a is the "this" and b is the "other"
Fraction Fraction:: operator+(const Fraction& other) const{
    //the arithmetic calculation.
    int numerator = this->numerator * other.denominator + other.numerator * this->denominator;
    int denominator = this->denominator * other.denominator;
    //return new object as a reduced fraction.
    return Fraction(numerator, denominator);
}
Fraction Fraction:: operator-(const Fraction& other) const{
    int numerator = this->numerator * other.denominator - other.numerator * this->denominator;
    int denominator = this->denominator * other.denominator;
    return Fraction(numerator, denominator);
}
Fraction Fraction:: operator*(const Fraction& other) const{
    int numerator = this->numerator * other.numerator;
    int denominator = this->denominator * other.denominator;
    return Fraction(numerator, denominator);
}
Fraction Fraction:: operator/(const Fraction& other) const{
    int numerator = this->numerator * other.denominator;
    int denominator = this->denominator * other.numerator;
    return Fraction(numerator, denominator);
}
//we
Fraction ariel:: operator+(const Fraction& fraction, const double& num){
    
    return (fraction + doubleToFraction(num));
}
Fraction ariel:: operator-(const Fraction& fraction, const double& num){
    return (fraction - doubleToFraction(num));
}
Fraction ariel:: operator*(const Fraction& fraction, const double& num){
    return (fraction * doubleToFraction(num));
}
Fraction ariel:: operator/(const Fraction& fraction, const double& num){
    return (fraction / doubleToFraction(num));
}
Fraction ariel:: operator+(const double& num, const Fraction& fraction){
    return (fraction + doubleToFraction(num));
}
Fraction ariel:: operator-(const double& num, const Fraction& fraction){
    return (doubleToFraction(num) - fraction);
}
Fraction ariel:: operator*(const double& num,const Fraction& fraction){
    return (fraction * doubleToFraction(num));
}
Fraction ariel:: operator/(const double& num, const Fraction& fraction){
    return (doubleToFraction(num) / fraction);
}
 
bool ariel::operator>(const Fraction& fraction, const double& num)
    {
        return fraction.getNumerator() > fraction.getDenominator() * num;
    }
bool ariel::operator>(const double& num,const Fraction& fraction ){
    //printf("num = %f fraction = %d/%d \n", num, fraction.getNumerator(), fraction.getDenominator());
    return doubleToFraction(num) > fraction;
}
bool ariel::operator<(const double& num,const Fraction& fraction ){
    //printf("num = %f fraction = %d/%d \n", num, fraction.getNumerator(), fraction.getDenominator());
    return doubleToFraction(num) < fraction;
}
bool ariel::operator>=(const double& num,const Fraction& fraction ){
    //printf("num = %f fraction = %d/%d \n", num, fraction.getNumerator(), fraction.getDenominator());
    return doubleToFraction(num) >= fraction;
}
bool ariel::operator<=(const double& num,const Fraction& fraction ){
    //printf("num = %f fraction = %d/%d \n", num, fraction.getNumerator(), fraction.getDenominator());
    return doubleToFraction(num) <= fraction;
}

bool ariel::operator<(const Fraction& fraction, const double& num)
{
    return fraction.getNumerator() < fraction.getDenominator() * num;
}
bool ariel::operator>=(const Fraction& fraction, const double& num)
{
    return fraction.getNumerator() >= fraction.getDenominator() * num;
}
bool ariel::operator<=(const Fraction& fraction, const double& num)
{
    return fraction.getNumerator() <= fraction.getDenominator() * num;
}

std::ostream& ariel::operator<<(std::ostream& os, const Fraction& fraction){
    os << fraction.getNumerator() << "/" << fraction.getDenominator();
    //printf("fraction.getNumerator() = %d fraction.getDenominator() = %d \n", fraction.getNumerator(), fraction.getDenominator());
    return os;
}
//The >> operator to read a fraction from an input stream by taking two integers as input.
std::istream& ariel::operator>>(std::istream& is, Fraction& fraction){
    int numerator;
    int denominator;
    char slash;
    is >> numerator >> slash >> denominator;
    if (is.fail() || slash != '/' || denominator == 0) {
        throw std::invalid_argument("Invalid input");
    }
    fraction = Fraction(numerator, denominator);
    return is;
}

Fraction doubleToFraction(double d) {
    if(hasMoreThanThreeDigitsAfterDecimal(d) == 0)
        throw std::invalid_argument("Invalid input");

    int sign = 1;
    if (d < 0) {
        sign = -1;
        d = -d;
    }

    int whole = floor(d);
    d = d - whole;

    int precision = 1000;
    int numerator = round(d * precision);
    int denominator = precision;

    int g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;

    numerator += whole * denominator;

    numerator *= sign;

    return Fraction(numerator, denominator);
}













