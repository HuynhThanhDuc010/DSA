#include <bits/stdc++.h>
using namespace std;
bool kq()
{
    long long n, k;
    cin >> n >> k;
    set<long long> s;
    vector<long long> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < k; i++)
    {
        if (s.count(A[i]))
        {
            return true;
        }
        s.insert(A[i]);
    }
    for (int i = k; i < n; i++)
    {
        s.erase(i - k);
        if (s.count(A[i]))
        {
            return true;
        }
        s.insert(A[i]);
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        if (kq())
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
}
