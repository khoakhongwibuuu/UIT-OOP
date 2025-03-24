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
        if (num < 0)
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
};

fraction rndFraction(int maxNum = INF, int maxDen = INF, int minNum = -INF, int minDen = 1)
{
    fraction f(random(minNum, maxNum), random(minDen, maxDen));
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
        fraction temp(0, 1);
        for (int i = 0; i < n; i++)
            if (!createRandomly)
                vf.push_back(temp);
            else
                vf.push_back(rndFraction());
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

    
    return 0;
}