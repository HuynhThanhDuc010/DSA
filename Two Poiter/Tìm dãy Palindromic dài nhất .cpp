#include <bits/stdc++.h>
using namespace std;
// link bài:https://leetcode.com/problems/longest-palindromic-substring/submissions/2044349379/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    string ans = "";
    ans += s[0];

    for (int i = 0; i < s.size(); i++)
    {
        int l = i;
        int r = i;
        string tmp = "";

        while (l > 0 && r < s.size() && s[l - 1] == s[r + 1])
        {
            l--;
            r++;
        }
        tmp = s.substr(l, r - l + 1);
        if (tmp.size() > ans.size())
            ans = tmp;

        if (i + 1 < s.size() && s[i] == s[r + 1])
        {
            l = i;
            r = i + 1;
            while (l > 0 && r < s.size() && s[l - 1] == s[r + 1])
            {
                l--;
                r++;
            }
            tmp = s.substr(l, r - l + 1);

            if (tmp.size() > ans.size())
            {
                ans = tmp;
            }
        }
    }
    cout << ans;
    return 0;
}