#include <bits/stdc++.h>
using namespace std;
int n;
// https://leetcode.com/problems/generate-parentheses/description/
vector<string> ans;
vector<string> tmp;
void Try(int mo, int dong)
{
    if (mo == 0 && dong == 0)
    {
        string c = "";
        for (auto it : tmp)
        {
            c += it;
        }
        ans.push_back(c);
        return;
    }
    if (mo > 0)
    {
        tmp.push_back("(");
        Try(mo - 1, dong);
        tmp.pop_back();
    }
    if (dong > mo)
    {
        tmp.push_back(")");
        Try(mo, dong - 1);
        tmp.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    Try(n, n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
        }
        cout << "\n";
    }

    return 0;
}