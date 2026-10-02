#include <bits/stdc++.h>
// #include "lib/debug.cpp"
using namespace std;
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/
int Check(vector<vector<int>> &matrix, int mid)
{
    int col = 0;
    int row = matrix.size() - 1;
    int count = 0;
    while (col < matrix.size() && row >= 0)
    {
        if (matrix[row][col] <= mid)
        {
            count += row + 1;
            col++;
        }
        else
        {
            row--;
        }
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int lo = matrix[0][0];

    int hi = matrix[n - 1][n - 1];
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (Check(matrix, mid) < k)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    cout << lo;
    return 0;
}