#pragma once
#include <algorithm>
#include <vector>
#include <string>

std::vector<int> manacher(const std::string& s) {
    int n = s.size();
    std::vector<int> vs(2 * n - 1);
    // odd length
    for (int i = 0, l = 0, r = -1; i < n; ++i) {
        int k = (i > r) ? 1 : std::min(vs[2 * (l + r - i)], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) ++k;
        vs[2 * i] = k;
        --k;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    // even length
    for (int i = 1, l = 0, r = -1; i < n; ++i) {
        int k = (i > r) ? 0 : std::min(vs[2 * (l + r - i + 1) - 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) ++k;
        vs[2 * i - 1] = k;
        --k;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }
    return vs;
}