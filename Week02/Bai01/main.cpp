#include <bits/stdc++.h>
using namespace std;

struct Matrix
{
    unsigned int row;
    unsigned int col;
    vector<vector<int>> data;

    Matrix(unsigned int r, unsigned int c) : row(r), col(c), data(r, vector<int>(c, 0)) {}

    Matrix operator+(const Matrix &target) const
    {
        if (row != target.row || col != target.col)
        {
            cout << "Khong the cong 2 ma tran co kich thuoc khac nhau.";
            return Matrix(0, 0);
        }
        Matrix result(row, col);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                result.data[i][j] = data[i][j] + target.data[i][j];

        return result;
    }

    Matrix operator-(const Matrix &target) const
    {
        if (row != target.row || col != target.col)
        {
            cout << "Khong the tru 2 ma tran co kich thuoc khac nhau.";
            return Matrix(0, 0);
        }
        Matrix result(row, col);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                result.data[i][j] = data[i][j] - target.data[i][j];

        return result;
    }

    Matrix operator*(const Matrix &target) const
    {
        if (col != target.row)
        {
            cout << "Khong the nhan 2 ma tran da cho.";
            return Matrix(0, 0);
        }
        Matrix result(row, target.col);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < target.col; j++)
                for (int k = 0; k < col; k++)
                    result.data[i][j] += data[i][k] * target.data[k][j];

        return result;
    }
    void input()
    {
        cout << "Nhap ma tran\n";
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                cin >> data[i][j];
    }
    void print()
    {
        for (const auto &row : data)
        {
            for (const int &val : row)
                cout << val << '\t';
            cout << endl;
        }
    }
};

int main()
{
    int ar, ac, br, bc;
    cout << "Nhap so dong cua ma tran A > ";
    cin >> ar;
    cout << "Nhap so cot cua ma tran A > ";
    cin >> ac;

    Matrix A(ar, ac);
    A.input();

    cout << "Nhap so dong cua ma tran B > ";
    cin >> br;
    cout << "Nhap so cot cua ma tran B > ";
    cin >> bc;

    Matrix B(br, bc);
    B.input();

    cout << "\nA + B = \n";
    (A + B).print();
    cout << "\nA - B = \n";
    (A - B).print();
    cout << "\nA * B = \n";
    (A * B).print();
    return 0;
}