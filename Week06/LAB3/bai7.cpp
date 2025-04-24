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
	bool operator==(const Date &other)
	{
		return (d == other.d && m == other.m && y == other.y);
	}
	bool operator!=(const Date &other)
	{
		return !(*this == other);
	}
	bool operator>(const Date &other)
	{
		return (y > other.y) || (y == other.y && m > other.m) || (y == other.y && m == other.m && d > other.d);
	}
	bool operator<(const Date &other)
	{
		return *this != other && !(*this > other);
	}
};
struct OfficeStaff
{
private:
	string ID;
	string Name;
	Date DOB;
	double salary;

public:
	OfficeStaff(string id = "", string name = "", Date dob = {1, 1, 1}, double sal = 0.0)
		: ID(id), Name(name), DOB(dob), salary(sal) {}

	string getID() const { return ID; }
	string getName() const { return Name; }
	Date getDOB() const { return DOB; }
	double getSalary() const { return salary; }

	void setID(const string &id) { ID = id; }
	void setName(const string &name) { Name = name; }
	void setDOB(const Date &dob) { DOB = dob; }
	void setSalary(double sal) { salary = sal; }

	void input()
	{
		cout << "Nhap ID Nhan vien: ";
		cin >> ID;
		cin.ignore();
		cout << "Nhap ten nhan vien: ";
		getline(cin, Name);
		cout << "Nhap ngay thang nam sinh: ";
		cin >> DOB.d >> DOB.m >> DOB.y;
		cout << "Nhap luong: ";
		cin >> salary;
	}

	void output() const
	{
		cout << "{\n";
		cout << "\tID: " << ID << endl;
		cout << "\tTen: " << Name << endl;
		cout << "\tNgay thang nam sinh: " << DOB.d << "/" << DOB.m << "/" << DOB.y << endl;
		cout << "\tLuong: " << salary << endl;
		cout << "}\n";
	}
};

void inputStaffArr(OfficeStaff *&staffArr, int &n)
{
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	staffArr = new OfficeStaff[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin nhan vien thu " << i << ":" << endl;
		staffArr[i].input();
	}
}

void outputStaffArr(const OfficeStaff *staffArr, int n)
{
	for (int i = 0; i < n; i++)
	{
		staffArr[i].output();
	}
}

OfficeStaff findHighestSalary(const OfficeStaff *staffArr, int n)
{
	OfficeStaff highest = staffArr[0];
	for (int i = 1; i < n; i++)
		if (staffArr[i].getSalary() > highest.getSalary())
			highest = staffArr[i];
	return highest;
}

double calculateTotalSalary(const OfficeStaff *staffArr, int n)
{
	double total = 0.0;
	for (int i = 0; i < n; i++)
		total += staffArr[i].getSalary();
	return total;
}

OfficeStaff findOldestEmployee(const OfficeStaff *staffArr, int n)
{
	OfficeStaff oldest = staffArr[0];
	for (int i = 1; i < n; i++)
		if (staffArr[i].getDOB() < oldest.getDOB())
			oldest = staffArr[i];
	return oldest;
}

void sortStaffBySalary(OfficeStaff *staffArr, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (staffArr[i].getSalary() > staffArr[j].getSalary())
				swap(staffArr[i], staffArr[j]);
}

int main()
{
	int n;
	OfficeStaff *staffArr = nullptr;
	inputStaffArr(staffArr, n);
	outputStaffArr(staffArr, n);
	cout << "Nhan vien co luong cao nhat: \n";
	findHighestSalary(staffArr, n).output();
	cout << "Tong tien luong phai tra: " << calculateTotalSalary(staffArr, n) << endl;
	cout << "Nhan vien lon tuoi nhat: \n";
	findOldestEmployee(staffArr, n).output();
	cout << "Sap xep nhan vien tang dan theo luong: \n";
	sortStaffBySalary(staffArr, n);
	outputStaffArr(staffArr, n);
	return 0;
}