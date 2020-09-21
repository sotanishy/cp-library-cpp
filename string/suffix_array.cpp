#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Suffix Array
 * @docs docs/string/suffix_array.md
 */
class SuffixArray {
public:
    explicit SuffixArray(const string& str) : s(str) {
        int n = s.size();
        sa.resize(n);
        iota(sa.begin(), sa.end(), 0);
        sort(sa.begin(), sa.end(), [&](int i, int j) {
            return s[i] == s[j] ? i > j : s[i] < s[j];
        });
        int cl = 0;
        vector<int> rank(n);
        for (int i = 1; i < n; i++) {
            if (s[sa[i-1]] != s[sa[i]]) cl++;
            rank[sa[i]] = cl;
        }
        vector<int> tmp(n), nrank(n), cnt(n);
        for (int k = 1; k < n; k *= 2) {
            for (int i = 0; i < n; i++) {
                tmp[i] = sa[i] - k;
                if (tmp[i] < 0) tmp[i] += n;
            }
            fill(cnt.begin(), cnt.end(), 0);
            for (int i = 0; i < n; i++) cnt[rank[tmp[i]]]++;
            for (int i = 1; i < n; i++) cnt[i] += cnt[i-1];
            for (int i = n - 1; i >= 0; i--) sa[--cnt[rank[tmp[i]]]] = tmp[i];
            nrank[sa[0]] = 0;
            cl = 0;
            for (int i = 1; i < n; i++) {
                if (rank[sa[i-1]] != rank[sa[i]] || rank[(sa[i-1] + k) % n] != rank[(sa[i] + k) % n]) {
                    cl++;
                }
                nrank[sa[i]] = cl;
            }
            swap(rank, nrank);
        }
    }

    int operator[](int k) const {
        return sa[k];
    }

    int lower_bound(const string& t) const {
        int lb = -1, ub = sa.size();
        while (ub - lb > 1) {
            int m = (lb + ub) / 2;
            if (lt_substr(t, sa[m])) lb = m;
            else ub = m;
        }
        return ub;
    }

    int upper_bound(string& t) const {
        t.back()++;
        int i = lower_bound(t);
        t.back()--;
        return i;
    }

private:
    vector<int> sa;
    const string s;

    bool lt_substr(const string& t, int si = 0, int ti = 0) const {
        int sn = s.size(), tn = t.size();
        while (si < sn && ti < tn) {
            if (s[si] < t[ti]) return true;
            if (s[si] > t[ti]) return false;
            si++;
            ti++;
        }
        return si >= sn && ti < tn;
    }
};
