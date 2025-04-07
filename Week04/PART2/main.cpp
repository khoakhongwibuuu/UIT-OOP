#include <iostream>
using namespace std;

const long long INF = 1e9 + 7;

class vect
{
private:
	double *e;
	size_t size;

public:
	vect(size_t size)
	{
		this->size = size;
		e = new double[size]{};
	}
	~vect()
	{
		delete[] e;
	}
	void Input()
	{
		for (size_t i = 0; i < size; i++)
			cin >> e[i];
	}
	void Output()
	{
		cout << "(";
		for (size_t i = 0; i < size; i++)
			cout << e[i] << (i == size - 1 ? "" : ",");
		cout << ")" << endl;
	}
	size_t getSize() const { return size; }
	double access(size_t index) const { return e[index]; }
	void modify(size_t index, double value) { e[index] = value; }
};

class mat
{
private:
	double **e;
	size_t row, col;

public:
	mat(size_t row, size_t col)
	{
		this->row = row;
		this->col = col;
		e = new double *[row];
		for (size_t i = 0; i < row; i++)
			e[i] = new double[col]{};
	}
	~mat()
	{
		for (size_t i = 0; i < row; ++i)
			delete[] e[i];
		delete[] e;
	}
	void Input()
	{
		for (size_t i = 0; i < row; i++)
			for (size_t j = 0; j < col; j++)
				cin >> e[i][j];
	}
	void Output()
	{
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
				cout << e[i][j] << "\t";
			cout << endl;
		}
	}
	size_t getRow() const { return row; }
	size_t getCol() const { return col; }
	double access(size_t row, size_t col) const { return e[row][col]; }
	void modify(size_t row, size_t col, double value) { e[row][col] = value; }
};

vect multiply(const mat &A, const vect &x)
{
	if (A.getCol() != x.getSize())
		throw invalid_argument("Error: So cot cua ma tran KHAC so chieu cua vector.");

	vect result(A.getRow());

	for (size_t i = 0; i < A.getRow(); i++)
	{
		double sum = 0;
		for (size_t j = 0; j < A.getCol(); j++)
			sum += A.access(i, j) * x.access(j);
		result.modify(i, sum);
	}

	return result;
}

vect multiply(const vect &x, const mat &A)
{
	if (x.getSize() != A.getRow())
		throw invalid_argument("Error: So chieu cua vector KHAC so dong cua ma tran.");

	vect result(A.getCol());

	for (size_t j = 0; j < A.getCol(); j++)
	{
		double sum = 0;
		for (size_t i = 0; i < A.getRow(); i++)
			sum += x.access(i) * A.access(i, j);
		result.modify(j, sum);
	}

	return result;
}

int main()
{
	vect v(4);
	cout << "Nhap 1 vector 4D. ";
	v.Input();
	cout << "Vector da nhap la.\n";
	v.Output();

	mat a(3, 4), b(4, 3);
	cout << "Nhap 1 ma tran 3x4 (3 dong 4 cot).\n";
	a.Input();
	cout << "Ma tran da nhap la.\n";
	a.Output();

	cout << "Nhap 1 ma tran 4x3 (4 dong 3 cot).\n";
	b.Input();
	cout << "Ma tran da nhap la.\n";
	b.Output();

	cout << "a * v = ";
	auto result1 = multiply(a, v);
	result1.Output();

	cout << "v * b = ";
	auto result2 = multiply(v, b);
	result2.Output();
	return 0;
}