#pragma once
#include <algorithm>
#include <vector>

template <typename F>
std::vector<int> smawk(int n, int m, F f) {
    auto calc = [&](auto& calc, const std::vector<int>& row,
                    const std::vector<int>& col) -> std::vector<int> {
        const int r = row.size();
        if (r == 0) return {};

        // reduce
        std::vector<int> c2;
        for (int c : col) {
            while (!c2.empty() && f(row[c2.size() - 1], c2.back()) >
                                      f(row[c2.size() - 1], c)) {
                c2.pop_back();
            }
            if ((int)c2.size() < r) {
                c2.push_back(c);
            }
        }

        // interpolate
        std::vector<int> r2;
        for (int i = 1; i < r; i += 2) {
            r2.push_back(row[i]);
        }
        auto a2 = calc(calc, r2, c2);
        std::vector<int> ans(r);
        for (int i = 0; i < (int)a2.size(); ++i) {
            ans[2 * i + 1] = a2[i];
        }
        int j = 0;
        for (int i = 0; i < r; i += 2) {
            ans[i] = c2[j];
            int end = (i == r - 1 ? c2.back() : ans[i + 1]);
            while (c2[j] < end) {
                ++j;
                if (f(row[i], ans[i]) > f(row[i], c2[j])) {
                    ans[i] = c2[j];
                }
            }
        }
        return ans;
    };

    std::vector<int> row(n), col(m);
    std::iota(row.begin(), row.end(), 0);
    std::iota(col.begin(), col.end(), 0);
    return calc(calc, row, col);
}
