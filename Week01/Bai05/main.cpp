#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

class student
{
private:
    string fullName;
    float math;
    float literature;

public:
    student(string fullName = "", float math = 0.0, float literature = 0.0)
    {
        this->fullName = fullName;
        this->math = math;
        this->literature = literature;
    }
    // ~student();
    void Input();
    float avg();
    string xeploai();
};

void student::Input()
{
    cout << "Nhap ho ten day du cua hoc sinh.\n";
    getline(cin, fullName);
    cout << "Nhap diem mon toan.\n";
    cin >> math;
    cout << "Nhap diem mon van.\n";
    cin >> literature;
}

float student::avg()
{
    return (math + literature) / 2;
}

string student::xeploai()
{
    const float dtb = this->avg();
    if (dtb < 5)
        return "Yeu";
    if (dtb < 6.5)
        return "Trung Binh";
    if (dtb < 8)
        return "Kha";
    if (dtb < 9)
        return "Gioi";
    return "Xuat Sac";
}

int main()
{
    student hs;
    hs.Input();
    cout << "DTB: " << hs.avg() << endl;
    cout << "Xep Loai: " << hs.xeploai();
    return 0;
}