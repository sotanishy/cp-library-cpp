#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Euler's Totient Function
 * @docs docs/math/euler_totient.md
 */
long long euler_totient(long long n) {
    long long ret = n;
    if (n % 2 == 0) {
        ret -= ret / 2;
        while (n % 2 == 0) n /= 2;
    }
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            ret -= ret / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n != 1) ret -= ret / n;
    return ret;
}