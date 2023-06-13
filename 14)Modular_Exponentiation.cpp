#include <bits/stdc++.h>

int binExpRec(int a, int b, int m)
{
    if (b == 0)
        return 1;
    long long ans = binExpRec(a, b / 2, m);
    if (b & 1) // if b is odd
    {
        return (a * ((ans * ans) % m)) % m;
    }
    else
    {
        return (ans * ans) % m;
    }
}

int modularExponentiation(int x, int n, int m)
{
    // f(a,b) -> a^b
    // f(a,b) -> f(a,b/2) * f(a,b/2) if b is even
    // f(a,b) -> a * f(a,b/2) * f(a,b/2) if b is odd
    return binExpRec(x, n, m);
}