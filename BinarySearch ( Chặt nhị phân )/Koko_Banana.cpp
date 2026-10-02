#include <bits/stdc++.h>
// #include "lib/debug.cpp"
using namespace std;
//https://leetcode.com/problems/koko-eating-bananas/description/
bool Check(vector<int> &piles, int mid, int h)
{
    long long hour = 0;
    for (auto it : piles)
    {
        hour += (it / mid);
        long long x = it % mid;
        if (x != 0)
        {
            hour++;
        }
    }
    if (hour <= h)
    {
        return true;
    }
    return false;
}
long long Binary(vector<int> &piles, int h)
{
    int ans = 0;
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (Check(piles, mid, h))
        {

            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, h;
    cin >> n >> h;
    vector<int> piles(n);
    for (int i = 0; i < n; i++)
    {
        cin >> piles[i];
    }
    cout << Binary(piles, h);
    return 0;
}