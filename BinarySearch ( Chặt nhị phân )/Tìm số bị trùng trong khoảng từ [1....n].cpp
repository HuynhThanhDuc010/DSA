#include <bits/stdc++.h>
// #include "lib/debug.cpp"
using namespace std;
// https://leetcode.com/problems/find-the-duplicate-number/description/
int Binary(vector<int> &nums)
{
    int lo = 1;
    int hi = nums.size() - 1;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        int count = 0;
        for (auto it : nums)
        {
            if (it <= mid)
                count++;
        }
        if (count > mid)
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return lo;
}
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
    cout << Binary(nums);
    return 0;
}