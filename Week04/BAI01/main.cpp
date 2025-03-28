#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;
const int maxn = 1e5 + 5;

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

    float getValue() const
    {
        return (float)ts / ms;
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
    Fraction A, B;
    cout << "Nhap phan so A. ";
    cin >> A;
    cout << "Phan so A co gia tri la " << A.getValue() << '\n';
    cout << "Nhap phan so B. ";
    cin >> B;
    cout << "Phan so B co gia tri la " << B.getValue() << '\n';

    cout << "A + B = " << A + B << endl
         << "A - B = " << A - B << endl
         << "A * B = " << A * B << endl
         << "A / B = " << A / B << endl;
    return 0;
}