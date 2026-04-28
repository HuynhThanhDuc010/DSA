//  Ý tưởng duyệt mảng để tìm số phần tử <=k
// dựa vào đó làm khoảng để xét những vị trí khác,
// ta lấy max để tìm đc số lần đổi chỗ nhỏ nhất,
// kết quả bằng (số pt<=k) - (khoảng có nhìu số<=k nhất).
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        long long n, k;
        cin >> n >> k;
        long long sum = 0;
        vector<long long> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
            if (A[i] <= k)
            {
                sum++;
            }
        }
        long long res = 0;
        for (int i = 0; i < sum; i++)
        {
            if (A[i] <= k)
                res++;
        }
        long long ans = res;
        for (int i = sum; i < n; i++)
        {
            if (A[i - sum] <= k)
                res--;
            if (A[i] <= k)
                res++;
            ans = max(res, ans);
        }
        cout << sum - ans << "\n";
    }
}