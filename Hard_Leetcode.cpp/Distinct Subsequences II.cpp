#include <bits/stdc++.h>
// #include "lib/debug.cpp"
// https://leetcode.com/problems/distinct-subsequences-ii/?envType=daily-question&envId=2026-09-07
int distinctSubseqII(string s)
{
    const int modulo = 1e9 + 7;
    vector<int> dnp(26, 0);
    for (char it : s)
    {
        int dem = 1;
        for (int i = 0; i < 26; i++)
        {
            dem = (dem + dnp[i]) % modulo;
        }
        dnp[it - 'a'] = dem;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        ans = (ans + dnp[i]) % modulo;
    }
    return ans;
}
using namespace std;
int main()
{
    string s;
    cin >> s;
    cout << distinctSubseqII(s);
}