#include <bits/stdc++.h>
// #include "lib/debug.cpp"
// https://cses.fi/problemset/task/1648
using namespace std;
const int maxn = 5e5 + 5;
int seg[4 * maxn];
int n;
int a[maxn];
// Xây dựng Segment Tree
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
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
// Tìm tổng trên đoạn [l,r]
int query(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return 0;
    }
    if (l >= u && r <= v)
    {
        return seg[id];
    }
    int mid = l + (r - l) / 2;
    return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v);
}
// Update vị trị pos bằng value và Xây dụng lại Segment Tree
void update(int id, int l, int r, int pos, int value)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        seg[id] = value;
        return;
    }
    int mid = l + (r - l) / 2;
    if (pos <= mid)
    {
        update(id * 2, l, mid, pos, value);
    }
    else
    {
        update(id * 2 + 1, mid + 1, r, pos, value);
    }
    seg[id] = seg[2 * id] + seg[2 * id + 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--)
    {
        int start, u, v;
        cin >> start >> u >> v;
        if (start == 1)
            update(1, 1, n, u, v);
        else
            cout << query(1, 1, n, u, v) << "\n";
    }
    return 0;
}