#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;

    vector<bool> is_prime(y + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; (long long)i * i <= y; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= y; j += i)
                is_prime[j] = false;
        }
    }

    for (int i = x; i <= y; i++)
        if (is_prime[i])
            cout << i << "\n";
}