#include <bits/stdc++.h>
using namespace std;

struct Fraction
{
    int ts;
    int ms;

    void simplify()
    {
        int gcd = __gcd(ts, ms);
        ts /= gcd;
        ms /= gcd;
        if (ms < 0)
        {
            ts = -ts;
            ms = -ms;
        }
    }

    Fraction(int num = 0, int den = 1) : ts(num), ms(den)
    {
        simplify();
    }

    friend ostream &operator<<(ostream &os, const Fraction &frac)
    {
        if (frac.ms != 1)
            os << frac.ts << "/" << frac.ms;
        else
            os << frac.ts / frac.ms;
        return os;
    }

    friend istream &operator>>(istream &is, Fraction &frac)
    {
        char slash;
        is >> frac.ts >> slash >> frac.ms;
        return is;
    }
};

int main()
{
    cout << "Nhap phan so A, vi du 1/3: ";
    Fraction a;
    cin >> a;
    a.simplify();
    cout << "Phan so sau khi rut gon: " << a;
    return 0;
}

/* FRACTIONS
8/2
9/-2
-1/-2
9/1
10/15
0/-2
0/3
10/10
*/