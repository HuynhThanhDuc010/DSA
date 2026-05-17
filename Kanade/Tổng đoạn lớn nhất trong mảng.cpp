#include <bits/stdc++.h>
using namespace std;
// Link bài:
// https://leetcode.com/problems/maximum-subarray/?envType=problem-list-v2&envId=array
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
    int Max = -1e6;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += A[i];
        Max = max(Max, ans);
        if (ans < 0)
        {
            ans = 0;
        }
    }
    cout << Max;
}
