#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

class Point
{
private:
	float x;
	float y;

public:
	Point(float x = 0, float y = 0);
	// ~Point();
	float distance(const Point &other);
};

Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Point::distance(const Point &other)
{
	float delta_x = (x - other.x);
	float delta_y = (y - other.y);
	return sqrt(delta_x * delta_x + delta_y * delta_y);
}

int main()
{
	Point A(1, 0), B(0, 1);
	cout << A.distance(B);
	return 0;
}