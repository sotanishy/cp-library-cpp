#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct RMQ {
    int n;
    vector<T> node;
    const int INF = 1e9;

    RMQ(int size) {
        n = 1;
        while (n < size) n << 1;
        node.resize(2 * n - 1, INF);
    }

    void update(int i, T x) {
        i += n - 1;
        node[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            node[i] = min(node[i * 2 + 1], node[i* 2 + 2]);
        }
    }

    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = n;

        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b) return node[k];
        int m = (l + r) / 2;
        T vl = query(a, b, k * 2 + 1, l, m);
        T vr = query(a, b, k * 2 + 2, m, r);
        return min(vl, vr);
    }
};