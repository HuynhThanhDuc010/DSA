#include <bits/stdc++.h>
using namespace std;
// Link bài:
// https://leetcode.com/problems/3sum-closest/description/?envType=problem-list-v2&envId=array
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target;
    cin >> n >> target;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int kq = A[0] + A[1] + A[2];
    sort(A.begin(), A.end());
    for (int i = 0; i < n - 1; i++)
    {
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            int check = A[i] + A[l] + A[r];
            if (abs(check - target) < abs(kq - target))
            {
                kq = check;
            }
            if (check == target)
            {
                cout << target;
                return 0;
            }
            else if (check < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    cout << kq;
}
