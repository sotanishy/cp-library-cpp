#include <vector>
#include "prime.cpp"

/*
 * @brief Table of Moebius Function
 */
std::vector<int> mobius_table(int n) {
    auto prime = prime_table(n);
    std::vector<int> ret(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        if (prime[i]) {
            for (int j = i; j <= n; j += i) {
                if ((j / i) % i == 0) ret[j] = 0;
                else ret[j] *= -1;
            }
        }
    }
    return ret;
}