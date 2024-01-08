#pragma once
#include <cmath>
#include <numeric>

#include "prime.hpp"

long long carmichael(long long n) {
    long long ret = 1;
    for (auto [p, e] : prime_factor(n)) {
        long long lambda = std::pow(p, e - 1) * (p - 1);
        if (p == 2 && e >= 3) lambda /= 2;
        ret = ret / std::gcd(ret, lambda) * lambda;
    }
    return ret;
}