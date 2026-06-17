#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
vector<int> tmp;
// https://leetcode.com/problems/subsets/
void Try(vector<int> nums, int x)
{
    for (int i = x; i < nums.size(); i++)
    {
        tmp.push_back(nums[i]);
        ans.push_back(tmp);

        Try(nums, i + 1);
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
    ans.push_back(tmp);
    Try(nums, 0);
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