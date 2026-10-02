// https://leetcode.com/problems/path-existence-queries-in-a-graph-i/submissions/?envType=daily-question&envId=2026-07-09
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, maxDiff, sizeQueries;
    cin >> n >> maxDiff >> sizeQueries;
    vector<int> nums(n);
    vector<vector<int>> queries(sizeQueries, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < sizeQueries; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> queries[i][j];
        }
    }

    vector<int> prefix(n, 0);
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + (abs(nums[i - 1] - nums[i]) > maxDiff ? 1 : 0);
    }

    vector<bool> result(queries.size());
    for (int i = 0; i < sizeQueries; i++)
    {
        int lo = min(queries[i][0], queries[i][1]);
        int hi = max(queries[i][0], queries[i][1]);
        int Capxau = prefix[hi] - prefix[lo];
        if (Capxau == 0)
        {
            result[i] = true;
        }
        else
        {
            result[i] = false;
        }
    }

    for (auto it : result)
    {
        cout << it << " ";
    }
}