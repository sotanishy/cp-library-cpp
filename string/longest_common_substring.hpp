#pragma once
#include <algorithm>
#include <string>

#include "lcp_array.cpp"
#include "suffix_array.cpp"

/**
 * @brief Longest Common Substring
 */
std::tuple<int, int, int, int> longest_common_substring(const std::string& S,
                                                        const std::string& T) {
    const int N = S.size();
    auto ST = S + "$" + T;
    auto sa = suffix_array(ST);
    auto lcp = lcp_array(ST, sa);
    std::pair<int, std::tuple<int, int, int, int>> ans(0, {0, 0, 0, 0});
    for (int i = 0; i < (int)ST.size() - 1; ++i) {
        int len = lcp[i];
        if (len == 0) continue;
        if (sa[i] < N && sa[i + 1] >= N + 1) {
            int a = sa[i], c = sa[i + 1] - N - 1;
            ans = std::max(ans, {len, {a, a + len, c, c + len}});
        } else if (sa[i] >= N + 1 && sa[i + 1] < N) {
            int a = sa[i + 1], c = sa[i] - N - 1;
            ans = std::max(ans, {len, {a, a + len, c, c + len}});
        }
    }
    return ans.second;
}