#include <bits/stdc++.h>
// #include "lib/debug.cpp"
// https://leetcode.com/problems/longest-increasing-subsequence/description/
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = 0;
    for (i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }
    return ans;
    return 0;
}