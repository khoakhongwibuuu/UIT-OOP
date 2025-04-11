#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

class cHocSinh
{
private:
	string id = "";
	string fullName = "";
	char gender = 0; // M or F
	int yearBorn = 0;
	float avg = 0;

public:
	void nhap()
	{
		// getline(cin, id);
		// getline(cin, fullName);
		cin >> yearBorn >> avg;
	}
	bool ageCompare(const cHocSinh &other) { return this->yearBorn > other.yearBorn; }
	bool scoreCompare(const cHocSinh &other) { return this->avg > other.avg; }
};

int main()
{
	cHocSinh A, B;
	A.nhap();
	B.nhap();
	cout << (A.ageCompare(B) ?  "A tre hon B" : "A gia hon B") << endl;
	cout << (A.scoreCompare(B) ?  "A co DTB lon hon B" : "A co DTB be hon B") << endl;
	return 0;
}