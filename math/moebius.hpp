#include <cmath>
#include <vector>

int moebius(long long n) {
    long long ret = 1;
    if (n % 4 == 0) return 0;
    if (n % 2 == 0) {
        ret *= -1;
        n /= 2;
    }
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % (i * i) == 0) return 0;
        if (n % i == 0) {
            ret *= -1;
            ret /= i;
        }
    }
    if (n != 1) ret *= -1;
    return ret;
}

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

std::pair<std::vector<int>, std::vector<int>> mertens_table(long long n) {
    if (n == 0) return {{0}, {0}};
    const int b = 1e4;
    std::vector<int> small(n/b + 1, 1), large(b + 1, 1);
    small[0] = large[0] = 0;

    std::vector<bool> prime(n/b + 1, true);
    for (int i = 2; i <= n/b; ++i) {
        if (!prime[i]) continue;
        for (int j = i; j <= n/b; j += i) {
            if (j > i) prime[j] = false;
            if ((j / i) % i == 0) small[j] = 0;
            else small[j] *= -1;
        }
    }
    for (int i = 1; i < n/b; ++i) small[i+1] += small[i];

    for (long long i = b; i >= 1; --i) {
        for (long long l = 2; l <= n/i; ) {
            long long q = n/(i*l), r = n/(i*q) + 1;
            large[i] -= (i*l <= b ? large[i*l] : small[n/(i*l)]) * (r - l);
            l = r;
        }
    }
    return {small, large};
}