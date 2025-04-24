#include <iostream>
#include <numeric>
#include <cmath>
#include <stdexcept>
#include <algorithm>

using namespace std;

#define nhập cin
#define xuất cout
#define XuốngDòng endl
#define Hằng const

void sieve(int *is_prime, int n)
{
	for (int i = 0; i < n; i++)
		is_prime[i] = 1;
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++)
	{
		if (is_prime[i] && (long long)i * i <= n)
		{
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
}

class PhânSố
{
private:
	long long TửSố;
	long long MẫuSố;

public:
	explicit PhânSố(long long TửSố = 0, long long MẫuSố = 1) : TửSố(TửSố), MẫuSố(MẫuSố)
	{
		if (MẫuSố == 0)
			throw invalid_argument("Mau so khong duoc bang 0.");
		simplify();
	}

	explicit PhânSố(double x)
	{
		double intPart;
		double fracPart = modf(x, &intPart);
		long long scale = 1;

		for (int i = 0; i < (1 << 4) && fabs(fracPart) > 1e-9; i++)
		{
			x *= 10;
			scale *= 10;
			fracPart = modf(x, &intPart);
		}

		TửSố = round(x);
		MẫuSố = scale;
		simplify();
	}

	operator double() Hằng
	{
		return static_cast<double>(TửSố) / MẫuSố;
	}

	void simplify()
	{
		long long r = gcd(abs(TửSố), abs(MẫuSố));
		TửSố /= r;
		MẫuSố /= r;
		if (MẫuSố < 0)
		{
			MẫuSố = -MẫuSố;
			TửSố = -TửSố;
		}
	}

	long long LấyTửSố() const { return TửSố; }
	long long LấyMẫuSố() const { return MẫuSố; }

	friend PhânSố operator+(Hằng PhânSố &a, Hằng PhânSố &b)
	{
		return PhânSố(a.TửSố * b.MẫuSố + a.MẫuSố * b.TửSố, a.MẫuSố * b.MẫuSố);
	}

	friend PhânSố operator-(Hằng PhânSố &a, Hằng PhânSố &b)
	{
		return PhânSố(a.TửSố * b.MẫuSố - a.MẫuSố * b.TửSố, a.MẫuSố * b.MẫuSố);
	}

	friend PhânSố operator*(Hằng PhânSố &a, Hằng PhânSố &b)
	{
		return PhânSố(a.TửSố * b.TửSố, a.MẫuSố * b.MẫuSố);
	}

	friend PhânSố operator/(Hằng PhânSố &a, Hằng PhânSố &b)
	{
		if (b.TửSố == 0)
			throw invalid_argument("Khong duoc chia cho 0.");
		return PhânSố(a.TửSố * b.MẫuSố, a.MẫuSố * b.TửSố);
	}

	PhânSố &operator+=(Hằng PhânSố &PhầnCònLại)
	{
		TửSố = TửSố * PhầnCònLại.MẫuSố + MẫuSố * PhầnCònLại.TửSố;
		MẫuSố *= PhầnCònLại.MẫuSố;
		simplify();
		return *this;
	}

	PhânSố &operator-=(Hằng PhânSố &PhầnCònLại)
	{
		TửSố = TửSố * PhầnCònLại.MẫuSố - MẫuSố * PhầnCònLại.TửSố;
		MẫuSố *= PhầnCònLại.MẫuSố;
		simplify();
		return *this;
	}

	PhânSố &operator*=(Hằng PhânSố &PhầnCònLại)
	{
		TửSố *= PhầnCònLại.TửSố;
		MẫuSố *= PhầnCònLại.MẫuSố;
		simplify();
		return *this;
	}

	PhânSố &operator/=(Hằng PhânSố &PhầnCònLại)
	{
		if (PhầnCònLại.TửSố == 0)
			throw invalid_argument("Mau so khong duoc bang 0.");

		TửSố *= PhầnCònLại.MẫuSố;
		MẫuSố *= PhầnCònLại.TửSố;
		simplify();
		return *this;
	}

	friend ostream &operator<<(ostream &os, Hằng PhânSố &frac)
	{
		if (frac.MẫuSố != 1)
			os << frac.TửSố << "/" << frac.MẫuSố;
		else
			os << frac.TửSố;
		return os;
	}

	friend istream &operator>>(istream &is, PhânSố &frac)
	{
		char slash;
		is >> frac.TửSố >> slash >> frac.MẫuSố;
		if (frac.MẫuSố == 0)
			throw invalid_argument("Mau so khong duoc bang 0.");

		frac.simplify();
		return is;
	}

	friend bool operator==(Hằng PhânSố a, Hằng PhânSố b)
	{
		return (a - b) != 0;
	}

	friend bool operator!=(Hằng PhânSố a, Hằng PhânSố b)
	{
		return !(a == b);
	}

	friend bool operator>(Hằng PhânSố a, Hằng PhânSố b)
	{
		return (a - b) > 0;
	}

	friend bool operator<(Hằng PhânSố a, Hằng PhânSố b)
	{
		return b > a;
	}

	friend bool operator>=(Hằng PhânSố a, Hằng PhânSố b)
	{
		return !(a < b);
	}

	friend bool operator<=(Hằng PhânSố a, Hằng PhânSố b)
	{
		return !(a > b);
	}
};

class MảngPhânSố
{
private:
	PhânSố *DữLiệu;
	size_t size;

public:
	MảngPhânSố(size_t size = 0) : DữLiệu(nullptr), size(size)
	{
		if (size > 0)
			DữLiệu = new PhânSố[size];
	}

	~MảngPhânSố()
	{
		if (DữLiệu != nullptr)
			delete[] DữLiệu;
	}

	size_t LấyKíchThước() Hằng { return size; }

	void Nhập() Hằng
	{
		for (int i = 0; i < LấyKíchThước(); i++)
		{
			xuất << "Nhap phan so thu " << i << ", vi du 1/2.  ";
			nhập >> DữLiệu[i];
		}
	}

	void Xuất() Hằng
	{
		for (int i = 0; i < LấyKíchThước(); i++)
			xuất << "#" << i << ": " << DữLiệu[i] << XuốngDòng;
	}

	PhânSố TínhTổng() Hằng
	{
		PhânSố res;
		for (int i = 0; i < LấyKíchThước(); i++)
			res += DữLiệu[i];
		return res;
	}

	PhânSố TìmLớnNhất() Hằng
	{
		PhânSố res = *DữLiệu;
		for (int i = 1; i < LấyKíchThước(); i++)
			res = max(res, *(DữLiệu + i));
		return res;
	}

	PhânSố TìmNhỏNhất() Hằng
	{
		PhânSố res = *DữLiệu;
		for (int i = 1; i < LấyKíchThước(); i++)
			res = min(res, *(DữLiệu + i));
		return res;
	}

	void SắpXếpTăngDần()
	{
		sort(DữLiệu, DữLiệu + LấyKíchThước());
	}

	void SắpXếpGiảmDần()
	{
		sort(DữLiệu, DữLiệu + LấyKíchThước(), greater<PhânSố>());
	}

	PhânSố TìmTửNguyênTốLớnNhất(int *prime) Hằng
	{
		for (int i = 0; i < LấyKíchThước(); i++)
			if (prime[DữLiệu[i].LấyTửSố()])
				return DữLiệu[i];

		// Không tìm thấy
		return (PhânSố)-1.0;
	}
};

int main()
{

	cout << "Nhap so luong phan so: ";
	int n;
	nhập >> n;
	MảngPhânSố mảng(n);
	mảng.Nhập();
	mảng.Xuất();
	xuất << "Tong: " << mảng.TínhTổng() << XuốngDòng;
	xuất << "Max: " << mảng.TìmLớnNhất() << XuốngDòng;
	xuất << "Min: " << mảng.TìmNhỏNhất() << XuốngDòng;

	mảng.SắpXếpTăngDần();
	cout << "Sap xep tang dan: \n";
	mảng.Xuất();

	mảng.SắpXếpGiảmDần();
	cout << "Sap xep giam dan: \n";
	mảng.Xuất();

	int *prime = new int[10000];
	sieve(prime, 10000);
	cout << "Phan so co tu nguyen to lon nhat: " << mảng.TìmTửNguyênTốLớnNhất(prime) << XuốngDòng;
	return 0;
}
