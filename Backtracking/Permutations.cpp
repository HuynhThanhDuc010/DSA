#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
vector<int> tmp;
// https://leetcode.com/problems/permutations/description/
void Try(vector<int> nums)
{
    if (nums.empty())
    {
        ans.push_back(tmp);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        tmp.push_back(nums[i]);
        vector<int> next = nums;
        next.erase(next.begin() + i);
        Try(next);
        tmp.pop_back();
    }
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
    sort(nums.begin(), nums.end());
    Try(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}