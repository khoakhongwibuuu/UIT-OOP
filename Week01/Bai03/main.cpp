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

    Fraction operator+(const Fraction &target)
    {
        return Fraction(ts * target.ms + target.ts * ms,
                        ms * target.ms);
    }

    Fraction operator-(const Fraction &target)
    {
        return Fraction(ts * target.ms - target.ts * ms,
                        ms * target.ms);
    }

    Fraction operator*(const Fraction &target)
    {
        return Fraction(ts * target.ts, ms * target.ms);
    }

    Fraction operator/(const Fraction &target)
    {
        return Fraction(ts * target.ms, ms * target.ts);
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
    cout << "Nhap 2 phan so A va B, vi du 1/3 1/4: ";
    Fraction a, b;
    cin >> a >> b;
    a.simplify();
    b.simplify();
    cout << "a + b = " << a + b << endl
         << "a - b = " << a - b << endl
         << "a * b = " << a * b << endl
         << "a / b = " << a / b << endl;
    return 0;
}
