#pragma once

#include <iostream> 
#include <string.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
class complex
{
private:
    double re, im;
public:
    complex() { re = 0; im = 0; }
    complex(double r, double i) { re = r; im = i; }
    complex(const complex& ob) { re = ob.re; im = ob.im; };
    complex& operator = (complex);
    complex operator + (complex);
    complex operator - (complex);
    complex operator * (complex&);
    complex operator / (complex&);
    complex& operator += (complex);
    complex& operator -= (complex);
    complex& operator *= (complex);
    complex& operator /=(complex);
    friend std::istream& operator >>(std::istream&, complex&);
    friend std::ostream& operator << (std::ostream&, const complex&);
    bool operator == (complex com);
    bool operator != (complex& com);
    bool operator > (complex& com);
    bool operator < (complex& com);

};