#pragma once
#include <algorithm>
#include <cassert>
#include <map>
#include <vector>

template <typename T, typename Compare>
void merge_sort(std::vector<T>& arr, int l, int r, Compare cmp) {
    if (r - l == 1) return;

    int m = (l + r) / 2;
    merge_sort(arr, l, m, cmp);
    merge_sort(arr, m, r, cmp);

    std::vector<T> res;
    res.reserve(r - l);
    int i = l, j = m;
    while (i < m && j < r) {
        if (cmp(arr[i], arr[j])) {
            res.push_back(arr[i++]);
        } else {
            res.push_back(arr[j++]);
        }
    }

    while (i < m) res.push_back(arr[i++]);
    while (j < r) res.push_back(arr[j++]);

    for (int k = 0; k < r - l; ++k) arr[l + k] = res[k];
}

// elements need to be distinct
template <typename Compare>
void merge_insertion_sort(std::vector<int>& arr, Compare cmp) {
    int n = arr.size();
    if (n <= 1) return;

    std::map<int, int> idx;
    for (int k = 0; k < n; ++k) {
        assert(!idx.count(arr[k]));
        idx[arr[k]] = k;
    }

    // pair elements and recursively sort the bigger ones
    std::vector<int> a;
    for (int k = 0; k < n - 1; k += 2) {
        a.push_back(cmp(arr[k], arr[k + 1]) ? arr[k + 1] : arr[k]);
    }
    merge_insertion_sort(a, cmp);

    // a: sorted
    // b: not sorted
    a.insert(a.begin(), arr[idx[a[0]] ^ 1]);
    std::vector<int> b;
    for (int k = 2; k < (int)a.size(); ++k) {
        b.push_back(arr[idx[a[k]] ^ 1]);
    }
    if (n % 2 == 1) {
        b.push_back(arr.back());
    }

    // insert b into a
    int s = 0, prev = 0;
    for (int i = 0; s < (int)b.size(); ++i) {
        int g = std::min((1 << (i + 1)) - prev, (int)b.size() - s);
        for (int k = g - 1; k >= 0; --k) {
            int x = b[s + k];
            // the first element guaranteed to be bigger than x
            int right = a.size();
            if ((idx[x] ^ 1) < n) {
                // this takes O(n)
                // it can be made O(log n) with a Fenwick tree
                right =
                    std::find(a.begin(), a.end(), arr[idx[x] ^ 1]) - a.begin();
            }
            // search insertion point
            int lb = -1, ub = right;
            while (ub - lb > 1) {
                int m = (lb + ub) / 2;
                if (cmp(x, a[m]))
                    ub = m;
                else
                    lb = m;
            }
            a.insert(a.begin() + ub, x);
        }
        s += g;
        prev = g;
    }

    arr = a;
}
