#include <bits/stdc++.h>
// #include "lib/debug.cpp"
using namespace std;
// https://leetcode.com/problems/minimum-size-subarray-sum/description/

// Ý tưởng: Duyệt for cho tưng vị trí i, kiểm tra Prefix[ mid ] >= target thì cho pos = mid
//  và thu hẹp hi = mid-1. Để khi l < r tức là đã xác định đc vị trí của giá trị >=target (pos)
// thì lấy pos - i ( vị trí i đang xét hiện tại ) để ra được số phân từ có trong mảng con đó
int binarySeach(int target, int n, vector<int> &Prefix)
{
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int check = target + Prefix[i];
        int lo = i + 1;
        int hi = n;
        int pos = -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (Prefix[mid] >= check)
            {
                pos = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        if (pos != -1)
        {
            ans = min(pos - i, ans);
        }
    }
    return ans == INT_MAX ? 0 : ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> Prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        Prefix[i + 1] = Prefix[i] + nums[i];
    }
    cout << binarySeach(target, n, Prefix);
    return 0;
}