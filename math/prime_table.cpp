#include <bits/stdc++.h>

/*
 * @brief Prime Table
 * @docs docs/math/prime_table.md
 */
std::vector<bool> prime_table(int n) {
    std::vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int j = 4; j <= n; j += 2) prime[j] = false;
    for (int i = 3; i * i <= n; i += 2) {
        if (!prime[i]) continue;
        for (int j = i * i; j <= n; j += 2 * i) prime[j] = false;
    }
    return prime;
}