#include <bits/stdc++.h>
// #include "lib/debug.cpp"
using namespace std;
// https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/?envType=daily-question&envId=2026-09-26
string Check(string s, unordered_map<string, string> &m)
{
    string ans = "";
    int pos = 0;
    while (pos < s.size())
    {

        while (pos < s.size() && s[pos] != '(')
        {
            ans += s[pos];
            pos++;
        }
        if (pos == s.size())
        {
            break;
        }
        pos++;
        string tmp = "";
        while (pos < s.size() && s[pos] != ')')
        {
            tmp += s[pos];
            pos++;
        }
        pos++;
        auto it = m.find(tmp);
        if (it != m.end())
        {
            ans += it->second;
        }
        else
        {
            ans += "?";
        }
        // Có thể ghi là
        //  if (m.count(tmp))
        //     {
        //         ans += m[tmp];
        //     }
        //     else
        //     {
        //         ans += "?";
        //     }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<vector<string>> knowledge(n, vector<string>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> knowledge[i][j];
        }
    }
    unordered_map<string, string> m;
    for (auto &it : knowledge)
    {
        m[it[0]] = it[1];
    }
    cout << Check(s, m);

    return 0;
}