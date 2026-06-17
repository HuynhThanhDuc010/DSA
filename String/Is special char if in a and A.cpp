#include <bits/stdc++.h>
using namespace std;
// link:https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/
bool check(string word, int l, int r, char x)
{

    for (int i = l; i < r; i++)
    {
        if (word[i] == x)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string word;
    cin >> word;
    int n = word.size();
    unordered_set<char> s;
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        if ((word[i] >= 'A') && (word[i] <= 'Z'))
        {
            if (!s.count(word[i]))
            {
                char x = tolower(word[i]);
                bool left = check(word, 0, i, x);

                bool right = check(word, i + 1, n, x);
                cout << left << " " << right << endl;

                if (left == true && right == false)
                {
                    tong++;
                    s.insert(word[i]);
                }
                else
                {
                    s.insert(word[i]);
                }
            }
        }
    }
    cout << tong;
}
