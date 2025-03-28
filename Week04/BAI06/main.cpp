#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;
const int maxn = 1e5 + 5;

class String
{
public:
    vector<char> vc;

    String(int n = 0)
    {
        for (int i = 0; i < n; i++)
            vc.push_back(0);
    }
    ~String()
    {
        while (!vc.empty())
            vc.pop_back();
        cout << "Destructor called\n";
    }
    int strlen() const
    {
        return vc.size();
    }
    void Input()
    {
        cout << "Nhap do dai chuoi can nhap: ";
        int n;
        cin >> n;
        vc.resize(n);

        cout << "Nhap chuoi: ";
        cin.ignore();
        for (int i = 0; i < n; i++)
            cin.get(vc[i]);
    }
    void Output() const
    {
        for (char c : vc)
            cout << c;
    }
    void concat(const String &other)
    {
        vc.insert(vc.end(), other.vc.begin(), other.vc.end());
    }

    void reverse()
    {
        std::reverse(vc.begin(), vc.end());
    }
    void convertChar()
    {
        for (char &c : vc)
        {
            if ('A' <= c && c <= 'Z')
                c += 32;
            else if ('a' <= c && c <= 'z')
                c -= 32;
        }
    }
};

int main()
{
    String *s = new String(3), *r = new String(4);
    s->Input();
    s->Output();
    cout << endl;

    r->Input();
    r->Output();
    cout << endl;

    s->concat(*r);
    s->Output();
    cout << endl;

    s->reverse();
    s->Output();
    cout << endl;

    s->convertChar();
    s->Output();
    cout << endl;

    delete s;
    delete r;

    return 0;
}