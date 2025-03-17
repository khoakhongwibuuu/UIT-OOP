#include <bits/stdc++.h>
using namespace std;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int h)
{
	if (l > h)
		swap(l, h);
	assert(l <= h);

	return l + rd() * rd() % (h - l + 1);
}

const long long INF = 1e9 + 7;

class cArray
{
private:
	vector<int> data;

public:
	cArray(int n = 0);
	void print();
	int findMaxNegative();
	int countAppearance(int x);
	bool isDecreasing();
	void sort();
	// ~cArray();
};

cArray::cArray(int n)
{
	for (int i = 0; i < n; i++)
		data.push_back(Rand(-16, 15));
}

void cArray::print()
{
	for (auto i : data)
		cout << i << " ";
	cout << endl;
}

int cArray::findMaxNegative()
{
	int result = data[0];
	for (auto i : data)
		if (i < 0)
			result = max(i, result);
	return result;
}

int cArray::countAppearance(int x)
{
	int result = 0;
	for (auto i : data)
		result += (i == x);
	return result;
}

bool cArray::isDecreasing()
{
	int *prev = &data[0];
	for (int i = 1; i < data.size(); i++)
	{
		if (*prev < data[i])
			return false;
		prev = &data[i];
	}
	return true;
}

void cArray::sort()
{
	std::sort(data.begin(), data.end());
}

int main()
{
	int n;
	cout << "Nhap so luong phan tu cua mang. ";
	cin >> n;
	cArray sample(n);
	sample.print();
	cout << "so am lon nhat la " << sample.findMaxNegative() << endl;
	int x;
	cout << "Nhap x. ";
	cin >> x;
	cout << "x xuat hien " << sample.countAppearance(x) << " lan" << endl;
	cout << (sample.isDecreasing() ? "Day giam dan" : "Day khong giam dan") << endl;
	sample.sort();
	cout << "Day sau khi sap xep tang dan. ";
	sample.print();
	return 0;
}