#include <bits/stdc++.h>
using namespace std;
// Link bài:
// https://leetcode.com/problems/container-with-most-water/description/?envType=problem-list-v2&envId=array
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int i = 0;
    int j = n - 1;
    int Max = 0;
    while (i < j)
    {
        if (A[j] > A[i])
        {
            int tong = A[j] * (j - i);
            Max = max(Max, tong);
            i++;
        }
        else if (A[i] > A[j])
        {
            int tong = A[i] * (j - i);
            Max = max(Max, tong);
            j--;
        }
        else
        {
            int tong = A[i] * (j - i);
            Max = max(Max, tong);
            i++;
        }
    }
    cout << Max;
}