#include <bits/stdc++.h>
using namespace std;
// link bài:https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/?envType=problem-list-v2&envId=array

vector<int> searchRange(vector<int> &A, int n, int target)
{
    vector<int> B(2, -1);
    int l = 0, r = n - 1, left = -1;

    while (l <= r)
    {
        int m = (l + r) / 2;
        if (A[m] == target)
        {
            left = m;
            r = m - 1;
        }
        else if (A[m] > target)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    if (left == -1)
        return B;

    int right = left;
    l = 0;
    r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (A[m] == target)
        {
            right = m;
            l = m + 1;
        }
        else if (A[m] > target)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    B[0] = left;
    B[1] = right;
    return B;
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    vector<int> B = searchRange(A, n, target);

    if (B[0] == -1)
        cout << "-1 -1";
    else
    {
        for (int i = 0; i < B.size(); i++)
            cout << B[i] << " ";
    }
}