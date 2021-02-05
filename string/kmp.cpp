#pragma once
#include <string>
#include <vector>

std::vector<int> kmp(const std::string txt, const std::string pat) {
    int n = txt.size(), m = pat.size();

    std::vector<int> lps(m);
    int len = 0;
    for (int i = 1; i < m; ++i) {
        if (pat[i] == pat[len]) {
            ++len;
            lps[i] = len;
        } else {
            if (len != 0) {
                len = lps[len - 1];
                --i;
            } else {
                lps[i] = 0;
            }
        }
    }

    std::vector<int> match;
    int i = 0, j = 0;
    while (i < n) {
        if (pat[j] == txt[i]) {
            ++i;
            ++j;
        }
        if (j == m) {
            match.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }
    }
    return match;
}