#include <bits/stdc++.h>
using namespace std;
// Link bài:
// https://leetcode.com/problems/jump-game-iii/description/?envType=daily-question&envId=2026-05-17
bool check(vector<int> A, int start, int n)
{
    queue<int> q;
    vector<bool> res(n, false);
    q.push(start);
    res[start] = true;
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        if (A[i] == 0)
            return true;
        for (auto it : {i - A[i], i + A[i]})
        {
            if (it >= 0 && it < n && !res[it])
            {
                res[it] = true;
                q.push(it);
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, start;
    cin >> n >> start;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int kq = check(A, start, n);
    if (kq)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}