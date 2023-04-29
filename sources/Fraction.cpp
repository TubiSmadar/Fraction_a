#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Fraction.hpp"
using namespace std;

namespace ariel{

    Fraction :: Fraction(int numirator, int denomirator)
    {
        if (denomirator == 0)
        {
            throw std :: invalid_argument("Division by zero is not defined\n");
        }
        int greatestCommonDivisor = gcdFoo(numirator, denomirator);

        this->numirator = numirator / greatestCommonDivisor;
        this->denomirator = denomirator / greatestCommonDivisor;
    }

    Fraction :: Fraction(float fractNum)

    {   int max = 1000;
        fractNum *= max;
        int gcd = gcdFoo((int) fractNum, max);
        Fraction fract = Fraction(fractNum / gcd, max / gcd);

        this->numirator = fract.getNumirator();
        this->denomirator = fract.getDenomirator();
    }

    void Fraction::setNumirator(int numirator)
    {
        this->numirator = numirator;
    }

    void Fraction::setDenomirator(int denominator)
    {
        if (denominator == 0){
            throw std :: invalid_argument ("Division by zero is not defined\n");
        }
        this->denomirator = denominator;
    }
    Fraction Fraction::operator+(Fraction& other){

        int newNuminator = (this->numirator * other.denomirator) + (other.numirator * this->denomirator);
        int newDenominator = this->denomirator * other.denomirator;
        int gcd = gcdFoo(newNuminator, newDenominator);
        newNuminator /= gcd;
        newDenominator /= gcd;

        return Fraction(newNuminator,newDenominator);

    }

    float Fraction::operator+(float fractNum){
        float result = (this->numirator / this->denomirator) + fractNum;
        return result;
    }

    Fraction Fraction::operator-(Fraction& other){

        int newNuminator = (this->numirator * other.denomirator) - (other.numirator * this->denomirator);
        int newDenominator = this->denomirator * other.denomirator;

        // int gcd = gcdFoo(newNuminator, newDenominator);
        // newNuminator /= gcd;
        // newDenominator /= gcd;

        return Fraction(newNuminator,newDenominator);

    }

    float Fraction::operator-(float fractNum){
        float result = (this->numirator / this->denomirator) - fractNum;
        return result;
    }

    Fraction Fraction::operator*(Fraction& other) {

        int newNuminator = this->numirator * other.numirator;
        int newDenominator = this->denomirator * other.denomirator;

        int gcd = gcdFoo(newNuminator, newDenominator);
        newNuminator /= gcd;
        newDenominator /= gcd;

        return Fraction(newNuminator,newDenominator);
    }

    float Fraction::operator*(float fractNum){
        float result = (this->numirator / this->denomirator) * fractNum;
        return result;
    }

    Fraction operator*(float fractNum, const Fraction &frac){
        return Fraction(1,2);
    }

    Fraction Fraction::operator/(Fraction& other) {
        int newNuminator = this->numirator * other.denomirator;
        int newDenominator = this->denomirator * other.numirator;

        int gcd = gcdFoo(newNuminator, newDenominator);
        newNuminator /= gcd;
        newDenominator /= gcd;

        return Fraction(newNuminator,newDenominator);
    }


    bool Fraction::operator==(const Fraction& other) const {
        if ((this->numirator == other.numirator) && (this->denomirator == other.denomirator)){
            return true;
        }
        return false;
    }


    bool Fraction::operator<(const Fraction& other) const {
        if ((this->numirator/this->denomirator) < (other.numirator/other.denomirator)){
            return false;
        }
        return true;

    }

    bool Fraction::operator>(const Fraction& other) const {
        float thisValue = static_cast<float>(this->numirator) / this->denomirator;
        float otherValue = static_cast<float>(other.numirator) / other.denomirator;
        return thisValue > otherValue;
    }

    bool Fraction::operator<=(const Fraction& other) const {
        if ((this->numirator/this->denomirator) <= (other.numirator/other.denomirator)){
            return true;
        }
        return false;
    }

    bool Fraction::operator>=(const Fraction& other) const {
        float thisValue = static_cast<float>(this->numirator) / this->denomirator;
        float otherValue = static_cast<float>(other.numirator) / other.denomirator;
        return thisValue >= otherValue;
    }
    bool Fraction::operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    //prefix
    Fraction& Fraction::operator++(){
        this->setNumirator(this->getNumirator() + this->getDenomirator());
        return *this;
    }

    //postfix
    Fraction Fraction::operator++(int) {
        Fraction a = *this;
        this->setNumirator(this->getNumirator() + this->getDenomirator());
        return a;
    }

    //prefix
    Fraction& Fraction::operator--(){
        this->setNumirator(this->getNumirator() - this->getDenomirator());
        return *this;
    }

    //postfix
    Fraction Fraction::operator--(int) {
        Fraction a = *this;
        this->setNumirator(this->getNumirator() - this->getDenomirator());
        return a;
    }


    std::ostream& operator<<(std::ostream& output, const Fraction& fraction)
    {
        output << fraction.getNumirator() << "/" << fraction.getDenomirator();
        return output;
    }

    std::istream& operator>>(std::istream& input, Fraction& fraction)
    {
        int numerator, denominator;
        char slash;

        input >> numerator >> slash >> denominator;

        if (slash != '/')
            throw invalid_argument("Invalid input");

        fraction = Fraction(numerator, denominator);

        return input;
    }
    int Fraction::gcdFoo(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        else
        {
            return gcdFoo(b, a % b);
        }
    }
}
