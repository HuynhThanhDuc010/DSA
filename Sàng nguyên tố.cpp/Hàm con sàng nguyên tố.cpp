#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
bool is_prime[MAXN];

void sieve()
{
    fill(is_prime, is_prime + MAXN, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i < MAXN; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < MAXN; j += i)
                is_prime[j] = false;
        }
    }
}

int main()
{
    sieve();

    int n;
    cin >> n;

    for (int i = 0; i <= n; i++)
        if (is_prime[i])
            cout << i << " ";
}