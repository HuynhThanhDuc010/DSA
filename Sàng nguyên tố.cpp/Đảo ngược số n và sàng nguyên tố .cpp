#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    string tmp = to_string(x);
    reverse(tmp.begin(), tmp.end());
    int y = stoi(tmp);
    if (y < x)
        swap(x, y);
    vector<bool> prime(y + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; (long long)i * i <= y; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= y; j += i)
                prime[j] = false;
        }
    }
    int tong = 0;
    for (int i = x; i <= y; i++)
    {
        if (prime[i])
            tong += i;
    }
    cout << tong;
}