#include "MyComplex.h"

bool complex:: operator > (complex& complex)
{
    if (this->real > complex.real)
        return 1;
    else if (this->real == complex.real && this->imagine > complex.imagine)
        return 1;
    else
        return 0;
}

bool complex ::operator < (complex& complex)
{
    if (this->real < complex.real)
        return 1;
    else if (this->real == complex.real && this->imagine < complex.imagine)
        return 1;
    else
        return 0;

}

bool complex::operator != (complex& complex)
{
    if (this->real != complex.real || this->imagine != complex.imagine)
        return 1;
    else
        return 0;
}

bool complex::operator == (complex complex)
{
    if (this->real == complex.real && this->imagine == complex.imagine)
        return 1;
    else
        return 0;
}



complex complex::operator*(complex& complex)
{
    double i, j;
    i = real * complex.real - imagine * complex.imagine;
    j = real * complex.imagine + complex.real * imagine;
    real = i;
    imagine = j;
    return *this;
}

complex complex::operator/(complex& complex)
{
    double i, j, k;
    k = real * real + complex.imagine * complex.imagine;
    i = (real * complex.real + imagine * complex.imagine) / k;
    j = (complex.real * imagine - real * complex.imagine) / k;
    real = i;
    imagine = j;
    return *this;
}

complex& complex::operator =(complex complex)
{
    this->real = complex.real;
    this->imagine = complex.imagine;
    return *this;
}

complex complex::operator+(complex complex)
{
    this->real = this->real + complex.real;
    this->imagine = this->imagine + complex.imagine;
    return *this;
}

complex complex::operator-(complex complex)
{
    this->real = this->real - complex.real;
    this->imagine = this->imagine - complex.imagine;
    return *this;
}


std::ostream& operator << (std::ostream& out, const complex& complex)
{
    if (complex.imagine < 0)
        out << complex.real << "+i(" << complex.imagine << ")";
    else
        out << complex.real << "+i" << complex.imagine;
    return out;
}

std::istream& operator >> (std::istream& in, complex& complex)
{
    std::cout << "¬ведите действительную часть комплексного числа: ";
    in >> complex.real;
    std::cout << "¬ведите мнимую часть комплексного числа: ";
    in >> complex.imagine;
    return in;
}

complex& complex::operator+=(complex a)
{
    real += a.real;
    imagine += a.imagine;
    return *this;
}

complex& complex::operator-=(complex a)
{
    real -= a.real;
    imagine -= a.imagine;
    return *this;
}

complex& complex::operator*=(complex a)
{
    real *= a.real;
    imagine *= a.imagine;
    return *this;
}

complex& complex::operator/=(complex a)
{
    real /= a.real;
    imagine /= a.imagine;
    return *this;
}