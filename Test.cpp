#include "doctest.h"
#include <iostream>
#include "Fraction.hpp"
using namespace ariel;


TEST_CASE("Checks that you cant assign 0 as denumirator")
{
    Fraction a(1,1);
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(a.setDenomirator(0));
}


TEST_CASE("Check's the + operator")
{
    Fraction a(2,10);
    Fraction b(3,10);
    Fraction c(5,10);
    CHECK(a.getNumirator() == 1);
    CHECK(a.getDenomirator() == 5);
    CHECK(b.getNumirator() == 3);
    CHECK(b.getDenomirator() == 10);
    CHECK(c.getNumirator() == 1);
    CHECK(c.getDenomirator() == 2);
    CHECK((a + b) + c == 1.0);

    Fraction x_f(5,10);
    CHECK(x_f.getNumirator() == 1);
    CHECK(x_f.getDenomirator() == 2);
    float y = 0.1;
    Fraction y_f(y);
    float z = 0.6;
    Fraction z_f(z);
    CHECK((x_f+y_f) == z_f);

}

TEST_CASE("Check's the - operator")
{
    Fraction a(2,10);
    Fraction b(3,10);
    Fraction c(5,10);
    CHECK(a.getNumirator() == 1);
    CHECK(a.getDenomirator() == 5);
    CHECK(b.getNumirator() == 3);
    CHECK(b.getDenomirator() == 10);
    CHECK(c.getNumirator() == 1);
    CHECK(c.getDenomirator() == 2);
    CHECK((b - a) + c == 0.6);

    Fraction x_f(5,10);
    CHECK(x_f.getNumirator() == 1);
    CHECK(x_f.getDenomirator() == 2);
    float y = 0.1;
    Fraction y_f(y);
    float z = 0.4;
    Fraction z_f(z);
    CHECK((x_f - y_f) == z_f);
}

TEST_CASE("Check's the * operator")
{
    Fraction a(1,3);
    float b = 0.0;
    float c = 1.1;
    CHECK( a * b  == b);
    CHECK( a * b == c * b);
    Fraction x(1,2);
    Fraction y(3,6);
    Fraction z(5,10);
    CHECK(x.getNumirator() == 1);
    CHECK(y.getNumirator() == 1);
    CHECK(z.getNumirator() == 1);    
    CHECK(x.getDenomirator() == 2);
    CHECK(y.getDenomirator() == 2);
    CHECK(z.getDenomirator() == 2);
    CHECK((x * y) * z == Fraction(1,8));
}

TEST_CASE("Check's the / operator")
{
    Fraction a(1,3);
    Fraction b(2,6);
    CHECK(a.getNumirator() == 1);
    CHECK(b.getNumirator() == 1);
    CHECK(a.getDenomirator() == 3);
    CHECK(b.getDenomirator() == 3);
    CHECK( a / b == 1);
    CHECK( b / a == 1);
    Fraction zero(0,1);
    CHECK_THROWS(a / zero);
    Fraction x(3,2);
    Fraction y(1,2);
    Fraction z(5,10);
    CHECK(((x / y) / z) == 6);
}

TEST_CASE("Check's (>,<,>=,<=, ==, !=) operations")
{
    Fraction a(1,3);
    Fraction b(2,6);
    Fraction c(0.10);

    CHECK(a == b);
    CHECK(b >= c);
    CHECK(b > c);
    CHECK(b <= a);
    CHECK(c < a);
}

TEST_CASE("Check's the ++ and -- operators"){
    Fraction a(1,1);
    a++;
    Fraction b(2);
    CHECK(a == b);
    CHECK(a++ == b);
    ++b;
    CHECK(a == b);
    --b;
    CHECK(--a == b);
}
