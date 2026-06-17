#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int nums[maxn];
int n, k;
void Try(int i)
{
    if (i == k + 1)
    {
        for (int j = 1; j <= k; j++)
        {
            cout << nums[j];
        }
        cout << "\n";
        return;
    }
    for (int j = nums[i - 1] + 1; j < n - k + i; j++)
    {
        nums[i] = j;
        Try(i + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    nums[0] = 0;
    Try(1);
}
set<vector<int>> check;
