#pragma once
#include <string>
#include <vector>

std::vector<int> prefix_function(const std::string& s) {
    const int n = s.size();
    std::vector<int> ret(n);
    int len = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[len]) {
            ++len;
            ret[i] = len;
        } else {
            if (len != 0) {
                len = ret[len - 1];
                --i;
            } else {
                ret[i] = 0;
            }
        }
    }
    return ret;
}

std::vector<int> kmp(const std::string txt, const std::string pat) {
    int n = txt.size(), m = pat.size();
    auto lps = prefix_function(pat);
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

template <int AlphabetSize, int Offset>
std::vector<std::vector<std::pair<int, bool>>> matching_automaton(const std::string& s) {
    const int n = s.size();
    auto lps = prefix_function(s);
    std::vector<std::vector<std::pair<int, bool>>> aut(n, std::vector<std::pair<int, bool>>(AlphabetSize));
    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < AlphabetSize; ++c) {
            if (Offset + c == s[i]) {
                if (i == n - 1) aut[i][c] = {lps[i], true};
                else aut[i][c] = {i + 1, false};
            } else {
                aut[i][c] = {i > 0 ? aut[lps[i - 1]][c].first : 0, 0};
            }
        }
    }
    return aut;
}