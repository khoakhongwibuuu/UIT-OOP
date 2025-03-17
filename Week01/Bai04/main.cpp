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

    bool operator>(const Fraction &target) const
    {
        return ts * target.ms > target.ts * ms;
    }
    bool operator<(const Fraction &target) const
    {
        return ts * target.ms < target.ts * ms;
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
    cout << "Nhap so luong phan so: ";
    int n;
    cin >> n;
    vector<Fraction> f(n);
    cout << "Nhap " << n << " phan so, moi phan so tren 1 dong: \n";
    for (int i = 0; i < n; i++)
        cin >> f[i];
    sort(f.begin(), f.end(), greater<Fraction>());
    for (int i = 0; i < n; i++)
        cout << f[i] << " ";
    sort(f.begin(), f.end());
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << f[i] << " ";

    return 0;
}