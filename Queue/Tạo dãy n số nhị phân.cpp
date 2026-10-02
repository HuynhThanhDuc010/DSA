
#include <bits/stdc++.h>
// #include "lib/debug.cpp"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> res;
        queue<string> q;
        res.push_back("1");
        q.push("1");

        while (res.size() <= n)
        {
            string top = q.front();
            q.pop();
            res.push_back(top + "0");
            res.push_back(top + "1");
            q.push(top + "0");
            q.push(top + "1");
        }
        for (int i = 0; i < n; i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}