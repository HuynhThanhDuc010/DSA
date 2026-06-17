#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int nums[maxn];
int n;
void Try(int i)
{
    if (i == n)
    {
        for (int j = 0; j < n; j++)
        {
            cout << nums[j];
        }
        cout << "\n";
        return;
    }
    for (int j = 0; j <= 1; j++)
    {
        if (j == 1 && i > 0 && nums[i - 1] == 1)
            continue;
        nums[i] = j;
        Try(i + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    Try(0);
}