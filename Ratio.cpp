#include "Ratio.h"
#include <math.h>

using namespace std;

Ratio::Ratio(int nom, unsigned int den) {
    this->nom = nom;
    this->den = den;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

void Ratio::simplify() {
    int rgcd = abs(gcd(this->nom, this->den));
    this->nom /= rgcd;
    this->den /= rgcd;
}

Ratio Ratio::fromDouble(double x) {
    unsigned int den = 1;
    while (floor(x) - x != 0) {
        x *= 10;
        den *= 10;
    }

    Ratio r(x, den);
    r.simplify();
    return r;
}

int Ratio::getNom() {
    return this->nom;
}

unsigned int Ratio::getDen() {
    return this->den;
}

void Ratio::setNom(int nom) {
    this->nom = nom;
}

void Ratio::setDen(unsigned int den) {
    this->den = den;
}

Ratio Ratio::operator +(const Ratio& b) {
    Ratio r(
        this->nom * b.den + this->den * b.nom,
        this->den * b.den
    );
    r.simplify();
    return r;
}

Ratio Ratio::operator -(const Ratio& b) {
    Ratio b_rev(-b.nom, b.den);
    return Ratio(this->nom, this->den) + b_rev;
}

Ratio Ratio::operator *(const Ratio& b) {
    Ratio r(
        this->nom * b.nom,
        this->den * b.den
    );
    r.simplify();
    return r;
}

Ratio Ratio::operator *(const double& b) {
    Ratio r(
        this->nom * b,
        this->den
    );
    r.simplify();
    return r;
}

Ratio Ratio::operator /(const Ratio& b) {
    Ratio b_rev(b.den, b.nom);
    return Ratio(this->nom, this->den) * b_rev;
}

Ratio Ratio::operator /(const double& b) {
    return Ratio(this->nom, this->den) * Ratio(1, b);
}


Ratio Ratio::operator +() {
    return Ratio(this->nom, this->den);
}

Ratio Ratio::operator -() {
    return Ratio(-this->nom, this->den);
}

Ratio& Ratio::operator += (const Ratio& b) {
    int newNom = this->nom * b.den + this->den * b.nom;
    unsigned int newDen = this->den * b.den;

    this->nom = newNom;
    this->den = newDen;

    this->simplify();
    return *this;
}

Ratio& Ratio::operator -= (const Ratio& b) {
    int newNom = this->nom * b.den - this->den * b.nom;
    unsigned int newDen = this->den * b.den;

    this->nom = newNom;
    this->den = newDen;

    this->simplify();
    return *this;
}

Ratio& Ratio::operator *= (const Ratio& b) {
    int newNom = this->nom * b.nom;
    unsigned int newDen = this->den * b.den;

    this->nom = newNom;
    this->den = newDen;

    this->simplify();
    return *this;
}

Ratio& Ratio::operator *= (const double& b) {
    int newNom = this->nom * b;

    this->nom = newNom;

    this->simplify();
    return *this;
}

Ratio& Ratio::operator /= (const Ratio& b) {
    int newNom = this->nom * b.den;
    unsigned int newDen = this->den * b.nom;

    this->nom = newNom;
    this->den = newDen;

    this->simplify();
    return *this;
}

Ratio& Ratio::operator /= (const double& b) {
    int newNom = this->nom / b;

    this->nom = newNom;

    this->simplify();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Ratio& r)
{
    os << std::to_string(r.nom) << '/' << std::to_string(r.den);
    return os;
}
