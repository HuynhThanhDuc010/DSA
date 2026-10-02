#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/2254/problem/B
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        vector<char> ch;
        vector<int> len;

        int i = 0;
        while (i < n)
        {
            int j = i;
            while (j < n && s[j] == s[i])
                j++;
            ch.push_back(s[i]);
            len.push_back(j - i);
            i = j;
        }

        int R = ch.size();
        int bestReduction = 0;

        for (int k = 1; k <= R - 2; k++)
        {
            if (len[k] == 1)
            {
                int red = (ch[k - 1] == ch[k + 1]) ? 2 : 1;
                bestReduction = max(bestReduction, red);
            }
        }

        cout << (R - bestReduction) << "\n";
    }
    return 0;
}