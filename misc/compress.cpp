#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Compress {
    vector<T> xs;

    Compress(const vector<T>& xs) : xs(xs) {
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
    }

    int compress(const T& x) {
        return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    }

    T decompress(int i) {
        return xs[i];
    }
};