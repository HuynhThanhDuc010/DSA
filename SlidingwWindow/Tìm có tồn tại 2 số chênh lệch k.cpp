// Ý tưởng dùng set để lưu các giá trị và check xem nếu có tồn tại sô >=A[i]-t
// trong set thì tồn tại hai số có độ chênh lệch <=k.
#include <bits/stdc++.h>
using namespace std;
bool check()
{

    int n, k, t;
    cin >> n >> k >> t;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    multiset<int> s;
    for (int i = 0; i < k; i++)
    {
        auto it = s.lower_bound(A[i] - t);
        if (it != s.end() && (*it <= A[i] + t))
        {
            return true;
        }
        s.insert(A[i]);
    }
    for (int i = k; i < n; i++)
    {
        s.erase(s.find(A[i - k]));
        auto it = s.lower_bound(A[i] - t);
        if (it != s.end() && (*it <= A[i] + t))
        {
            return true;
        }
        s.insert(A[i]);
    }
    return false;
}
int main()
{
    bool kq = check();
    if (kq)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
