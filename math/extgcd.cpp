#include <bits/stdc++.h>
using namespace std;

long long extgcd(long long a, long long b, long long& x, long long& y) {
    long long d = a;
    if (b == 0) {
        x = 1;
        y = 0;
    } else {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    return d;
}