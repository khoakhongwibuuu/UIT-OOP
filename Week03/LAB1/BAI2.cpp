#include <iostream>
using namespace std;

const long long INF = 1e9 + 7;
const int maxn = 1e5 + 5;

class circle
{
private:
	int x;
	int y;
	int r;

public:
	circle(int x = 0, int y = 0, int r = 0);
	// ~circle();
	float radius();
	float area();
	float circumference();
};

circle::circle(int x, int y, int r)
{
	this->x = x;
	this->y = y;
	this->r = r;
}

float circle::radius()
{
	return this->r;
}

float circle::circumference()
{
	return 3.14 * 2 * this->r;
}

float circle::area()
{
	return 3.14 * this->r * this->r;
}

int main()
{
	circle c(1, 2, 3);
	cout << "Radius: " << c.radius() << endl;
	cout << "Area: " << c.area() << endl;
	cout << "Circumference: " << c.circumference() << endl;
	return 0;
}
