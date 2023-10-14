#include "complex.h"

Tcomplex::Tcomplex(double r, double im)
{
   real = r;
   image = im;
}

Tcomplex::Tcomplex()
{
   real = 0;
   image = 0;
}

Tcomplex::Tcomplex(int d)
{
   real = d;
   image = 0;
}

Tcomplex::Tcomplex(const Tcomplex& c)
{
    real = c.real;
    image = c.image;
}

ostream& operator<< (ostream& os, Tcomplex& c)
{
    if(c.image == 0)
    {
        os << c.real;
        return os;
    }
    if(c.image == 1)
    {
        os << c.real << "+i";
        return os;
    }
    if(c.image == -1)
    {
        os << c.real << "-i";
        return os;
    }
    if(c.image < 0)
        os << c.real << c.image << "i ";
    else
        os << c.real << "+" << c.image << "i ";
    return os;
}

QString& operator<<(QString& os, Tcomplex c)
{
    if(c.image == 0)
    {
        os += QString().setNum(c.real);
        return os;
    }
    if(c.image == 1)
    {
        os += (QString().setNum(c.real) + "+i");
        return os;
    }
    if(c.image == -1)
    {
        os += (QString().setNum(c.real) + "-i");
        return os;
    }
    if(c.image < 0)
        os += (QString().setNum(c.real) + QString().setNum(c.image) + "i");
    else
        os += (QString().setNum(c.real) + "+" + QString().setNum(c.image) + "i");
    return os;
}

istream& operator>> (istream& is, Tcomplex& c)
{
    cout<< endl << "real = ";
    cin >> c.real;
    cout<<"image = ";
    cin >> c.image;
    return is;
}

Tcomplex Tcomplex::operator+(Tcomplex c)
{
    return Tcomplex(real + c.real, image + c.image);
}

Tcomplex Tcomplex::operator-(Tcomplex c)
{
    return Tcomplex(real - c.real, image - c.image);
}

Tcomplex Tcomplex::operator-()
{
    return Tcomplex(-real, -image);
}

Tcomplex Tcomplex::operator*(Tcomplex c)
{
    return Tcomplex(real * c.real - image * c.image, real * c.image + image * c.real);
}

Tcomplex Tcomplex::operator/(Tcomplex c)
{
    return Tcomplex((real * c.real + image * c.image) / (c.real * c.real + c.image * c.image),
                   (image * c.real - real * c.image) / (c.real * c.real + c.image * c.image));
}

Tcomplex Tcomplex::operator=(Tcomplex c)
{
    real = c.real;
    image = c.image;
    return *this;
}

Tcomplex Tcomplex::operator=(int d)
{
    real = d;
    image = 0;
    return *this;
}

Tcomplex Tcomplex::operator+=(Tcomplex c)
{
    real += c.real;
    image += c.image;
    return *this;
}

Tcomplex Tcomplex::operator*=(Tcomplex c)
{
    *this = *this * c;
    return *this;
}

bool Tcomplex::operator==(int i)
{
    return real == i && image == 0 ? true : false;
}

bool Tcomplex::operator!=(int i)
{
    return real != 0 || image != 0? true : false;
}

