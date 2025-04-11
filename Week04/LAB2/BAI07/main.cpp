#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;
const int maxn = 1e5 + 5;

class Vehicle
{
private:
    string owner;
    string type;
    int value;
    int capacity;
    static int count;

public:
    Vehicle(string owner = "", string type = "", int value = 0, int capacity = 0)
    {
        this->owner = owner;
        this->type = type;
        this->value = value;
        this->capacity = capacity;
        count++;
    }
    ~Vehicle() {}
    float getTax() const
    {
        return (capacity < 100   ? 0.01f
                : capacity < 200 ? 0.03f
                                 : 0.05f) *
               (float)value;
    }
    void print()
    {
        cout << "Thong tin xe" << "\n";
        cout << "Chu xe: " << owner << "\n";
        cout << "Loai xe: " << type << "\n";
        cout << "Gia tien: " << value << "USD\n";
        cout << "Dung tich xy-lanh: " << capacity << "cc\n";
        cout << "Tien thue truoc ba: " << getTax() << "USD\n";
    }
    void input()
    {
        cout << "Nhap chu xe: ";
        getline(cin, owner);

        cout << "Nhap loai xe: ";
        getline(cin, type);

        do
        {
            cout << "Nhap gia tien (USD): ";
            cin >> value;

            if (value < 0)
                cout << "Gia tien phai lon hon hoac bang 0. Vui long nhap lai! ";

        } while (value < 0);

        do
        {
            cout << "Nhap dung tich xy-lanh (cc): ";
            cin >> capacity;

            if (capacity < 0)
                cout << "Dung tich xy-lanh phai lon hon hoac bang 0. Vui long nhap lai! ";

        } while (capacity < 0);
    }
};

int Vehicle::count = 0;

int main()
{
    Vehicle xe1("Khoa", "HondaWave125", 500, 125);
    Vehicle xe2;
    xe2.input();
    Vehicle xe3("Dang", "WinnerX2024", 1000, 250);

    xe1.print();
    cout << endl;
    xe2.print();
    cout << endl;
    xe3.print();
    cout << endl;
    return 0;
}