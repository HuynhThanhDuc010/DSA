#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-peak-element/description/
int BinarySearch(vector<int> &nums)
{
    int lo = 0;
    int hi = nums.size() - 1;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (mid > 0 && nums[mid] < nums[mid - 1])
        {
            hi = mid - 1;
        }
        else if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1])
        {
            lo = mid + 1;
        }
        else
        {
            return mid;
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
    cout << BinarySearch(nums);
    return 0;
}