#include <bits/stdc++.h>
using namespace std;
// link bài: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
int bnr(vector<int> nums, int n, int target)
{
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int m = (l + r) / 2;
        if (nums[m] == target)
        {

            return m;
        }
        else if (nums[m] >= nums[l])
        {
            if (nums[l] <= target && target < nums[m])
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        else
        {
            if (nums[r] >= target && target > nums[m])
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
    }
    return -1;
}
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int kq = bnr(nums, n, target);

    cout << kq;
}