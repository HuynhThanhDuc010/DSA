#include <bits/stdc++.h>
// #include "lib/debug.cpp"
using namespace std;
const int MAXN = 200005;
int n, q, a[MAXN], BIT[MAXN];
void update(int pos, int val)
{
    for (; pos <= n; pos += pos & (-pos))
    {
        BIT[pos] += val;
    }
}
int query(int pos)
{
    int sum = 0;
    for (; pos >= 1; pos -= pos & (-pos))
    {
        sum += BIT[pos];
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }
    while (q--)
    {
        int tt, x, y;
        cin >> tt >> x >> y;
        if (tt == 1)
        {
            update(x, y);
        }
        else
        {
            cout << query(y) - query(x - 1) << endl;
        }
    }
    return 0;
}