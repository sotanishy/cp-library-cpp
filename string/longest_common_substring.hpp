#pragma once
#include <algorithm>
#include <string>

#include "lcp_array.hpp"
#include "suffix_array.hpp"

/**
 * @brief Longest Common Substring
 */
std::tuple<int, int, int, int> longest_common_substring(const std::string& s,
                                                        const std::string& t) {
    const int n = s.size();
    auto st = s + "$" + t;
    auto sa = suffix_array(st);
    auto lcp = lcp_array(st, sa);
    std::pair<int, std::tuple<int, int, int, int>> ans(0, {0, 0, 0, 0});
    for (int i = 0; i < (int)st.size() - 1; ++i) {
        int len = lcp[i];
        if (len == 0) continue;
        if (sa[i] < n && sa[i + 1] >= n + 1) {
            int a = sa[i], c = sa[i + 1] - n - 1;
            ans = std::max(ans, {len, {a, a + len, c, c + len}});
        } else if (sa[i] >= n + 1 && sa[i + 1] < n) {
            int a = sa[i + 1], c = sa[i] - n - 1;
            ans = std::max(ans, {len, {a, a + len, c, c + len}});
        }
    }
    return ans.second;
}