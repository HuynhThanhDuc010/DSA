#include <bits/stdc++.h>
// https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/?envType=daily-question&envId=2026-07-16
using namespace std;
// Tạo 1 mảng PrefixGcd
vector<long long> HandlePrefixGcd(const vector<int> &nums)
{
    vector<long long> Prefix(nums.size());
    int curMax = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        curMax = max(curMax, nums[i]);
        Prefix[i] = __gcd(nums[i], curMax);
    }
    return Prefix;
}
// Dùng Two Poister để xử lí theo yêu cầu đề bài
long long SumGcd(vector<long long> Prefix)
{
    sort(Prefix.begin(), Prefix.end());
    int left = 0;
    int right = Prefix.size() - 1;
    long long gcdSum = 0;

    while (left < right)
    {
        gcdSum += __gcd(Prefix[left], Prefix[right]);

        left++;
        right--;
    }
    return gcdSum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<long long> Prefix = HandlePrefixGcd(nums);
    long long result = SumGcd(Prefix);
    cout << result;

    return 0;
}