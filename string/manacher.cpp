#pragma once
#include <vector>
#include <string>

/*
 * @brief Manacher's Algorithm
 */
std::vector<int> manacher(const std::string& s) {
    int n = s.size();
    std::vector<int> vs(n);
    int i = 0, j = 0;
    while (i < n) {
        while (0 <= i - j && i + j < n && s[i - j] == s[i + j]) ++j;
        vs[i] = j;
        int k = 1;
        while (0 <= i - k && i + k < n && k + vs[i - k] < j) {
            vs[i + k] = vs[i - k];
            ++k;
        }
        i += k;
        j -= k;
    }
    return vs;
}