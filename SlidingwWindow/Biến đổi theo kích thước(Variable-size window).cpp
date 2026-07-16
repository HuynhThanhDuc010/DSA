// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/?envType=daily-question&envId=2026-06-30
#include <bits/stdc++.h>
using namespace std;
int Check(string s)
{
    int tmp[3] = {0, 0, 0};
    int l = 0;
    int res = 0;
    for (int r = 0; r < s.size(); r++)
    {
        tmp[s[r] - 'a']++;
        while (tmp[0] > 0 && tmp[1] > 0 && tmp[2] > 0)
        {
            tmp[s[l] - 'a']--;
            l++;
        }
        res += l;
    }
    return res;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    cout << Check(s);

    return 0;
}