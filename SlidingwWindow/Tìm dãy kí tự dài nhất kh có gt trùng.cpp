#include <bits/stdc++.h>
// #include "lib/debug.cpp"
using namespace std;
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    unordered_map<char, int> m;
    int left = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        m[s[i]]++;
        while (m[s[i]] > 1)
        {
            m[s[left]]--;
            left++;
        }
        ans = max(ans, i - left + 1);
    }
    cout << ans;
    return 0;
}