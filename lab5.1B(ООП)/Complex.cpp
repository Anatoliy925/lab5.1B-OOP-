#include "Complex.hpp"
#include "Exception.hpp"
#include "Exception_anc.hpp"
#include <sstream>
#include <string>
using namespace std;

int isfloat (string a)
{
    int len = a.length();
    int dsum = 0;
    int dot = 0;
    int minus = 0;
    for (int i = 0; i < len; i++)
    {
        if(isdigit(a[i])!= 0)
        {
            dsum++;
        }
        else if(a[i] == '.')
        {
            dot++;
        }
        else if(a[i] == '-')
        {
            minus++;
        }
    }
    if(dsum + dot + minus == len)
        return 1;
    else
        return 0;
}

Complex sub(Complex a, Complex b)
{
    return a - b;
}

Complex div(Complex a, Complex b)
{
    return a/b;
}

Complex Complex::conj()
{
    return Complex(re, -im);
}

Complex::Complex()
{
    set_re(0);
    set_im(0);
}

Complex::Complex(double r, double i)
{
    set_re(r);
    set_im(i);
}

Complex::Complex(const Complex& r)
{
    set_re(r.re);
    set_im(r.im);
}

Complex::~Complex()
{ }

Complex& Complex::operator = (const Complex& r)
{
    set_re(r.re);
    set_im(r.im);
    return *this;
}

Complex::operator string () const
{
    stringstream ss;
    ss << " Re = " << re << endl;
    ss << " Im = " << im << endl;
    
    return ss.str();
}

Complex operator - (const Complex& x, const Complex& y)
{
    return Complex(x.re - y.re, x.im - y.im);
}

Complex operator / (const Complex& x, const Complex& y)
{
    double r1 = x.re;
    double i1 = x.im;
    double r2 = y.re;
    double i2 = y.im;
    
    if(r2 * r2 + i2 * i2 == 0)
        throw Exception("Cannot divide by zero");
    else
    return Complex((r1 * r2 - i1 * i2) / (r2 * r2 + i2 * i2), (-r1 * i2 + i1 * r2) / (r2 * r2 + i2 * i2));
}

ostream& operator << (ostream& out, const Complex& r)
{
      out << string(r);
      return out;
}

istream& operator >> (istream& in, Complex& r)
{
    string a = "";
    string b = "";
    cout << " Re = "; in >> a;
    cout << " Im = "; in >> b;
    cout << endl;
    if(isfloat(a) == 1)
    {
        double x = stof(a);
        r.set_re(x);
    }
    else
        throw new Exception_anc("Is not a float");
    if(isfloat(b) == 1)
    {
        double y = stof(b);
        r.set_im(y);
    }
    else
        throw bad_exception();
    
    return in;
}

Complex& Complex::operator ++()
{
      re++;
      return *this;
}

Complex& Complex::operator --()
{
      re--;
      return *this;
}

Complex Complex::operator ++(int)
{
      Complex t(*this);
      im++;
      return t;
}

Complex Complex::operator --(int)
{
      Complex t(*this);
      im--;
      return t;
}


