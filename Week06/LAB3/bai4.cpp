#include <iostream>
#include <algorithm>
#include <random>
#include <cmath>
using namespace std;

const long long INF = 1e9 + 7;

bool isPrime(int num)
{
	if (num <= 1)
		return false;
	for (int i = 2; i <= sqrt(num); ++i)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

class Array
{
private:
	int *data;
	size_t size;

public:
	Array(size_t size = 0) : data(nullptr), size(size)
	{
		if (size > 0)
			data = new int[size];
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(-1e6, 1e6);
		for (size_t i = 0; i < size; ++i)
			data[i] = dis(gen);
	}

	~Array()
	{
		if (data != nullptr)
			delete[] data;
	}

	size_t getsize() const { return size; }

	void Print()
	{
		for (int i = 0; i < size; i++)
			cout << data[i] << " ";
		cout << endl;
	}

	int countFreq(int x) const
	{
		return count(data, data + size, x);
	}

	bool isAscending() const
	{
		for (size_t i = 1; i < size; ++i)
		{
			if (data[i] < data[i - 1])
				return false;
		}
		return true;
	}

	int minOdd() const
	{
		int smallestOdd = INF;
		for (size_t i = 0; i < size; ++i)
		{
			if (data[i] % 2 != 0 && data[i] < smallestOdd)
				smallestOdd = data[i];
		}
		return (smallestOdd == INF) ? -1 : smallestOdd;
	}

	int maxPrime() const
	{
		int largestPrime = -1;
		for (size_t i = 0; i < size; ++i)
		{
			if (isPrime(data[i]) && data[i] > largestPrime)
				largestPrime = data[i];
		}
		return largestPrime;
	}

	void quickSort(int l, int r)
	{
		if (l >= r)
			return;
		int pivot = data[r];
		int i = l - 1;
		for (int j = l; j < r; ++j)
		{
			if (data[j] <= pivot)
				swap(data[++i], data[j]);
		}
		swap(data[i + 1], data[r]);
		quickSort(l, i);
		quickSort(i + 2, r);
	}

	void mergeSort(int l, int r)
	{
		if (l >= r)
			return;
		int mid = l + (r - l) / 2;
		mergeSort(l, mid);
		mergeSort(mid + 1, r);
		vector<int> temp;
		int i = l, j = mid + 1;
		while (i <= mid && j <= r)
		{
			if (data[i] <= data[j])
				temp.push_back(data[i++]);
			else
				temp.push_back(data[j++]);
		}
		while (i <= mid)
			temp.push_back(data[i++]);
		while (j <= r)
			temp.push_back(data[j++]);
		for (int k = l; k <= r; ++k)
			data[k] = temp[k - l];
	}

	void sortAscending()
	{
		quickSort(0, size - 1);
		// mergeSort(0, size - 1);
	}

	void sortDescending()
	{
		sort(data, data + size, greater<int>());
	}
};

int main()
{
	int n;
	cin >> n;
	Array arr(n);
	arr.Print();

	int x = 231234;
	cout << x << " xuat hien " << arr.countFreq(x) << " lan trong mang.\n";

	cout << (!arr.isAscending() ? "mang ko tang dan" : "mang tang dan") << endl;

	cout << "So le nho nhat: " << arr.minOdd() << endl;
	int tmp = arr.maxPrime();
	cout << "So NT lon nhat: " << (tmp == -1 ? "ko ton tai" : to_string(tmp)) << endl;

	cout << "Sap xep tang dan\n";
	arr.sortAscending();
	arr.Print();
	cout << (!arr.isAscending() ? "mang ko tang dan" : "mang tang dan") << endl;
	cout << "Sap xep giam dan\n";
	arr.sortDescending();
	arr.Print();
	return 0;
}