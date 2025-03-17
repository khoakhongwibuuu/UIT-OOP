#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;
const int maxn = 1e5 + 5;

class Date
{
private:
    int DD;
    int MM;
    int YYYY;

public:
    Date(int DD = 0, int MM = 0, int YYYY = 0) : DD(DD), MM(MM), YYYY(YYYY)
    {
    }

    bool isLeapYear(int year) const
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysInMonth(int month, int year) const
    {
        const int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && isLeapYear(year))
            return 29;
        return daysPerMonth[month - 1];
    }

    bool isValid() const
    {
        if (YYYY < 1)
            return false;
        if (MM < 1 || MM > 12)
            return false;
        if (DD < 1 || DD > daysInMonth(MM, YYYY))
            return false;
        return true;
    }

    void fix()
    {

        if (MM < 1)
        {
            MM = 12;
            YYYY--;
        }
        if (MM > 12)
        {
            MM = 1;
            YYYY++;
        }

        while (DD > daysInMonth(MM, YYYY))
        {
            DD -= daysInMonth(MM, YYYY);
            MM++;

            if (MM > 12)
            {
                MM = 1;
                YYYY++;
            }
        }

        while (DD <= 0)
        {
            MM--;
            if (MM < 1)
            {
                MM = 12;
                YYYY--;
            }
            DD += daysInMonth(MM, YYYY);
        }
    }

    string getDayOfWeek()
    {
        int day = this->DD;
        int month = this->MM;
        int year = this->YYYY;
        if (month == 1 || month == 2)
        {
            month += 12;
            year--;
        }

        int K = year % 100;
        int J = year / 100;
        int h = (day + (13 * (month + 1)) / 5 + K + (K / 4) + (J / 4) + (5 * J)) % 7;

        string days[] = {"Thu 7", "Chu Nhat", "Thu 2", "Thu 3", "Thu 4", "Thu 5", "Thu 6"};

        return days[h];
    }

    friend ostream &operator<<(ostream &os, const Date &d)
    {
        os << d.YYYY << "/" << setw(2) << setfill('0') << d.MM << "/" << setw(2) << setfill('0') << d.DD;
        return os;
    }

    friend istream &operator>>(istream &is, Date &d)
    {
        char slash;
        is >> d.YYYY >> slash >> d.MM >> slash >> d.DD;
        return is;
    }
};

int main()
{
    Date d;
    cout << "Nhap 1 ngay bat ky, dinh dang YYYY/MM/DD: ";
    cin >> d;
    if (!d.isValid())
        cout << "Ngay da nhap ko hop le";
    else
        cout << d.getDayOfWeek();
    return 0;
}