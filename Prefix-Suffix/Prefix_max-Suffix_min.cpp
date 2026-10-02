#include <bits/stdc++.h>
// #include "lib/debug.cpp"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> Prefix_max(n);
    Prefix_max[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        Prefix_max[i] = max(Prefix_max4[i - 1], nums[i]);
    }
    vector<int> Suffix_min(n);
    Suffix_min[0] = Suffix_min[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        Suffix_min[i] = min(Suffix_min[i + 1], nums[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (Prefix_max[i] - Suffix_min[i] <= k)
            cout << i;
        return 0;
    }
    cout << "-1";
}