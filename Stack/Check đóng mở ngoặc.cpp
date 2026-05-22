#include <bits/stdc++.h>
using namespace std;
// Link bài:https://leetcode.com/problems/valid-parentheses/description/
int main()
{
    string s;
    cin >> s;
    stack<char> A;
    for (auto c : s)
    {
        if (s.size() < 1)
        {
            cout << "false";
        }
        if (c == '(' || c == '{' || c == '[')
        {
            A.push(c);
        }
        else
        {
            if (A.empty())
            {
                cout << "false";
                return 0;
            }
            char x = A.top();
            A.pop();
            if (c == ')' && x != '(' || c == '}' && x != '{' || c == ']' && x != '[')
            {
                cout << "false";
                return 0;
            }
        }
    }
    if (A.empty())
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}