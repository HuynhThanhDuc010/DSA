// Ý tưởng tính tổng dãy n ban đầu
// sau đó cộng tổng các phép XOR của
// các dãy lại với nhau
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long k, n;
    cin >> k >> n;
    long long x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<long long> arr(k);
    arr[0] = x;
    for (int i = 1; i < k; i++)
    {
        arr[i] = (a * arr[i - 1] + b) % c;
    }
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    long long res = sum;
    for (int i = n; i < k; i++)
    {
        sum = sum - arr[i - n];
        sum += arr[i];
        res ^= sum;
    }
    cout << res;
}