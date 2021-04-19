#pragma once

#include <iostream> 
#include <string.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
class complex
{
private:
    double real, imagine;
public:
    complex() { real = 0; imagine = 0; }
    complex(double r, double i) { real = r; imagine = i; }
    complex(const complex& ob) { real = ob.real; imagine = ob.imagine; };
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