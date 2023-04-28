#include "doctest.h"
#include "Fraction.hpp"
#include <stdexcept>
#include <sstream>
#include <string>

using namespace ariel;
using namespace std;


TEST_CASE("check the constructor") {
    Fraction a(5,3), b(14,21);
    CHECK(a.getNumerator() == 5);
    CHECK(a.getDenominator() == 3);
    CHECK(b.getNumerator() == 2);
    CHECK(b.getDenominator() == 3);

    CHECK_THROWS(Fraction(5,0));
    CHECK_THROWS(Fraction(5.5,0));

    Fraction c(5.5);
    CHECK(c.getNumerator() == 11);
    CHECK(c.getDenominator() == 2);

    Fraction d(1.2,2); 
    CHECK(d.getNumerator() == 3);
    CHECK(d.getDenominator() == 5);

    Fraction e(1.2,2.3);
    CHECK(e.getNumerator() == 12);
    CHECK(e.getDenominator() == 23);

    CHECK_THROWS(Fraction(1.2222,2.3333));
    CHECK_THROWS(Fraction(1.2222));
    CHECK_THROWS(Fraction(1.2222,1));


}
TEST_CASE("check the copy constructor") {
    Fraction a(5,3), b(14,21);
    Fraction c(a);
    Fraction d(b);
    CHECK_FALSE(&a == &c);
    CHECK_FALSE(&b == &d);
    CHECK(c.getNumerator() == 5);
    CHECK(c.getDenominator() == 3);
    CHECK(d.getNumerator() == 2);
    CHECK(d.getDenominator() == 3);
}
TEST_CASE("check the copy assignment operator") {
    Fraction a(5,3), b(14,21);
    Fraction c(1,1), d(1,1);
    c = a;
    d = b;
    CHECK_FALSE(&a == &c);
    CHECK_FALSE(&b == &d);
    CHECK(c.getNumerator() == 5);
    CHECK(c.getDenominator() == 3);
    CHECK(d.getNumerator() == 2);
    CHECK(d.getDenominator() == 3);
}
TEST_CASE("check the move constructor") {
    //move constructor is move the value of the object to the new object
    //and the old object is empty
    Fraction a(5,3), b(14,21);
    Fraction c(std::move(a));
    Fraction d(std::move(b));

    CHECK(a.getNumerator() == 0);
    CHECK(a.getDenominator() == 0);
    CHECK(b.getNumerator() == 0);
    CHECK(b.getDenominator() == 0);
    
    CHECK(c.getNumerator() == 5);
    CHECK(c.getDenominator() == 3);
    CHECK(d.getNumerator() == 2);
    CHECK(d.getDenominator() == 3);
}
TEST_CASE("check the move assignment operator") {
    Fraction a(5,3), b(14,21);
    Fraction c(1,1), d(1,1);
    c = std::move(a);
    d = std::move(b);
    CHECK(c.getNumerator() == 5);
    CHECK(c.getDenominator() == 3);
    CHECK(d.getNumerator() == 2);
    CHECK(d.getDenominator() == 3);

    CHECK(a.getNumerator() == 0);
    CHECK(a.getDenominator() == 0);
    CHECK(b.getNumerator() == 0);
    CHECK(b.getDenominator() == 0);
}
TEST_CASE("check the OPERATORS") {
    SUBCASE("check the + operator") {
        Fraction a(5,3), b(14,21);
        Fraction c = a + b;
        Fraction d = a + 1.34;
        Fraction e = 1.34 + a;
        CHECK(c.getNumerator() == 7);
        CHECK(c.getDenominator() == 3);

        CHECK(d.getNumerator() == 451);
        CHECK(d.getDenominator() == 150);

        CHECK_EQ(d,e);

        Fraction m(0.2);
        Fraction n(0.1);
        Fraction o = m + n;
        CHECK(o.getNumerator() == 3);
        CHECK(o.getDenominator() == 10);

    }
    SUBCASE("check the - operator") {
        Fraction a(5,3), b(14,21);
        Fraction c = a - b;
        CHECK(c.getNumerator() == 1);
        CHECK(c.getDenominator() == 1);
    }
    SUBCASE("check the * operator") {
        Fraction a(5,3), b(14,21);
        Fraction c = a * b;
        CHECK(c.getNumerator() == 10);
        CHECK(c.getDenominator() == 9);
    }
    SUBCASE("check the / operator") {
        Fraction a(5,3), b(14,21);
        Fraction c = a / b;
        CHECK(c.getNumerator() == 5);
        CHECK(c.getDenominator() == 2);
    }
    SUBCASE("check the += operator") {
        Fraction a(5,3), b(14,21);
        a += b;
        CHECK(a.getNumerator() == 7);
        CHECK(a.getDenominator() == 3);
    }
    SUBCASE("check the -= operator") {
        Fraction a(5,3), b(14,21);
        a -= b;
        CHECK(a.getNumerator() == 1);
        CHECK(a.getDenominator() == 1);
    }
    SUBCASE("check the *= operator") {
        Fraction a(5,3), b(14,21);
        a *= b;
        CHECK(a.getNumerator() == 10);
        CHECK(a.getDenominator() == 9);
    }
    SUBCASE("check the /= operator") {
        Fraction a(5,3), b(14,21);
        a /= b;
        CHECK(a.getNumerator() == 5);
        CHECK(a.getDenominator() == 2);
    }

    SUBCASE("check the ++ operator") {
        Fraction a(5,3);
        ++a;
        CHECK(a.getNumerator() == 8);
        CHECK(a.getDenominator() == 3);
    }
    SUBCASE("check the -- operator") {
        Fraction a(5,3);
        --a;
        CHECK(a.getNumerator() == 2);
        CHECK(a.getDenominator() == 3);
    }
    SUBCASE("check the ++ operator") {
        Fraction a(5,3);
        a++;
        CHECK(a.getNumerator() == 8);
        CHECK(a.getDenominator() == 3);
    }
    SUBCASE("check the -- operator") {
        Fraction a(5,3);
        a--;
        CHECK(a.getNumerator() == 2);
        CHECK(a.getDenominator() == 3);
    }
    SUBCASE("check the == operator") {
        Fraction a(5,3), b(14,21);
        CHECK(!(a == b));
    }
    SUBCASE("check the != operator") {
        Fraction a(5,3), b(14,21);
        CHECK((a != b));
    }
    SUBCASE("check the > operator") {
        Fraction a(5,3), b(14,21);
        CHECK((a > b));
    }
    SUBCASE("check the < operator") {
        Fraction a(5,3), b(14,21);
        CHECK(!(a < b));
    }
    SUBCASE("check the >= operator") {
        Fraction a(5,3), b(14,21);
        CHECK((a >= b));
    }


   
}
TEST_CASE("check the I/O") {
    SUBCASE("check the << operator") {
        Fraction a(5,3);
        std::stringstream ss;
        ss << a;
        CHECK(ss.str() == "5/3");
    }
    SUBCASE("check the >> operator") {
        Fraction a;
        std::stringstream ss;
        ss << "5/3";
        ss >> a;
        CHECK(a.getNumerator() == 5);
        CHECK(a.getDenominator() == 3);
    }
}
// TEST_CASE("check the cast") {
//     SUBCASE("check the cast to double") {
//         Fraction a(5,3);
        
//         double b = a;
//         CHECK(b == 5.0/3.0);
//     }
//     SUBCASE("check the cast to int") {
//         Fraction a(5,3);
//         int b = a;
//         CHECK(b == 1);
//     }
//}
TEST_CASE("arithmetics with order of operations") {
    Fraction a(5,3), b(14,21), c(1,1), d(1,1);
    c = a + b * a;
    d = (a + b) * a;
    CHECK(c.getNumerator() == 25);
    CHECK(c.getDenominator() == 9);
    CHECK(d.getNumerator() == 35);
    CHECK(d.getDenominator() == 9);

    Fraction e(5,3), f(14,21), g(1,1), h(1,1);
    g = e + f / e;
    h = (e + f) / e;
    CHECK(g.getNumerator() == 31);
    CHECK(g.getDenominator() == 15);
    CHECK(h.getNumerator() == 7);
    CHECK(h.getDenominator() == 5);

    Fraction i(5,3), j(14,21), k(1,1), l(1,1);
    k = i - j * i;
    l = (i - j) * i;
    CHECK(k.getNumerator() == 5);
    CHECK(k.getDenominator() == 9);
    CHECK(l.getNumerator() == 5);
    CHECK(l.getDenominator() == 3);

}
TEST_CASE("check negative numbers") {
    Fraction a(-5,3), b(14,21), c(1,1), d(1,1);
    c = a + b;
    d = a - b;
    CHECK(c.getNumerator() == -1);
    CHECK(c.getDenominator() == 1);
    CHECK(d.getNumerator() == -7);
    CHECK(d.getDenominator() == 3);

    Fraction e(-5,3), f(14,21), g(1,1), h(1,1);
    g = e * f;
    h = e / f;
    CHECK(g.getNumerator() == -10);  
    CHECK(g.getDenominator() == 9);
    CHECK(h.getNumerator() == -5);   
    CHECK(h.getDenominator() == 2);

    Fraction i(-5,3), j(14,21), k(1,1), l(1,1);
    k = i + j * i;
    l = (i + j) * i;
    CHECK(k.getNumerator() == -25);
    CHECK(k.getDenominator() == 9);
    CHECK(l.getNumerator() == 5);
    CHECK(l.getDenominator() == 3);
}
