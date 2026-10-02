#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> nums2 = nums;
    sort(nums2.begin(), nums2.end());
    nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end()); // Nếu nén về rank dãy số liên tục thì dùng

    for (auto &it : nums)
    {
        it = lower_bound(nums2.begin(), nums2.end(), it) - nums2.begin() + 1; // +1 để bắt đầu từ 1
        cout << it << " ";
    }

    return 0;
}