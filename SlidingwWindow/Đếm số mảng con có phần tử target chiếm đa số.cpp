
#include <bits/stdc++.h>
using namespace std;
// https: // leetcode.com/problems/count-subarrays-with-majority-element-i/description/?envType=daily-question&envId=2026-06-25
int Check(int n, vector<int> nums, int target, int k)
{
    int tong = 0;
    int tmp = 0;
    for (int i = 0; i < k; i++)
    {
        if (nums[i] == target)
        {
            tmp++;
        }
    }
    int ans = tmp;
    if (ans * 2 > k)
    {
        tong++;
    }
    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i - k] == target)
            ans--;
        if (nums[i] == target)
            ans++;
        if (ans * 2 > k)
        {
            tong++;
        }
    }
    return tong;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int results = 0;
    for (int i = 1; i <= n; i++)
    {
        results += Check(n, nums, target, i);
    }
    cout << results;
}