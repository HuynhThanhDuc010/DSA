
// Kinh nghiệm => Đặt tong dưới main gọi lên đệ quy
// => Đề ràng buộc dùng các chữ số bất kì từ 1->9 (Không phụ thuộc vào n)
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> nums;
vector<int> tmp;
// Link bài:https://leetcode.com/problems/combination-sum-iii/submissions/2051412960/
void Check(int tong, int k, int n, int x)
{
    if (tmp.size() == k)
    {
        if (tong == n)
        {
            tong = 0;
            nums.push_back(tmp);
        }
        return;
    }
    for (int i = x; i <= 9; i++)
    {
        if (tong + i > n)
            break;
        tmp.push_back(i);
        Check(tong + i, k, n, i + 1);
        tmp.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, n;
    cin >> k >> n;
    int tong = 0;
    Check(tong, k, n, 1);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
