#include <bits/stdc++.h>
using namespace std;
// Link bài:https://leetcode.com/problems/4sum/description/
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<vector<int>> B;
    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && A[i] == A[i - 1])
            continue;
        for (int j = n - 1; j > 2; j--)
        {
            if (j < n - 1 && A[j] == A[j + 1])
                continue;
            int l = i + 1;
            int r = j - 1;
            while (l < r)
            {
                int check = A[i] + A[l] + A[r] + A[j];
                if (check == target)
                {
                    cout << "1";
                    B.push_back({A[i], A[l], A[r], A[j]});
                    while (l < r && A[l] == A[l + 1])
                        l++;
                    while (l < r && A[r] == A[r - 1])
                        r--;
                    l++;
                    r--;
                }
                else if (check < target)
                {
                    cout << "2";
                    while (l < r && A[l] == A[l + 1])
                        l++;
                    l++;
                }
                else
                {
                    cout << "3";
                    while (l < r && A[r - 1] == A[r])
                        r--;
                    r--;
                }
            }
        }
    }
    cout << endl;
    for (int i = 0; i < B.size(); i++)
    {
        for (int j = 0; j < B[i].size(); j++)
        {
            cout << B[i][j] << " ";
        }
        cout << "\n";
    }
}