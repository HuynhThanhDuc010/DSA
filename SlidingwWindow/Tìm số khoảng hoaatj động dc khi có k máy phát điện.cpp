#include <bits/stdc++.h>
using namespace std;

long long K(string s, int k)
{
    long long tong = 0, dem = 0;
    int l = 0;
    for (int r = 0; r < s.size(); r++)
    {
        if (s[r] == '1')
            dem++;
        while (dem > k)
        {
            if (s[l] == '1')
                dem--;
            l++;
        }
        tong += (r - l + 1);
    }
    return tong;
}

int main()
{
    int k;
    string s;
    cin >> k >> s;
    cout << K(s, k) - K(s, k - 1) << "\n";
}