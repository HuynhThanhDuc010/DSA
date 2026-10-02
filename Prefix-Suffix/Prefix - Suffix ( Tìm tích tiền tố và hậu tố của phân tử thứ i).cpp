#include <bits/stdc++.h>
// #include "lib/debug.cpp"
using namespace std;
// https://leetcode.com/problems/product-of-array-except-self/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> ans(n, 1);
    int prefix = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        ans[i] = prefix;
        prefix *= nums[i];
    }
    int suffix = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        ans[i] *= suffix;
        suffix *= nums[i];
    }
    cout << ans;
    return 0;
}