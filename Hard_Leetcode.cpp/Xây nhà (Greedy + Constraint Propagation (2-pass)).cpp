#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/maximum-building-height/description/?envType=daily-question&envId=2026-06-20
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> restrictions(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> restrictions[i][j];
        }
    }
    sort(restrictions.begin(), restrictions.end());
    if (m == 0)
    {
        return n - 1;
    }
    restrictions.push_back({1, 0});
    restrictions.push_back({n, n - 1});
    m = restrictions.size();
    sort(restrictions.begin(), restrictions.end());

    for (int i = m - 2; i >= 0; i--)
    {
        int kc = restrictions[i + 1][0] - restrictions[i][0];
        restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + kc);
    }
    for (int i = 1; i < m; i++)
    {
        int kc = restrictions[i][0] - restrictions[i - 1][0];
        restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + kc);
    }
    int ans = 0;
    for (int i = 0; i < m - 1; i++)
    {
        int kc = restrictions[i + 1][0] - restrictions[i][0];
        int mid = (restrictions[i][1] + restrictions[i + 1][1] + kc) / 2;
        ans = max(ans, mid);
    }
    cout << ans;
    return 0;
}