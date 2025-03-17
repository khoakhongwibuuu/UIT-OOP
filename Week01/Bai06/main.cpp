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
    cin.ignore();
    getline(cin, fullName);
    cout << "Nhap diem mon toan.\n";
    cin >> math;
    cout << "Nhap diem mon van.\n";
    cin.ignore();
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
        return "Yeu\n";
    if (dtb < 6.5)
        return "Trung Binh\n";
    if (dtb < 8)
        return "Kha\n";
    if (dtb < 9)
        return "Gioi\n";
    return "Xuat Sac\n";
}

int main()
{
    int n;
    float maxAvg = -INF, minAvg = INF;
    cout << "Nhap so luong HS: ";
    cin >> n;
    student hs[127];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin HS thu " << i + 1 << ":\n";
        hs[i].Input();
        float avg = hs[i].avg();
        maxAvg = max(maxAvg, avg);
        minAvg = min(minAvg, avg);
    }
    cout << "DTB_max = " << maxAvg << endl;
    cout << "DTB_min = " << minAvg;

    // hs.Input();
    // cout << "DTB: " << hs.avg() << endl;
    // cout << "Xep Loai: " << hs.xeploai();
    return 0;
}