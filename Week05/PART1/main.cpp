#include <iostream>
#include <numeric>
#include <cmath>
using namespace std;

const long long INF = 1e9 + 7;

class Fraction
{
private:
	long long num; //
	long long den; //

public:
	explicit Fraction(long long num = 0, long long den = 1) : num(num), den(den)
	{
		simplify();
	}
	explicit Fraction(double x = 0.0)
	{
		double intPart;
		double fracPart = modf(x, &intPart);
		long long scale = 1;

		for (int i = 0; i < (1 << 4) && fabs(fracPart) > 1e-9; i++)
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
		return (double)num / den;
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
		return Fraction(a.num * b.den, a.den * b.num);
	}
	friend ostream &operator<<(ostream &os, const Fraction &frac)
	{
		if (frac.den != 1)
			os << frac.num << "/" << frac.den;
		else
			os << frac.num / frac.den;
		return os;
	}
	friend istream &operator>>(istream &is, Fraction &frac)
	{
		char slash;
		is >> frac.num >> slash >> frac.den;
		return is;
	}
};

int main()
{
	double d1 = -3.125f, d2 = 3.0f;
	Fraction f1(1, 4), f2(-1, 3);
	cout << endl;

	// Test case 1
	cout << "Cong" << endl;
	cout << (Fraction)d1 + f1 << endl;
	cout << f1 + (Fraction)d1 << endl;
	cout << f1 + f2 << endl;
	cout << endl;

	cout << "Tru" << endl;
	cout << (Fraction)d1 - f1 << endl;
	cout << f1 - (Fraction)d1 << endl;
	cout << f1 - f2 << endl;
	cout << endl;

	cout << "Nhan" << endl;
	cout << (Fraction)d1 * f1 << endl;
	cout << f1 * (Fraction)d1 << endl;
	cout << f1 * f2 << endl;
	cout << endl;

	cout << "Chia" << endl;
	cout << (Fraction)d1 / f1 << endl;
	cout << f1 / (Fraction)d1 << endl;
	cout << f1 / f2 << endl;
	cout << endl;

	// Test case 2
	/*
	cout << "Cong" << endl;
	cout << (Fraction)d2 + f1 << endl;
	cout << f1 + (Fraction)d2 << endl;
	cout << f1 + f2 << endl;
	cout << endl;

	cout << "Tru" << endl;
	cout << (Fraction)d2 - f1 << endl;
	cout << f1 - (Fraction)d2 << endl;
	cout << f1 - f2 << endl;
	cout << endl;

	cout << "Nhan" << endl;
	cout << (Fraction)d2 * f1 << endl;
	cout << f1 * (Fraction)d2 << endl;
	cout << f1 * f2 << endl;
	cout << endl;

	cout << "Chia" << endl;
	cout << (Fraction)d2 / f1 << endl;
	cout << f1 / (Fraction)d2 << endl;
	cout << f1 / f2 << endl;
	*/
	return 0;
}