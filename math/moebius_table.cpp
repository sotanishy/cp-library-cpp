#include <vector>
#include "prime.cpp"

/*
 * @brief Table of Moebius Function
 */
std::vector<int> moebius_table(int n) {
    std::vector<bool> prime(n + 1, true);
    std::vector<int> ret(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        if (!prime[i]) continue;
        for (int j = i; j <= n; j += i) {
            if (j > i) prime[j] = false;
            if ((j / i) % i == 0) ret[j] = 0;
            else ret[j] *= -1;
        }
    }
    return ret;
}