#pragma once
#include <random>

#include "fast_prime.hpp"

long long primitive_root(long long p) {
    auto prime = fast_prime::prime_factor(p - 1);

    using mint = fast_prime::LargeModint;
    mint::set_mod(p);

    std::random_device rd;
    std::mt19937_64 rng(rd());
    std::uniform_int_distribution<long long> rand(1, p - 1);
    while (true) {
        long long x = rand(rng);
        mint a = x;
        bool ok = true;
        for (auto pi : prime) {
            if (a.pow((p - 1) / pi) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return a.val();
    }
}
