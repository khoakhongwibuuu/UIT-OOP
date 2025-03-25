#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int random(int min, int max)
{
    mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

class fraction
{
private:
    int num;
    int den;

public:
    void simplify()
    {
        int g = __gcd(num, den);
        num /= g;
        den /= g;
        if (den < 0)
        {
            num *= -1;
            den *= -1;
        }
    }
    fraction(int num = 0, int den = 1) : num(num), den(den) {}
    void Input()
    {
        char slash;
        cin >> this->num >> slash >> this->den;
        simplify();
    }
    void Output()
    {
        cout << this->num << "/" << this->den << "\n";
    }
    int getNum() const { return this->num; }
    int getDen() const { return this->den; }
};

fraction rndFraction(int maxNum = 1e3, int maxDen = 1e3, int minNum = -1e3, int minDen = 1)
{
    fraction f(random(minNum, maxNum), random(minDen, maxDen));
    f.simplify();
    return f;
}

class arrPhanSo
{
private:
    vector<fraction> vf;

public:
    unsigned int size() const { return this->vf.size(); }

    arrPhanSo(int n = 0, bool createRandomly = false)
    {
        for (int i = 0; i < n; i++)
        {
            fraction temp;
            if (createRandomly)
                temp = rndFraction();
            vf.push_back(temp);
        }
    }
    void Input()
    {
        int n;
        cout << "Nhap so luong phan so. ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap phan so thu " << i << " (vi du: 1/2). ";
            fraction f;
            f.Input();
            vf.push_back(f);
        }
    }
    void Output()
    {
        for (fraction f : vf)
            f.Output();
    }
    void Sort(bool ascending = true)
    {
        if (ascending)
            sort(this->vf.begin(), this->vf.end(), [](fraction a, fraction b)
                 { return a.getNum() * b.getDen() < a.getDen() * b.getNum(); });
        else
            sort(this->vf.begin(), this->vf.end(), [](fraction a, fraction b)
                 { return a.getNum() * b.getDen() > a.getDen() * b.getNum(); });
    }
    fraction randomAccess(int index) const
    {
        fraction a;
        if (index >= vf.size())
            return a;
        else
            return vf[index];
    }
    int countPrimeNum() const
    {
        vector<bool> prime(2001, true);
        for (int p = 2; p * p <= 2001; p++)
            if (prime[p] == true)
                for (int i = p * p; i <= 2001; i += p)
                    prime[i] = false;
        int result = 0;
        for (auto f : vf)
            result += (bool)prime[abs(f.getNum())];
        return result;
    }
};

int main()
{
    arrPhanSo exampleArray(0);
    exampleArray.Input();
    exampleArray.Output();

    int n;
    cout << "Nhap so luong phan so ngau nhien. ";
    cin >> n;
    arrPhanSo randomArray(n, true);
    randomArray.Output();

    randomArray.Sort();
    cout << "Phan so lon nhat la. ";
    randomArray.randomAccess(randomArray.size() - 1).Output();

    cout << "Co " << randomArray.countPrimeNum() << " phan so co tu so la so nguyen to.";

    cout << "Sap xep tang dan. \n";
    randomArray.Output();
    return 0;
}