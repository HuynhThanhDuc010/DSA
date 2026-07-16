// https://oj.vnoi.info/problem/fcb025_koddflo
#include <bits/stdc++.h>
using namespace std;
long long check(vector<long long> A, long long k)
{
    if (k < 0)
    {
        return 0;
    }
    long long left = 0, tong = 0, kq = 0;
    for (long long right = 0; right < A.size(); right++)
    {
        if (A[right] % 2 != 0)
        {
            tong++;
        }
        while (tong > k)
        {
            if (A[left] % 2 != 0)

                tong--;
            left++;
        }
        kq += right - left + 1;
    }
    return kq;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    vector<long long> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << check(A, k) - check(A, k - 1);
    return 0;
}
