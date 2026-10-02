#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nums[i][j];
        }
    }

    vector<vector<long long>> Prefix(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            Prefix[i][j] = nums[i - 1][j - 1] + Prefix[i - 1][j] + Prefix[i][j - 1] - Prefix[i - 1][j - 1];
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << Prefix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}