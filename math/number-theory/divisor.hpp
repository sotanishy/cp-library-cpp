#pragma once
#include <vector>

std::vector<long long> divisor(long long n) {
    std::vector<long long> ret1, ret2;
    for (long long i = 1; i * i <= n; ++i) {
        if (i * i == n) {
            ret1.push_back(i);
        } else if (n % i == 0) {
            ret1.push_back(i);
            ret2.push_back(n / i);
        }
    }
    ret1.insert(ret1.end(), ret2.rbegin(), ret2.rend());
    return ret1;
}