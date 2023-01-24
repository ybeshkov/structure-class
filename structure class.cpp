#include <iostream>

class Rational
{
public:
    Rational() : numerator(0), denominator(1) {}
    Rational(const int a, const int b) : numerator(a), denominator(b) {}

    void add(const Rational& f)
    {
        if (denominator == f.denominator)
        {
            numerator += f.numerator;
            return;
        }
        int mult = denominator * f.denominator;
        numerator = numerator * (mult / denominator) +
            f.numerator * (mult / f.denominator);
        denominator = mult;
    }
    void sub(const Rational& f)
    {
        if (denominator == f.denominator)
        {
            numerator -= f.numerator;
            return;
        }
        int mult = denominator * f.denominator;
        numerator = numerator * (mult / denominator) -
            f.numerator * (mult / f.denominator);
        denominator = mult;
    }

    friend std::ostream& operator<< (std::ostream& out, const Rational& f)
    {
        out << f.numerator << "/" << f.denominator;
        return out;
    }

protected:
    int numerator, denominator;
};


int main()
{
    Rational f1(3, 4), f2(1, 8), f3(1, 32);
    std::cout << f1 << " + " << f2 << " - " << f3 << " = ";
    f1.add(f2);
    f1.sub(f3);
    std::cout << f1 << std::endl;
}