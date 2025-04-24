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
struct FactoryStaff
{
private:
	string ID;
	string Name;
	Date DOB;
	double itemPrice;
	size_t itemCount;

public:
	FactoryStaff(string id = "", string name = "", Date dob = {1, 1, 1}, double itemPrice = 0.0, size_t itemCount = 0)
		: ID(id), Name(name), DOB(dob), itemPrice(itemPrice), itemCount(itemCount) {}

	string getID() const { return ID; }
	string getName() const { return Name; }
	Date getDOB() const { return DOB; }
	double getSalary() const { return itemPrice * itemCount; }
	double getItemPrice() const { return itemPrice; }
	double getItemCount() const { return itemCount; }

	void setID(const string &id) { ID = id; }
	void setName(const string &name) { Name = name; }
	void setDOB(const Date &dob) { DOB = dob; }
	void setItemPrice(const double &price) { itemPrice = price; }
	void setItemCount(const size_t &count) { itemCount = count; }

	void input()
	{
		cout << "Nhap ID Nhan vien: ";
		cin >> ID;
		cin.ignore();
		cout << "Nhap ten nhan vien: ";
		getline(cin, Name);
		cout << "Nhap ngay thang nam sinh: ";
		cin >> DOB.d >> DOB.m >> DOB.y;
		cout << "Nhap don gia san pham: ";
		cin >> itemPrice;
		cout << "Nhap so luong san pham: ";
		cin >> itemCount;
	}

	void output() const
	{
		cout << "{\n";
		cout << "\tID: " << ID << endl;
		cout << "\tTen: " << Name << endl;
		cout << "\tNgay thang nam sinh: " << DOB.d << "/" << DOB.m << "/" << DOB.y << endl;
		cout << "\tDon gia san pham: " << itemPrice << endl;
		cout << "\tSo luong san pham: " << itemCount << endl;
		cout << "}\n";
	}
};

void inputStaffArr(FactoryStaff *&staffArr, int &n)
{
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	staffArr = new FactoryStaff[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin nhan vien thu " << i << ":" << endl;
		staffArr[i].input();
	}
}

void outputStaffArr(const FactoryStaff *staffArr, int n)
{
	for (int i = 0; i < n; i++)
	{
		staffArr[i].output();
	}
}

FactoryStaff findLowestSalary(const FactoryStaff *staffArr, int n)
{
	FactoryStaff lowest = staffArr[0];
	for (int i = 1; i < n; i++)
		if (staffArr[i].getSalary() < lowest.getSalary())
			lowest = staffArr[i];
	return lowest;
}

double calculateTotalSalary(const FactoryStaff *staffArr, int n)
{
	double total = 0.0;
	for (int i = 0; i < n; i++)
		total += staffArr[i].getSalary();
	return total;
}

FactoryStaff findOldestEmployee(const FactoryStaff *staffArr, int n)
{
	FactoryStaff oldest = staffArr[0];
	for (int i = 1; i < n; i++)
		if (staffArr[i].getDOB() < oldest.getDOB())
			oldest = staffArr[i];
	return oldest;
}

void sortStaffBySalary(FactoryStaff *staffArr, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (staffArr[i].getSalary() < staffArr[j].getSalary())
				swap(staffArr[i], staffArr[j]);
}

int main()
{
	int n;
	FactoryStaff *staffArr = nullptr;
	inputStaffArr(staffArr, n);
	outputStaffArr(staffArr, n);
	cout << "Nhan vien co luong thap nhat: \n";
	findLowestSalary(staffArr, n).output();
	cout << "Tong tien luong phai tra: " << calculateTotalSalary(staffArr, n) << endl;
	cout << "Nhan vien lon tuoi nhat: \n";
	findOldestEmployee(staffArr, n).output();
	cout << "Sap xep nhan vien tang dan theo luong: \n";
	sortStaffBySalary(staffArr, n);
	outputStaffArr(staffArr, n);
	return 0;
}