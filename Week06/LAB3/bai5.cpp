#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Monomial
{
	int Coeff;
	int Expo;
	Monomial(int Coeff = 0, int Expo = 0) : Coeff(Coeff), Expo(Expo) {}
	bool operator>(const Monomial &other) const
	{
		return Expo > other.Expo;
	}
	bool operator<(const Monomial &other) const
	{
		return Expo < other.Expo;
	}

	friend ostream &operator<<(ostream &os, const Monomial &term)
	{
		os << (term.Coeff >= 0 ? "+" : "") << term.Coeff << "x^" << term.Expo;
		return os;
	}

	friend istream &operator>>(istream &is, Monomial &term)
	{
		char x, exp;
		is >> term.Coeff >> x >> exp >> term.Expo;
		return is;
	}
};

class Polynomial
{
private:
	Monomial *data;
	size_t size;

public:
	Polynomial(size_t size = 0) : data(nullptr), size(size)
	{
		if (size)
			data = new Monomial[size];
	}
	~Polynomial()
	{
		if (data != nullptr)
			delete[] data;
	}
	size_t getSize() const { return size; }
	void Input()
	{
		for (size_t i = 0; i < size; i++)
			cin >> data[i];
		Merge();
	}
	void Output()
	{
		for (size_t i = 0; i < size; i++)
			cout << data[i];
	}
	void Merge()
	{
		sort(data, data + size, greater<Monomial>());

		Monomial *merged = new Monomial[size];
		size_t mergedIndex = 0;

		for (size_t i = 0; i < size; i++)
		{
			if (i < size - 1 && data[i].Expo == data[i + 1].Expo)
			{

				int combinedCoeff = data[i].Coeff;
				while (i < size - 1 && data[i].Expo == data[i + 1].Expo)
				{
					combinedCoeff += data[i + 1].Coeff;
					i++;
				}
				if (combinedCoeff != 0)
					merged[mergedIndex++] = Monomial(combinedCoeff, data[i].Expo);
			}
			else
			{
				if (data[i].Coeff != 0)
					merged[mergedIndex++] = data[i];
			}
		}

		delete[] data;
		size = mergedIndex;
		data = new Monomial[size];
		for (size_t i = 0; i < size; ++i)
			data[i] = merged[i];

		delete[] merged;
	}

	friend Polynomial operator+(const Polynomial &a, const Polynomial &b)
	{

		size_t maxSize = a.size + b.size;
		Monomial *combined = new Monomial[maxSize];
		size_t idx = 0;

		for (size_t i = 0; i < a.size; ++i)
			combined[idx++] = a.data[i];

		for (size_t i = 0; i < b.size; ++i)
			combined[idx++] = b.data[i];

		Polynomial res(maxSize);
		for (size_t i = 0; i < maxSize; ++i)
			res.data[i] = combined[i];

		delete[] combined;

		res.Merge();

		return res;
	}

	friend Polynomial operator-(const Polynomial &a, const Polynomial &b)
	{

		size_t maxSize = a.size + b.size;
		Monomial *combined = new Monomial[maxSize];
		size_t idx = 0;

		for (size_t i = 0; i < a.size; ++i)
			combined[idx++] = a.data[i];

		for (size_t i = 0; i < b.size; ++i)
			combined[idx++] = Monomial(-b.data[i].Coeff, b.data[i].Expo);

		Polynomial res(maxSize);
		for (size_t i = 0; i < maxSize; ++i)
			res.data[i] = combined[i];

		delete[] combined;

		res.Merge();
		return res;
	}
};

int main()
{
	int n;
	cout << "Nhap so luong don thuc cua da thuc A. ";
	cin >> n;
	Polynomial A(n);
	cout << "Nhap cac don thuc cua da thuc A (vi du 2x^3). \n";
	A.Input();
	cout << "Da thuc A co " << A.getSize() << " don thuc. : ";
	A.Output();
	cout << endl;
	int m;
	cout << "Nhap so luong don thuc cua da thuc B. ";
	cin >> m;
	Polynomial B(m);
	cout << "Nhap cac don thuc cua da thuc B (vi du 2x^3). \n";
	B.Input();
	cout << "Da thuc B co " << B.getSize() << " don thuc. : ";
	B.Output();
	cout << endl;

	cout << "A+B=";
	(A + B).Output();
	cout << endl;
	cout << "A-B=";
	(A - B).Output();
	return 0;
}

/*
4
2x^3
-4x^2
9x^1
8x^0
5
7x^4
-6x^3
5x^2
-4x^1
3x^0
*/