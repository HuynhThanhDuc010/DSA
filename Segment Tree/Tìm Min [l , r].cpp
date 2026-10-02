#include <bits/stdc++.h>
using namespace std;
//https://cses.fi/problemset/task/1649
vector<long long> seg, a;
int n, q;
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
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
long long query(int id, int l, int r, int u, int v)
{
    if (v < l || u > r)
    {
        return LLONG_MAX;
    }
    if (u <= l && r <= v)
    {
        return seg[id];
    }
    int mid = l + (r - l) / 2;
    return min(query(id * 2, l, mid, u, v), query(id * 2 + 1, mid + 1, r, u, v));
}
void update(int id, int l, int r, int pos, int val)
{
    if (pos > r || pos < l)
    {
        return;
    }
    if (l == r)
    {
        seg[id] = val;
        return;
    }
    int mid = l + (r - l) / 2;
    if (pos <= mid)
    {
        update(id * 2, l, mid, pos, val);
    }
    else
    {
        update(id * 2 + 1, mid + 1, r, pos, val);
    }
    seg[id] = min(seg[2 * id], seg[2 * id + 1]);
}
int main()
{

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
        int x, u, v;
        cin >> x >> u >> v;
        if (x == 1)
        {
            update(1, 1, n, u, v);
        }
        else
        {
            cout << query(1, 1, n, u, v) << " \n";
        }
    }
}