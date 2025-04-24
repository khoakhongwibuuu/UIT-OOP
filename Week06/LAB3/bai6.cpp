#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
using namespace std;

const long long INF = 1e9 + 7;

struct Date
{
	int d;
	int m;
	int y;
	Date(int d = 1, int m = 1, int y = 1) : d(d), m(m), y(y) {}
};

class Candidate
{
private:
	string name;
	string ID;
	Date DOB;
	double math;
	double literature;
	double english;

public:
	Candidate(string name = "", string ID = "", Date DOB = {1, 1, 1}, double math = 0, double literature = 0, double english = 0) : name(name), ID(ID), DOB(DOB), math(math), literature(literature), english(english)
	{
	}
	double getSum() const { return math + english + literature; }
	bool operator<(const Candidate &other) const
	{
		return this->getSum() < other.getSum();
	}
	bool operator>(const Candidate &other) const
	{
		return this->getSum() > other.getSum();
	}
	void input()
	{
		cin.ignore();
		cout << "Nhap ten. ";
		getline(cin, name);
		cout << "Nhap ID. ";
		getline(cin, ID);
		cout << "Nhap diem toan. ";
		cin >> math;
		cout << "Nhap diem van. ";
		cin >> literature;
		cout << "Nhap diem anh. ";
		cin >> english;
		// cout << "Nhap ngay sinh: ";
		// cin >> DOB.d;
		// cout << "Nhap thang sinh: ";
		// cin >> DOB.m;
		// cout << "Nhap nam sinh: ";
		// cin >> DOB.y;
	}
	void output()
	{
		cout << "{\n\tTen: " << name << "\n\tID: " << ID << "\nTong diem: " << getSum() << "\n}\n";
	}
};

class ListCandidate
{
private:
	Candidate *data;
	size_t size;

public:
	ListCandidate(size_t size = 0) : data(nullptr), size(size)
	{
		data = new Candidate[size];
	}
	~ListCandidate()
	{
		if (data != nullptr)
			delete[] data;
	}
	void sortDescending()
	{
		sort(data, data + size, greater<Candidate>());
	}
	void input()
	{
		for (int i = 0; i < size; i++)
		{
			cout << "NHAP THONG TIN HOC SINH THU " << i << endl;
			data[i].input();
		}
	}
	void output()
	{
		for (int i = 0; i < size; i++)
		{
			cout << "THONG TIN HOC SINH THU " << i << endl;
			data[i].output();
		}
	}
	Candidate getIndex(int i) const { return *(data + i); }
	bool sumGreaterThan15(const Candidate *sample) const
	{
		return sample->getSum() > 15;
	}
	void printGreaterThan15() const
	{
		for (int i = 0; i < size; i++)
			if (sumGreaterThan15(data + i))
				data[i].output();
	}
};

int main()
{
	int n;
	cin >> n;
	ListCandidate lc(n);
	lc.input();
	lc.sortDescending();
	cout << "Thi sinh co tong diem cao nhat la: ";
	lc.getIndex(0).output();
	cout << "Cac thi sinh co tong diem > 15 la: ";
	lc.printGreaterThan15();
	cout << "DS Thi sinh giam dan theo tong diem: ";
	lc.output();
	return 0;
}