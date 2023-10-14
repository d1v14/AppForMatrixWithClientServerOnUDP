#ifndef TCOMPLEX_H
#define TCOMPLEX_H
#include <qstring.h>
#include <iostream>
#include <ostream>
using namespace std;

class Tcomplex
{
private:

    double real = 0;
    double image = 0;

public:
    Tcomplex(double, double);
    Tcomplex(int);
    Tcomplex();
    Tcomplex(const Tcomplex&);
    friend ostream& operator<<(ostream&, Tcomplex&);
    friend istream& operator>>(istream&, Tcomplex&);
    friend QString& operator<<(QString&, Tcomplex);
    Tcomplex operator+(Tcomplex);
    Tcomplex operator-(Tcomplex);
    Tcomplex operator*(Tcomplex);
    Tcomplex operator/(Tcomplex);
    Tcomplex operator=(Tcomplex);
    Tcomplex operator=(int);
    Tcomplex operator+=(Tcomplex);
    Tcomplex operator-();
    Tcomplex operator*=(Tcomplex);
    bool operator==(int);
    bool operator!=(int);

};

#endif // TCOMPLEX_H
