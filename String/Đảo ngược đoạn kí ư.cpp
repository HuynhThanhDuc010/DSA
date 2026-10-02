#include <bits/stdc++.h>
// #include "lib/debug.cpp"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    istringstream ch(s);
    vector<string> words;
    string kitu;

    while (ch >> kitu)
    {
        words.push_back(kitu);
    }
    string ans;
    for (int i = words.size() - 1; i >= 0; i--)
    {
        ans += words[i];
        if (i != 0)
            ans += " ";
    }
    cout << ans;
    return 0;
}