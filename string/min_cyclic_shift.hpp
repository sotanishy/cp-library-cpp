#pragma once
#include <string>
#include <vector>

/**
 * @brief Minimum Cyclic Shift
 */

template <typename T>
std::vector<T> min_cyclic_shift(const std::vector<T>& s) {
    const int n = s.size();
    auto ss = s;
    ss.insert(ss.end(), s.begin(), s.end());
    int i = 0, ans = 0;
    while (i < n) {
        ans = i;
        int j = i + 1, k = i;
        while (j < 2 * n && ss[k] <= ss[j]) {
            if (ss[k] < ss[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k) i += j - k;
    }
    return std::vector<T>(ss.begin() + ans, ss.begin() + ans + n);
}

std::string min_cyclic_shift(const std::string& s) {
    auto res = min_cyclic_shift(std::vector<char>(s.begin(), s.end()));
    return std::string(res.begin(), res.end());
}
