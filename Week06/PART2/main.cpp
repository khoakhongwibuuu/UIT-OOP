#include <iostream>
#include <numeric>
#include <cmath>
#include <stdexcept>
using namespace std;

class Fraction
{
private:
    long long num;
    long long den;

public:
    Fraction(long long num = 0, long long den = 1) : num(num), den(den)
    {
        if (den == 0)
            throw invalid_argument("Mau so phai khac 0.");
        simplify();
    }

    Fraction(const Fraction &f)
    {
        num = f.num;
        den = f.den;
        simplify();
    }

    Fraction(double x)
    {
        double intPart;
        double fracPart = modf(x, &intPart);
        long long scale = 1;

        for (int i = 0; i < 10 && fabs(fracPart) > 1e-10; i++)
        {
            x *= 10;
            scale *= 10;
            fracPart = modf(x, &intPart);
        }

        long long numerator = round(x);
        num = numerator;
        den = scale;
        simplify();
    }

    operator double() const
    {
        return static_cast<double>(num) / den;
    }

    void simplify()
    {
        long long r = gcd(num, den);
        num /= r;
        den /= r;
        if (den < 0)
        {
            den = -den;
            num = -num;
        }
    }

    friend Fraction operator+(const Fraction &a, const Fraction &b)
    {
        return Fraction(a.num * b.den + a.den * b.num, a.den * b.den);
    }

    friend Fraction operator-(const Fraction &a, const Fraction &b)
    {
        return Fraction(a.num * b.den - a.den * b.num, a.den * b.den);
    }

    friend Fraction operator*(const Fraction &a, const Fraction &b)
    {
        return Fraction(a.num * b.num, a.den * b.den);
    }

    friend Fraction operator/(const Fraction &a, const Fraction &b)
    {
        if (b.num == 0)
            throw invalid_argument("Khong duoc chia cho 0.");

        return Fraction(a.num * b.den, a.den * b.num);
    }

    friend bool operator>(const Fraction &a, const Fraction &b)
    {
        return a.num * b.den > a.den * b.num;
    }

    friend bool operator<(const Fraction &a, const Fraction &b)
    {
        return b > a;
    }

    friend bool operator==(const Fraction &a, const Fraction &b)
    {
        return a.num == b.num && a.den == b.den;
    }

    friend bool operator!=(const Fraction &a, const Fraction &b)
    {
        return !(a == b);
    }

    friend ostream &operator<<(ostream &os, const Fraction &frac)
    {
        if (frac.den != 1)
            os << frac.num << "/" << frac.den;
        else
            os << frac.num;
        return os;
    }

    friend istream &operator>>(istream &is, Fraction &frac)
    {
        char slash;
        is >> frac.num >> slash >> frac.den;
        if (frac.den == 0)
            throw invalid_argument("Mau so phai khac 0.");
        frac.simplify();
        return is;
    }
};

class DSCPhanSo
{
private:
    Fraction *f;
    int size;

public:
    explicit DSCPhanSo(int size) : size(size)
    {
        f = new Fraction[size];
    }

    ~DSCPhanSo()
    {
        if (f != NULL)
            delete[] f;
    }

    void inputFractions()
    {
        cout << "Nhap " << size << " phan so (vi du 2/3):\n";
        for (int i = 0; i < size; i++)
        {
            cout << "Phan so #" << i + 1 << ": ";
            cin >> f[i];
        }
    }

    Fraction findMax() const
    {
        Fraction MAX = f[0];
        for (int i = 1; i < size; i++)
        {
            if (f[i] > MAX)
                MAX = f[i];
        }
        return MAX;
    }

    Fraction sum() const
    {
        Fraction res(0, 1);
        for (int i = 0; i < size; i++)
            res = res + f[i];
        return res;
    }
};

int main()
{
    cout << "Nhap so luong phan so. ";
    int n;
    cin >> n;
    DSCPhanSo PhanSoArr(n);
    PhanSoArr.inputFractions();
    cout << "Tong: " << PhanSoArr.sum() << endl;
    cout << "Max: " << PhanSoArr.findMax() << endl;
    return 0;
}
