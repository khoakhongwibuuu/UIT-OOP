#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

enum Gender
{
	FEMALE = 0,
	MALE = 1
};

class CHocSinh
{
private:
	static int count;
	string ID;
	string fullName;
	bool gender;
	int yearBorn;
	float GPA;

public:
	CHocSinh(string ID = "", string fullName = "", bool gender = FEMALE, int yearBorn = 0, float GPA = 0.0f)
	{
		this->ID = ID;
		this->fullName = fullName;
		this->gender = gender;
		this->yearBorn = yearBorn;
		this->GPA = GPA;
		count++;
	}

	void Input();
	void setGPA(float newGPA);
	float getGPA() const;
	string getID() const;
	string getFullName() const;
	float compareGPA(const CHocSinh &other) const;
	int compareYear(const CHocSinh &other) const;
};

int CHocSinh::count = 0;

void CHocSinh::Input()
{
	cout << "Nhap ID cua hoc sinh: ";
	getline(cin, ID);

	cout << "Nhap ho ten day du cua hoc sinh: ";
	getline(cin, fullName);

	cout << "Nhap gioi tinh cua hoc sinh (0 - Nu, 1 - Nam): ";
	while (!(cin >> gender) || (gender != FEMALE && gender != MALE))
	{
		cout << "Gioi tinh khong hop le! Moi nhap lai (0 - Nu, 1 - Nam): ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	cout << "Nhap nam sinh cua hoc sinh: ";
	while (!(cin >> yearBorn) || yearBorn < 1900 || yearBorn > 2025)
	{
		cout << "Nam sinh khong hop le! Moi nhap lai: ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	cout << "Nhap GPA cua hoc sinh: ";
	while (!(cin >> GPA) || GPA < 0.0 || GPA > 4.0)
	{
		cout << "GPA khong hop le! Moi nhap lai (0.0 - 4.0): ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	cin.ignore();
}

void CHocSinh::setGPA(float newGPA) { this->GPA = newGPA; }
float CHocSinh::getGPA() const { return this->GPA; }
string CHocSinh::getID() const { return this->ID; }
string CHocSinh::getFullName() const { return this->fullName; }

float CHocSinh::compareGPA(const CHocSinh &other) const { return this->GPA - other.GPA; }
int CHocSinh::compareYear(const CHocSinh &other) const { return this->yearBorn - other.yearBorn; }

int main()
{
	CHocSinh hsA, hsB;
	hsA.Input();
	hsB.Input();
	int yearDiff = hsA.compareYear(hsB);
	float GPADiff = hsA.compareGPA(hsB);
	cout << yearDiff << " " << GPADiff << endl;
	cout << hsA.getFullName() << (yearDiff < 0.0f ? " lon tuoi hon " : (yearDiff > 0.0f ? " nho tuoi hon " : " bang tuoi ")) << hsB.getFullName() << endl;
	cout << hsA.getFullName() << (GPADiff < 0.0f ? " co GPA thap hon " : (GPADiff > 0.0f ? " co GPA cao hon " : " co GPA bang ")) << hsB.getFullName() << endl;
	return 0;
}