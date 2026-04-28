// Ý tưởng dùng set để lưu các bóng bị hư ,tìm k khoảng đầu
// xem có bao nhiu bóng cần sửa, lưu kỉ lục và duyệt chó đến
// khi tìm được khoảng k liên tiếp có số bóng cần sủa nhỏ nhất.

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
        long long N, K, B;
        cin >> N >> K >> B;
        unordered_set<long long> A(B);
        for (int i = 0; i < B; i++)
        {
            long long x;
            cin >> x;
            A.insert(x);
        }
        long long cnt = 0;
        for (int i = 1; i <= K; i++)
        {
            if (A.count(i))
            {
                cnt++;
            }
        }
        long long ans = cnt;
        for (int i = K; i <= N; i++)
        {
            if (A.count(i - K))
                cnt--;
            if (A.count(i))
                cnt++;
            ans = min(cnt, ans);
        }
        cout << ans;
    }
}