#include <bits/stdc++.h>
// #include "lib/debug.cpp"
using namespace std;
// https://leetcode.com/problems/split-array-largest-sum/description/
int check(vector<int> &nums, int mid)
{
    int count = 0;
    int curCount = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (curCount + nums[i] <= mid)
        {
            curCount += nums[i];
        }
        else
        {
            count++;
            curCount = nums[i];
        }
    }
    return count + 1;
}
int binarySearch(vector<int> &nums, int k, int lo, int hi)
{
    int ans = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(nums, mid) <= k)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int lo = *max_element(nums.begin(), nums.end());
    int hi = accumulate(nums.begin(), nums.end(), 0);
    cout << binarySearch(nums, k, lo, hi);
    return 0;
}