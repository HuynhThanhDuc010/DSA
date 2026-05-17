#include <bits/stdc++.h>
using namespace std;
// Link bài:
// https://leetcode.com/problems/3sum/?envType=problem-list-v2&envId=array
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<vector<int>> kq;
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && A[i] == A[i - 1])
            continue;
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            int check = A[i] + A[l] + A[r];
            if (check == 0)
            {
                kq.push_back({A[i], A[l], A[r]});
                while (l < r && A[l] == A[l + 1])
                    l++;
                while (l < r && A[r] == A[r - 1])
                    r--;
                l++;
                r--;
            }
            else if (check < 0)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    for (int i = 0; i < kq.size(); i++)
    {
        for (int j = 0; j < kq[i].size(); j++)
        {
            cout << kq[i][j] << " ";
        }
        cout << "\n";
    }
}
