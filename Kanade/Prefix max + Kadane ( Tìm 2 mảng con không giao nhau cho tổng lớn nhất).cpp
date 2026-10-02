#include <bits/stdc++.h>
// #include "lib/debug.cpp"
using namespace std;
// https://oj.vnoi.info/problem/prefixsum_diff_e
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<long long> L(n), R(n);
    // Kadane max từ trái sang phải
    long long maxL = nums[0];
    L[0] = maxL;
    for (int i = 1; i < n; i++)
    {
        maxL = max(nums[i], maxL + nums[i]);
        L[i] = max(L[i - 1], maxL);
    }
    // Kadane max từ phải sang trái
    long long maxR = nums[n - 1];
    R[n - 1] = maxR;
    for (int i = n - 2; i >= 0; i--)
    {
        maxR = max(nums[i], maxR + nums[i]);
        R[i] = max(R[i + 1], maxR);
    }
    // Vì hai mảng con không giao nhau nên phải là L[i] và R[i+1];
    long long ans = -1e9;
    for (int i = 0; i < n - 1; i++)
    {
        ans = max(ans, L[i] + R[i + 1]);
    }
    cout << ans;

    return 0;
}