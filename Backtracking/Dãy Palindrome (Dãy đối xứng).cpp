#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/palindrome-partitioning/description/
vector<vector<string>> ans;
vector<string> tmp;
bool check(string ch)
{
    string rev = ch;
    reverse(rev.begin(), rev.end());
    if (rev != ch)
    {
        return false;
    }
    return true;
}
void Try(string s, int x)
{
    if (x == s.size())
    {
        ans.push_back(tmp);
        return;
    }
    string ch = "";
    for (int i = x; i < s.size(); i++)
    {

        ch += s[i];
        if (check(ch))
        {
            tmp.push_back(ch);
            Try(s, i + 1);
            tmp.pop_back();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    Try(s, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}