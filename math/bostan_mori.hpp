#pragma once
#include <vector>
#include "../convolution/ntt.hpp"

template <typename T>
T bostan_mori(const std::vector<T>& a, const std::vector<T>& c, long long n) {
    const int d = c.size();
    if (n < d) return a[n];

    std::vector<T> q(d + 1);
    q[0] = 1;
    for (int i = 0; i < d; ++i) q[i + 1] = -c[i];
    auto p = convolution(a, q);
    p.resize(d);

    auto take = [&](const std::vector<T>& p, int s) {
        std::vector<T> r((p.size() + 1) / 2);
        for (int i = 0; i < (int) r.size(); ++i) {
            r[i] = p[2 * i + s];
        }
        return r;
    };

    while (n > 0) {
        auto qm = q;
        for (int i = 1; i < (int) qm.size(); i += 2) qm[i] = -qm[i];
        p = take(convolution(p, qm), n & 1);
        q = take(convolution(q, qm), 0);
        n >>= 1;
    }

    return p[0] / q[0];
}