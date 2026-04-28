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
        int sum = 0;
        vector<long long> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        for (int i = 0; i < k; i++)
        {
            sum += A[i];
        }
        long long ans = sum;
        for (int i = k; i < n; i++)
        {
            sum = sum - A[i - k] + A[i];
            if (ans < sum)
            {
                ans = sum;
            }
        }
        cout << ans << "\n";
    }
}