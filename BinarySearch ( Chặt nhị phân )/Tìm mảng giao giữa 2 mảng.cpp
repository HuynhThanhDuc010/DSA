// https://leetcode.com/problems/intersection-of-two-arrays-ii/
//  Lưu ý nếu test case lớn thì dùng => unordered_map
#include <bits/stdc++.h>
using namespace std;
bool Binary(vector<int> &nums2, int x)
{
    int l = 0;
    int r = nums2.size() - 1;
    while (l <= r)
    {

        int m = (l + r) / 2;
        if (nums2[m] == x)
        {
            nums2.erase(nums2.begin() + m);
            return true;
        }
        else if (nums2[m] < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    for (auto &v : nums1)
        cin >> v;
    for (auto &v : nums2)
        cin >> v;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> ans;
    for (int x : nums1)
    {
        if (nums2.empty())
            break;
        bool check = Binary(nums2, x);
        if (check)
        {
            ans.push_back(x);
        }
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}