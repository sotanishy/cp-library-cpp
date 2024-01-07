#pragma once
#include <algorithm>
#include <utility>
#include <vector>

#include "z_array.hpp"

std::vector<std::vector<std::pair<int, int>>> enumerate_runs(
    const std::string& s) {
    std::vector<std::vector<std::pair<int, int>>> runs(s.size() + 1);

    auto calc = [&](const std::string& u, const std::string& v) {
        const int nu = u.size(), nv = v.size();
        std::string ru(u.rbegin(), u.rend());
        auto z1 = z_array(ru);
        auto z2 = z_array(v + '$' + u + v);
        std::vector<std::tuple<int, int, int>> res;
        for (int i = 0; i < nu; ++i) {
            int period = nu - i;
            int left = period + (i > 0 ? z1[nu - i] : 0);
            int right = z2[nv + 1 + i];
            if (2 * period <= left + right) {
                res.emplace_back(nu - left, nv - right, period);
            }
        }
        return res;
    };

    auto rec = [&](auto& rec, int l, int r) {
        if (r - l == 1) return;
        int m = std::midpoint(l, r);
        rec(rec, l, m);
        rec(rec, m, r);

        std::string u(s.begin() + l, s.begin() + m);
        std::string v(s.begin() + m, s.begin() + r);
        for (auto [a, b, p] : calc(u, v)) {
            runs[p].emplace_back(l + a, r - b);
        }

        std::string ru(u.rbegin(), u.rend());
        std::string rv(v.rbegin(), v.rend());
        for (auto [a, b, p] : calc(rv, ru)) {
            runs[p].emplace_back(l + b, r - a);
        }
    };

    rec(rec, 0, s.size());

    // remove duplicates
    for (int p = 1; p <= (int)s.size(); ++p) {
        std::ranges::sort(runs[p], [&](auto& p, auto& q) {
            return std::make_pair(p.first, -p.second) <
                   std::make_pair(q.first, -q.second);
        });
        std::vector<std::pair<int, int>> res;
        int mx = -1;
        for (auto [l, r] : runs[p]) {
            if (r <= mx) continue;
            mx = r;
            res.emplace_back(l, r);
        }
        runs[p].swap(res);
    }
    return runs;
}
