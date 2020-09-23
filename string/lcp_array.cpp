#include <bits/stdc++.h>
#include "suffix_array.cpp"

/*
 * @brief Longest Common Prefix Array
 * @docs docs/string/lcp_array.md
 */
std::vector<int> lcp_array(const std::string& s, const SuffixArray& sa) {
    int n = s.size();
    std::vector<int> rank(n);
    for (int i = 0; i < n; ++i) rank[sa[i]] = i;
    int h = 0;
    std::vector<int> lcp(n - 1);
    for (int i = 0; i < n; ++i) {
        if (h > 0) --h;
        if (rank[i] == 0) continue;
        int j = sa[rank[i] - 1];
        while (j + h < n && i + h < n && s[j + h] == s[i + h]) ++h;
        lcp[rank[i] - 1] = h;
    }
    return lcp;
}