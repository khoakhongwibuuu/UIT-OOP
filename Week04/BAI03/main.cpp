#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

class complx
{
private:
	float real;
	float imaginary;

public:
	complx(float real = 0, float imaginary = 0) : real(real), imaginary(imaginary) {}

	float getReal() { return this->real; }
	float getImg() { return this->imaginary; }

	void setReal(float newReal) { this->real = newReal; }
	void setImg(float newImg) { this->imaginary = newImg; }

	complx operator+(const complx &other) const
	{
		return complx(real + other.real, imaginary + other.imaginary);
	}

	complx operator-(const complx &other) const
	{
		return complx(real - other.real, imaginary - other.imaginary);
	}

	complx operator*(const complx &other) const
	{
		return complx(real * other.real - imaginary * other.imaginary, real * other.imaginary + imaginary * other.real);
	}

	complx operator/(const complx &other) const
	{
		float denominator = other.real * other.real + other.imaginary * other.imaginary;
		return complx((real * other.real + imaginary * other.imaginary) / denominator, (imaginary * other.real - real * other.imaginary) / denominator);
	}

	complx operator+() const
	{
		return *this;
	}

	complx operator-() const
	{
		return complx(-real, -imaginary);
	}

	void print()
	{
		if (real != 0)
		{
			cout << real;
			if (imaginary > 0)
				cout << "+";
		}

		if (imaginary != 0)
		{
			if (abs(imaginary) != 1)
				cout << imaginary << "i";
			else
				cout << (imaginary == 1 ? "i" : "-i");
		}

		if (!real && !imaginary)
			cout << 0;
		cout << endl;
	}
};

int main()
{
	complx a(0, 0), b(0, 0);
	int ar, ai, br, bi;
	cin >> ar >> ai >> br >> bi;
	a.setReal(ar);
	b.setReal(br);
	a.setImg(ai);
	b.setImg(bi);
	cout << "a = ";
	a.print();
	cout << endl;
	cout << "b = ";
	b.print();
	cout << endl;
	cout << "a + b = ";
	(a + b).print();
	cout << endl;
	cout << "a - b = ";
	(a - b).print();
	cout << endl;
	cout << "a * b = ";
	(a * b).print();
	cout << endl;
	cout << "a / b = ";
	(a / b).print();
	return 0;
}