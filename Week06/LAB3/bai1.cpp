#include <iostream>
#include <cmath>
#include <complex>
#include <string>
#include <math.h>

using namespace std;

#define M_PI 3.14159265358979323846

bool comparator(double a, double b)
{
	return fabs(a - b) < 1e-9;
}

struct Point
{
	double x;
	double y;

	Point(double x = 0.0f, double y = 0.0f) : x(x), y(y) {}

	double distance(const Point &other) const
	{
		double X = x - other.x;
		double Y = y - other.y;
		return sqrt(pow(X, 2) + pow(Y, 2));
	}
};

class Triangle
{
private:
	Point *data;

	double sideLength(int i, int j) const
	{
		return data[i].distance(data[j]);
	}

public:
	Triangle(Point A = {0, 0}, Point B = {0, 0}, Point C = {0, 0})
		: data(nullptr)
	{
		data = new Point[3];
		data[0] = A;
		data[1] = B;
		data[2] = C;
	}
	~Triangle()
	{
		if (data != nullptr)
			delete[] data;
	}

	double Perimeter() const
	{
		return sideLength(0, 1) + sideLength(1, 2) + sideLength(2, 0);
	}

	double Area() const
	{
		double a = sideLength(0, 1);
		double b = sideLength(1, 2);
		double c = sideLength(2, 0);
		double s = Perimeter() / 2;
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}

	string TriangleType() const
	{
		double a = sideLength(0, 1);
		double b = sideLength(1, 2);
		double c = sideLength(2, 0);

		if (comparator(a, b) && comparator(b, c))
			return "Tam giac Deu";
		if (comparator(a * a + b * b, c * c) || comparator(b * b + c * c, a * a) || comparator(c * c + a * a, b * b))
			return "Tam giac Vuong";
		if (comparator(a, b) || comparator(b, c) || comparator(c, a))
			return "Tam giac Can";
		return "Tam giac thuong";
	}

	void Translate(double dx, double dy)
	{
		for (int i = 0; i < 3; ++i)
		{
			data[i].x += dx;
			data[i].y += dy;
		}
	}

	void Rotate(double deg)
	{
		double rad = deg * M_PI / 180.0;
		for (int i = 0; i < 3; ++i)
		{
			double newX = data[i].x * cos(rad) - data[i].y * sin(rad);
			double newY = data[i].x * sin(rad) + data[i].y * cos(rad);
			data[i].x = newX;
			data[i].y = newY;
		}
	}

	void Zoom(double factor)
	{
		for (int i = 0; i < 3; ++i)
		{
			data[i].x *= factor;
			data[i].y *= factor;
		}
	}

	void Input()
	{
		double a, b;
		cout << "Nhap toa do diem A. (vi du 1 0). ";
		cin >> a >> b;
		data[0] = {a, b};

		cout << "Nhap toa do diem B. (vi du 1 0). ";
		cin >> a >> b;
		data[1] = {a, b};

		cout << "Nhap toa do diem C. (vi du 1 0). ";
		cin >> a >> b;
		data[2] = {a, b};
	}

	string Output()
	{
		return "{\n\t{" + to_string(data[0].x) + "," + to_string(data[0].y) + "},\n\t{" + to_string(data[1].x) + "," + to_string(data[1].y) + "},\n\t{" + to_string(data[2].x) + "," + to_string(data[2].y) + "}\n}";
	}
};

int main()
{
	Triangle ABC({0, 0}, {1, 0}, {3, 1}); // Tam giac thuong

	// Triangle ABC({0, 0}, {1, 0}, {0.5, sqrt(3)/2}); // Tam giac deu
	// Triangle ABC({0, 0}, {1, 0}, {0.5, 3.1415926}); // Tam giac can
	// Triangle ABC({0, 0}, {1, 0}, {1, 1}); // Tam giac vuong

	ABC.Input();
	cout << "Tam giac da nhap co toa do cac diem la: \n"
		 << ABC.Output();
	cout << endl;

	cout << "Dien tich: " << ABC.Area() << endl;
	cout << "Chu vi: " << ABC.Perimeter() << endl;
	cout << "Loai tam giac: " << ABC.TriangleType() << endl;

	ABC.Rotate(90);
	cout << "Sau khi xoay 90 do nguoc chieu kim dong ho, tam giac da nhap co toa do cac diem la: \n"
		 << ABC.Output();
	cout << endl;

	ABC.Translate(1, 2);
	cout << "Sau khi tinh tien theo vector (1,2), tam giac da nhap co toa do cac diem la: \n"
		 << ABC.Output();
	cout << endl;

	ABC.Zoom(2);
	cout << "Sau khi zoom 2x, tam giac da nhap co toa do cac diem la: \n"
		 << ABC.Output();
	cout << endl;
	return 0;
}