#pragma once
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

template <typename T>
std::vector<int> suffix_array(const std::vector<T>& s) {
    const int n = s.size();
    std::vector<int> sa(n);
    std::iota(sa.begin(), sa.end(), 0);
    std::ranges::sort(sa, {}, [&](int i) { return s[i]; });
    int cl = 0;
    std::vector<int> rank(n);
    for (int i = 1; i < n; ++i) {
        if (s[sa[i - 1]] != s[sa[i]]) ++cl;
        rank[sa[i]] = cl;
    }
    std::vector<int> tmp(n), nrank(n), cnt(n);
    for (int k = 1; k < n; k <<= 1) {
        // sort by second half
        int cnt1 = 0, cnt2 = k;
        for (int i = 0; i < n; ++i) {
            int j = sa[i] - k;
            if (j >= 0)
                tmp[cnt2++] = j;
            else
                tmp[cnt1++] = j + n;
        }

        // sort by first half
        std::ranges::fill(cnt, 0);
        for (int i = 0; i < n; ++i) ++cnt[rank[tmp[i]]];
        for (int i = 1; i < n; ++i) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i) sa[--cnt[rank[tmp[i]]]] = tmp[i];

        // assign new rank
        nrank[sa[0]] = 0;
        cl = 0;
        for (int i = 1; i < n; ++i) {
            if (rank[sa[i - 1]] != rank[sa[i]] ||
                (sa[i - 1] + k < n ? rank[sa[i - 1] + k] : -1) !=
                    (sa[i] + k < n ? rank[sa[i] + k] : -1)) {
                ++cl;
            }
            nrank[sa[i]] = cl;
        }
        rank.swap(nrank);
    }
    return sa;
}

std::vector<int> suffix_array(const std::string& s) {
    return suffix_array(std::vector<char>(s.begin(), s.end()));
}

template <typename T>
std::vector<int> cyclic_suffix_array(const std::vector<T>& s) {
    const int n = s.size();
    std::vector<int> sa(n);
    std::iota(sa.begin(), sa.end(), 0);
    std::ranges::sort(sa, {}, [&](int i) { return s[i]; });
    int cl = 0;
    std::vector<int> rank(n);
    for (int i = 1; i < n; ++i) {
        if (s[sa[i - 1]] != s[sa[i]]) ++cl;
        rank[sa[i]] = cl;
    }
    std::vector<int> tmp(n), nrank(n), cnt(n);
    for (int k = 1; k < n; k <<= 1) {
        // sort by second half
        int cnt1 = 0, cnt2 = k;
        for (int i = 0; i < n; ++i) {
            int j = sa[i] - k;
            if (j >= 0)
                tmp[cnt2++] = j;
            else
                tmp[cnt1++] = j + n;
        }

        // sort by first half
        std::ranges::fill(cnt, 0);
        for (int i = 0; i < n; ++i) ++cnt[rank[tmp[i]]];
        for (int i = 1; i < n; ++i) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i) sa[--cnt[rank[tmp[i]]]] = tmp[i];

        // assign new rank
        nrank[sa[0]] = 0;
        cl = 0;
        for (int i = 1; i < n; ++i) {
            if (rank[sa[i - 1]] != rank[sa[i]] ||
                rank[(sa[i - 1] + k) % n] != rank[(sa[i] + k) % n]) {
                ++cl;
            }
            nrank[sa[i]] = cl;
        }
        rank.swap(nrank);
    }
    return sa;
}

std::vector<int> cyclic_suffix_array(const std::string& s) {
    return cyclic_suffix_array(std::vector<char>(s.begin(), s.end()));
}

/*
// comparator for substrings
// used for string matching with the suffix array

auto cmp = [&](int si, const string& t) {
    int sn = S.size(), tn = t.size();
    int ti = 0;
    for (; si < sn && ti < tn; ++si, ++ti) {
        if (T[si] < t[ti]) return true;
        if (T[si] > t[ti]) return false;
    }
    return si == sn && ti < tn;
};
*/
