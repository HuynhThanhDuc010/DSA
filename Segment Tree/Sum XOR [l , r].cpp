#include <bits/stdc++.h>
// #include "lib/debug.cpp"
using namespace std;
int n, q;
// https://cses.fi/problemset/task/1650
vector<long long> seg, a;
void build(int id, int l, int r)
{

    if (l == r)
    {
        seg[id] = a[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    seg[id] = seg[id * 2] ^ seg[id * 2 + 1];
}
long long query(int id, int l, int r, int u, int v)
{

    if (l > v || r < u)
    {
        return 0;
    }
    if (u <= l && r <= v)
    {
        return seg[id];
    }
    int mid = l + (r - l) / 2;
    return query(id * 2, l, mid, u, v) ^ query(id * 2 + 1, mid + 1, r, u, v);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    a.resize(n + 1);
    seg.resize(n * 4);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << query(1, 1, n, u, v) << "\n";
    }

    return 0;
}