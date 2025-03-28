#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;
const int maxn = 1e5 + 5;

#include <bits/stdc++.h>
using namespace std;

class Time
{
private:
    int SS;
    int MM;
    int HH;

public:
    Time(int SS = 0, int MM = 0, int HH = 0) : SS(SS), MM(MM), HH(HH)
    {
        fix();
    }

    bool isValid() const
    {
        return (HH >= 0 && HH < 24) && (MM >= 0 && MM < 60) && (SS >= 0 && SS < 60);
    }

    void fix()
    {

        if (SS >= 60)
        {
            MM += SS / 60;
            SS %= 60;
        }
        else if (SS < 0)
        {
            MM += (SS / 60) - 1;
            SS = (SS % 60 + 60) % 60;
        }

        if (MM >= 60)
        {
            HH += MM / 60;
            MM %= 60;
        }
        else if (MM < 0)
        {
            HH += (MM / 60) - 1;
            MM = (MM % 60 + 60) % 60;
        }

        HH = (HH % 24 + 24) % 24;
    }

    int getSeconds() const { return SS; }
    int getMinutes() const { return MM; }
    int getHours() const { return HH; }

    void setS(int s)
    {
        this->SS = s;
        fix();
    }

    void setM(int m)
    {
        this->MM = m;
        fix();
    }

    void setH(int h)
    {
        this->HH = h;
        fix();
    }

    void addS(int offset)
    {
        this->SS += offset;
        fix();
    }

    void addM(int offset)
    {
        this->MM += offset;
        fix();
    }

    void addH(int offset)
    {
        this->HH += offset;
        fix();
    }

    friend ostream &operator<<(ostream &os, const Time &t)
    {
        os << setw(2) << setfill('0') << t.HH << "-"
           << setw(2) << setfill('0') << t.MM << "-"
           << setw(2) << setfill('0') << t.SS;
        return os;
    }

    friend istream &operator>>(istream &is, Time &t)
    {
        char dash;
        is >> t.HH >> dash >> t.MM >> dash >> t.SS;
        t.fix();
        return is;
    }
};

int main()
{
    Time t;
    cout << "Nhap 1 gio bat ky, dinh dang HH/MM/SS, 24h: ";
    cin >> t;

    t.addS(1);
    cout << "1 giay sau la " << t << endl;
    t.addS(-1);
    t.addM(-2);
    cout << "2 phut truoc la " << t << endl;
    t.addM(2);
    t.addH(3);
    cout << "3 tieng la sau la " << t << endl;
    t.addH(-3);
    return 0;
}