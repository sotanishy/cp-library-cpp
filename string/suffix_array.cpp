#pragma once
#include <algorithm>
#include <limits>
#include <string>
#include <vector>

/*
 * @brief Suffix Array
 * @docs docs/string/suffix_array.md
 */
class SuffixArray {
public:
    SuffixArray() = default;
    explicit SuffixArray(const std::string& str) : s(str) {
        int n = s.size();
        sa.resize(n);
        std::iota(sa.begin(), sa.end(), 0);
        std::sort(sa.begin(), sa.end(), [&](int i, int j) {
            return s[i] < s[j];
        });
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
                if (j >= 0) tmp[cnt2++] = j;
                else tmp[cnt1++] = j + n;
            }

            // sort by first half
            std::fill(cnt.begin(), cnt.end(), 0);
            for (int i = 0; i < n; ++i) ++cnt[rank[tmp[i]]];
            for (int i = 1; i < n; ++i) cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; --i) sa[--cnt[rank[tmp[i]]]] = tmp[i];

            // assign new rank
            nrank[sa[0]] = 0;
            cl = 0;
            for (int i = 1; i < n; ++i) {
                if (rank[sa[i - 1]] != rank[sa[i]]
                    || (sa[i - 1] + k < n ? rank[sa[i - 1] + k] : -1) != (sa[i] + k < n ? rank[sa[i] + k] : -1)) {
                    ++cl;
                }
                nrank[sa[i]] = cl;
            }
            std::swap(rank, nrank);
        }
    }

    int operator[](int k) const {
        return sa[k];
    }

    int lower_bound(const std::string& t) const {
        int lb = -1, ub = sa.size();
        while (ub - lb > 1) {
            int m = (lb + ub) / 2;
            if (lt_substr(t, sa[m])) lb = m;
            else ub = m;
        }
        return ub;
    }

    int upper_bound(const std::string& t) const {
        return lower_bound(t + std::numeric_limits<char>::max());
    }

private:
    std::vector<int> sa;
    const std::string s;

    bool lt_substr(const std::string& t, int si) const {
        int sn = s.size(), tn = t.size();
        int ti = 0;
        for (; si < sn && ti < tn; ++si, ++ti) {
            if (s[si] < t[ti]) return true;
            if (s[si] > t[ti]) return false;
        }
        return si >= sn && ti < tn;
    }
};