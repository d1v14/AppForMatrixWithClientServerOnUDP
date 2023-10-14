#ifndef TRATIONAL_H
#define TRATIONAL_H

#include <iostream>
#include <ostream>
#include <QString>

using namespace std;

class Trational
{
private:

    int num = 0;
    int denom = 1;

public:
    void NOD();
    Trational(int, int);
    Trational(int);
    Trational();
    Trational(const Trational&);
    double GetNum();
    double GetDenom();

    friend  QString& operator<<(QString&, Trational);

    friend ostream& operator<<(ostream&, Trational&);
    friend istream& operator>>(istream&, Trational&);
    Trational operator+(Trational);
    Trational operator-(Trational);
    Trational operator*(Trational);
    Trational operator/(Trational);
    Trational operator=(Trational);
    Trational operator=(int);
    Trational operator+=(Trational);
    Trational operator-();
    Trational operator*=(Trational);
    bool operator==(int);
    bool operator!=(int);
};

#endif // TRATIONAL_H
