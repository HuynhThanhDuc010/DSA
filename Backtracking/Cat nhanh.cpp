#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
vector<int> tmp;
int n, k;
void Try(int x)
{
    if (tmp.size() == k)
    {
        ans.push_back(tmp);
        return;
    }
    int need = k - tmp.size();
    for (int i = x; i <= n - need + 1; i++)
    {
        tmp.push_back(i);
        Try(i + 1);
        tmp.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    long long total = 1;
    for (int i = 1; i <= k; i++)
    {
        total = total * (n - i + 1) / i;
    }
    ans.reserve(total);
    tmp.reserve(k);
    Try(1);
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