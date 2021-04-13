#include "MyComplex.h"

bool complex:: operator > (complex& com)
{
    if (this->re > com.re)
        return 1;
    else if (this->re == com.re && this->im > com.im)
        return 1;
    else
        return 0;
}

bool complex ::operator < (complex& com)
{
    if (this->re < com.re)
        return 1;
    else if (this->re == com.re && this->im < com.im)
        return 1;
    else
        return 0;

}

bool complex::operator != (complex& com)
{
    if (this->re != com.re || this->im != com.im)
        return 1;
    else
        return 0;
}

bool complex::operator == (complex com)
{
    if (this->re == com.re && this->im == com.im)
        return 1;
    else
        return 0;
}



complex complex::operator*(complex& com)
{
    double i, j;
    i = re * com.re - im * com.im;
    j = re * com.im + com.re * im;
    re = i;
    im = j;
    return *this;
}

complex complex::operator/(complex& com)
{
    double i, j, k;
    k = re * re + com.im * com.im;
    i = (re * com.re + im * com.im) / k;
    j = (com.re * im - re * com.im) / k;
    re = i;
    im = j;
    return *this;
}

complex& complex::operator =(complex com)
{
    this->re = com.re;
    this->im = com.im;
    return *this;
}

complex complex::operator+(complex com)
{
    this->re = this->re + com.re;
    this->im = this->im + com.im;
    return *this;
}

complex complex::operator-(complex com)
{
    this->re = this->re - com.re;
    this->im = this->im - com.im;
    return *this;
}


std::ostream& operator << (std::ostream& out, const complex& com)
{
    if (com.im < 0)
        out << com.re << "+i(" << com.im << ")";
    else
        out << com.re << "+i" << com.im;
    return out;
}

std::istream& operator >> (std::istream& in, complex& com)
{
    std::cout << "¬ведите действительную часть комплексного числа: ";
    in >> com.re;
    std::cout << "¬ведите мнимую часть комплексного числа: ";
    in >> com.im;
    return in;
}

complex& complex::operator+=(complex a)
{
    re += a.re;
    im += a.im;
    return *this;
}

complex& complex::operator-=(complex a)
{
    re -= a.re;
    im -= a.im;
    return *this;
}

complex& complex::operator*=(complex a)
{
    re *= a.re;
    im *= a.im;
    return *this;
}

complex& complex::operator/=(complex a)
{
    re /= a.re;
    im /= a.im;
    return *this;
}