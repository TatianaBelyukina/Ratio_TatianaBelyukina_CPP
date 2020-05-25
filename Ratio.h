#ifndef __RATIO__
#define __RATIO__

#include <string>
#include <iostream>

using namespace std;

class Ratio
{
private:
    int nom;
    unsigned int den;

    void simplify();

public:
    Ratio(int nom, unsigned int den);

    static Ratio fromDouble(double x);

    int getNom();
    unsigned int getDen();

    void setNom(int nom);
    void setDen(unsigned int den);

    Ratio operator +(const Ratio& b);
    Ratio operator -(const Ratio& b);
    Ratio operator *(const Ratio& b);
    Ratio operator *(const double& b);
    Ratio operator /(const Ratio& b);
    Ratio operator /(const double& b);

    Ratio operator +();
    Ratio operator -();

    Ratio& operator += (const Ratio& b);
    Ratio& operator -= (const Ratio& b);
    Ratio& operator *= (const Ratio& b);
    Ratio& operator *= (const double& b);
    Ratio& operator /= (const Ratio& b);
    Ratio& operator /= (const double& b);
    friend ostream& operator<<(ostream& os, const Ratio& x);
};

#endif
