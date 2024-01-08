#pragma once
#include <numeric>
#include <vector>

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

std::vector<int> euler_totient_table(int n) {
    std::vector<int> ret(n + 1);
    std::iota(ret.begin(), ret.end(), 0);
    for (int i = 2; i <= n; ++i) {
        if (ret[i] == i) {
            for (int j = i; j <= n; j += i) {
                ret[j] = ret[j] / i * (i - 1);
            }
        }
    }
    return ret;
}

template <typename mint>
std::pair<std::vector<mint>, std::vector<mint>> totient_summatory_table(
    long long n) {
    if (n == 0) return {{0}, {0}};
    const int b = std::min(n, (long long)1e4);
    std::vector<mint> small(n / b + 1), large(b + 1);

    std::vector<int> totient(n / b + 1);
    std::iota(totient.begin(), totient.end(), 0);
    for (int i = 2; i <= n / b; ++i) {
        if (totient[i] != i) continue;
        for (int j = i; j <= n / b; j += i) {
            totient[j] = totient[j] / i * (i - 1);
        }
    }
    for (int i = 0; i < n / b; ++i) small[i + 1] = small[i] + totient[i + 1];

    for (int i = 1; i <= b; ++i) {
        mint k = n / i;
        large[i] = k * (k + 1) / 2;
    }
    for (long long i = b; i >= 1; --i) {
        for (long long l = 2; l <= n / i;) {
            long long q = n / (i * l), r = n / (i * q) + 1;
            large[i] -=
                (i * l <= b ? large[i * l] : small[n / (i * l)]) * (r - l);
            l = r;
        }
    }
    return {small, large};
}