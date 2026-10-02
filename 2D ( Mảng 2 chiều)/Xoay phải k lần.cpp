#include <bits/stdc++.h>
// #include "lib/debug.cpp"
using namespace std;
// https://leetcode.com/problems/shift-2d-grid/submissions/2074359603/?envType=daily-question&envId=2026-07-20
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int size2D = n * m;

    vector<vector<int>> ans(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int index = i * m + j;              // Đưa về mảng 1D lấy idex 1D
            int newIdex = (index + k) % size2D; // Lấy idex mới khi xoay phải k lần
            int newI = newIdex / m;             // Chuyển về lại idexI ( Hàng ) của mảng 2D từ index mới của mảng 1D
            int newJ = newIdex % m;             // Chuyển về lại idexI ( Cột ) của mảng 2D từ index mới của mảng 1D
            ans[newI][newJ] = grid[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}