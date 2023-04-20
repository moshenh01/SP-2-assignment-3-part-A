#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <utility>

 namespace ariel {

    class Fraction {
    private:
        int numerator;
        int denominator;
        void reduce();
    public:
        Fraction();
        Fraction(double num);
        Fraction(int num, int den);
        Fraction(double num, int den);
        Fraction(int num, double den);
        Fraction(const Fraction& other);//copy constructor 
        Fraction(double num, double den);

        Fraction& operator=(const Fraction& other);//copy assignment operator 
        
        // Move constructor
        Fraction(Fraction&& other) noexcept : numerator(std::exchange(other.numerator, 0)), denominator(std::exchange(other.denominator, 0)) {}
    
        // Move assignment operator
        Fraction& operator=(Fraction&& other) noexcept {
            if (this != &other) {
                numerator = std::exchange(other.numerator, 0);
                denominator = std::exchange(other.denominator, 0);
            }
            return *this;
        }
        
         // Destructor
        ~Fraction() {}


        //cast operator frome Fraction to double "double d = a;"
        // operator double() const{
        //     return (double)numerator / (double)denominator;
        // }
    
         //cast operator frome Fraction to int "int d = a;"
        // operator int() const{
        //     return (int)(numerator / denominator);
        // }

        //we have const in the end of the func becz we want 
        Fraction operator+(const Fraction& other) const;
        Fraction operator-(const Fraction& other) const;
        Fraction operator*(const Fraction& other) const;
        Fraction operator/(const Fraction& other) const;

        
         


        bool operator==(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        bool operator<(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;
        bool operator!=(const Fraction& other) const;

        Fraction& operator++();
        const Fraction operator++(int);//postfix increment operator   
        Fraction& operator--();
        const Fraction operator--(int);

        int getNumerator() const;
        int getDenominator() const;//const on ->this 

        Fraction operator+=(const Fraction& other);
        Fraction operator-=(const Fraction& other);
        Fraction operator*=(const Fraction& other);
        Fraction operator/=(const Fraction& other);
        //const function canot change the object just return the value

        //we return reference to the object so we can use it in the same line agian
        friend std::ostream& operator<<(std::ostream& oss, const Fraction& fraction);
        friend std::istream& operator>>(std::istream& iss, Fraction& fraction);
        //the "friend" keyword is used to give a function or class access to private and protected members of other class in which it is declared as friend.
    };
   
    //for "a + 1.123"
    Fraction operator+(const Fraction& fraction, const double& num);
    Fraction operator-(const Fraction& fraction, const double& num);
    Fraction operator*(const Fraction& fraction, const double& num);
    Fraction operator/(const Fraction& fraction, const double& num);
    //for "1.123 + a"
    Fraction operator*(const double& num, const Fraction& fraction);
    Fraction operator+(const double& num, const Fraction& fraction);
    Fraction operator-(const double& num, const Fraction& fraction);
    Fraction operator/(const double& num, const Fraction& fraction);

    //for "a > 1.123"
    bool operator>(const Fraction& fraction, const double& num);
    bool operator<(const Fraction& fraction, const double& num);
    bool operator>=(const Fraction& fraction, const double& num);
    bool operator<=(const Fraction& fraction, const double& num);
    //for "1.123 > a"
    bool operator>(const double& num,const Fraction& fraction );
    bool operator<(const double& num,const Fraction& fraction );
    bool operator>=(const double& num,const Fraction& fraction );
    bool operator<=(const double& num,const Fraction& fraction );


    
  
}

#endif
