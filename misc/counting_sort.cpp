#include <bits/stdc++.h>

std::vector<int> counting_sort(const std::vector<int>& v, int k) {
    std::vector<int> cnt(k + 1);
    for (int i = 0; i < (int) v.size(); ++i) ++cnt[v[i]];
    for (int i = 1; i <= k; ++i) cnt[i] += cnt[i - 1];
    std::vector<int> ret(v.size());
    for (int i = v.size() - 1; i >= 0; --i) ret[--cnt[v[i]]] = v[i];
    return ret;
}