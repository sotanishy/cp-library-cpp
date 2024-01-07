#pragma once
#include <vector>

template <typename F>
std::vector<int> monotone_minima(int n, int m, const F& f) {
    std::vector<int> idx(n, -1);

    auto calc = [&](const auto& calc, int l, int r, int optl,
                    int optr) -> void {
        if (l > r) return;
        int m = std::midpoint(l, r);
        auto mi = f(m, optl);
        idx[m] = optl;
        for (int i = optl + 1; i <= optr; ++i) {
            auto v = f(m, i);
            if (mi > v) {
                mi = v;
                idx[m] = i;
            }
        }
        calc(calc, l, m - 1, optl, idx[m]);
        calc(calc, m + 1, r, idx[m], optr);
    };

    calc(calc, 0, n - 1, 0, m - 1);
    return idx;
}