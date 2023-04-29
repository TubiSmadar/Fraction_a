#ifndef FRACTION_HPP
#define FRACTION_HPP

using namespace std;
namespace ariel {
    class Fraction {
    private:
        int numirator;
        int denomirator;
    public:
        //Constructors
        Fraction(int numirator, int denomirator);
        Fraction(float fractNum);

        //Getters
        int getNumirator() const
        {
            return this->numirator;
        }

        int getDenomirator() const
        {
            return this->denomirator;
        }

        //Setters
        void setNumirator(int numirator);
        void setDenomirator(int denumirator);

        //Operators
        Fraction operator+(Fraction& other);
        float operator+(float fractNum);
        Fraction operator-(Fraction& other);
        float operator-(float fractNum);
        Fraction operator*(Fraction& other);
        float operator*(float fractNum);
        friend Fraction operator*(float fractNum, const Fraction &frac);
        Fraction operator/( Fraction& other);
        bool operator<(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        bool operator==(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;
        bool operator!=(const Fraction& other) const;
        //prefix
        Fraction& operator++();
        Fraction& operator--();
        //postfix
        Fraction operator++(int);
        Fraction operator--(int);
        friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
        friend std::istream& operator>>(std::istream& in, Fraction& fraction);

        //Methods
        int gcdFoo(int a, int b);
    };
};
#endif