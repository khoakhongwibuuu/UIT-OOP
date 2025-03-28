#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

class Point
{
private:
	float x;
	float y;

public:
	Point(float x = 0, float y = 0)
	{
		this->x = x;
		this->y = y;
	}
	float distance(const Point &other)
	{
		float delta_x = (x - other.x);
		float delta_y = (y - other.y);
		return sqrt(delta_x * delta_x + delta_y * delta_y);
	}
	void setX(float x)
	{
		this->x = x;
	}
	void setY(float y)
	{
		this->y = y;
	}
	void changeCoordnate(float x, float y)
	{
		setX(x);
		setY(y);
	}
	float getX() const { return this->x; }
	float getY() const { return this->y; }

	friend ostream &operator<<(ostream &os, const Point &p)
	{
		os << "(" << p.x << "," << p.y << ")";
		return os;
	}

	friend istream &operator>>(istream &is, Point &p)
	{
		char comma;
		is >> p.x >> comma >> p.y;
		return is;
	}
};

int main()
{
	Point A(1, 0), B(0, 1);
	cout << A.distance(B) << endl;
	cout << A << " " << B << endl;

	A.changeCoordnate(3.14, -3.14);
	cout << A.distance(B) << endl;
	cout << A << " " << B << endl;
	return 0;
}