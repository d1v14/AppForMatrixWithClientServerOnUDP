#include "rational.h"
#include <math.h>
Trational::Trational(int n, int d)
{
   num = n;
   denom = d;
}


Trational::Trational()
{
   num = 0;
   denom = 1;
}

Trational::Trational(int n)
{
   num = n;
   denom = 1;
}

Trational::Trational(const Trational& r)
{
    num = r.num;
    denom = r.denom;
}

void Trational::NOD()
{
    int up = abs(num);
    int down = abs(denom);
    if (up == 0) return;
    while (up != down) {
      if (up>down) {
        up = up-down;
      }
      else {
        down = down-up;
      }
    }
    this->num = num/up;
    this->denom = denom/up;
}

QString& operator<<(QString& s, Trational r)
{
    if(r.denom == 1)
    {
        s += QString().setNum(r.num);
        return s;
    }
    if(r.num == 0)
    {
        s += QString().setNum(r.num);
        return s;
    }
    s += QString().setNum(r.num);
    s += "/";
    s += QString().setNum(r.denom);
    return s;
}

ostream& operator<< (ostream& os, Trational& r)
{
    if(r.denom == 1)
    {
        os << r.num;
        return os;
    }
    os << r.num << "/" << r.denom;
    return os;
}

istream& operator>> (istream& is, Trational& r)
{
    cout<< endl << "num = ";
    cin >> r.num;
    cout<<"denom = ";
    cin >> r.denom;
    return is;
}

Trational Trational::operator+(Trational r)
{
    Trational t;
    t.num = r.num*denom+ num*r.denom;
    t.denom = denom*r.denom;
    t.NOD();
    return t;
}

Trational Trational::operator-(Trational r)
{
    Trational t;
    t.num = num*r.denom-r.num*denom;
    t.denom = denom*r.denom;
    t.NOD();
    return t;
}

Trational Trational::operator-()
{
    Trational t;
    t.num = -num;
    t.denom = denom;
    return t;
}

Trational Trational::operator*(Trational r)
{
    Trational t;
    t.num = num * r.num;
    t.denom = denom * r.denom;
    t.NOD();
    return t;
}

Trational Trational::operator/(Trational r)
{
    Trational t;
    t.num = num * r.denom;
    t.denom = denom * r.num;
    t.NOD();
    return t;
}

Trational Trational::operator=(Trational r)
{
    num = r.num;
    denom = r.denom;
    return *this;
}

Trational Trational::operator=(int d)
{
    num = d;
    denom = 1;
    return *this;
}

Trational Trational::operator+=(Trational r)
{
    *this = Trational(*this + r);
    return *this;
}

Trational Trational::operator*=(Trational r)
{
    *this = Trational(*this * r);
    return *this;
}

bool Trational::operator==(int i)
{
    return num == i * denom ? true : false;
}

bool Trational::operator!=(int i)
{
    return num != i * denom ? true : false;
}

