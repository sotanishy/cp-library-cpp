---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/range_chmin_chmax_add_range_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-15 16:09:04+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum">https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data-structure/segment_tree_beats.cpp.html">Segment Tree Beats <small>(data-structure/segment_tree_beats.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "../../data-structure/segment_tree_beats.cpp"

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    SegmentTreeBeats<ll> st(a);
    for (int i = 0; i < Q; i++) {
        int t, l, r;
        ll b;
        cin >> t >> l >> r;
        if (t != 3) cin >> b;
        if (t == 0) {
            st.chmin(l, r, b);
        } else if (t == 1) {
            st.chmax(l, r, b);
        } else if (t == 2) {
            st.add(l, r, b);
        } else {
            cout << st.fold_sum(l, r) << "\n";
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/range_chmin_chmax_add_range_sum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#line 1 "data-structure/segment_tree_beats.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Segment Tree Beats
 * @docs docs/data-structure/segment_tree_beats.md
 */
template <typename T>
struct SegmentTreeBeats {

    SegmentTreeBeats(int n) : SegmentTreeBeats(vector<T>(n)) {}
    SegmentTreeBeats(const vector<T>& v) {
        size = 1;
        while (size < v.size()) size <<= 1;
        sum.resize(2 * size);
        lazy.resize(2 * size);
        max_val.resize(2 * size, NINF);
        smax_val.resize(2 * size, NINF);
        max_cnt.resize(2 * size);
        min_val.resize(2 * size, INF);
        smin_val.resize(2 * size, INF);
        min_cnt.resize(2 * size);
        len.resize(2 * size);
        len[1] = size;
        for (int i = 2; i < 2 * size; i++) len[i] = len[i / 2] >> 1;
        for (int i = 0; i < v.size(); i++) {
            sum[size + i] = max_val[size + i] = min_val[size + i] = v[i];
            max_cnt[size + i] = min_cnt[size + i] = 1;
        }
        for (int i = size - 1; i > 0; i--) recalc(i);
    }

    T operator[](int k) {
        return fold_sum(k, k + 1);
    }

    void chmin(int l, int r, T x) { update<CHMIN>(l, r, x, 1, 0, size); }
    void chmax(int l, int r, T x) { update<CHMAX>(l, r, x, 1, 0, size); }
    void add(int l, int r, T x) { update<ADD>(l, r, x, 1, 0, size); }

    T fold_min(int l, int r) { return fold<MIN>(l, r, 1, 0, size); }
    T fold_max(int l, int r) { return fold<MAX>(l, r, 1, 0, size); }
    T fold_sum(int l, int r) { return fold<SUM>(l, r, 1, 0, size); }

private:
    const T INF = numeric_limits<T>::max();
    const T NINF = numeric_limits<T>::min();

    int size;
    vector<T> sum, lazy;
    vector<T> max_val, smax_val;
    vector<T> min_val, smin_val;
    vector<int> len, max_cnt, min_cnt;

    enum OpType {
        CHMIN, CHMAX, ADD
    };

    enum QueryType {
        MIN, MAX, SUM
    };

    void recalc(int k) {
        sum[k] = sum[2 * k] + sum[2 * k + 1];

        if (max_val[2 * k] > max_val[2 * k + 1]) {
            max_val[k] = max_val[2 * k];
            max_cnt[k] = max_cnt[2 * k];
            smax_val[k] = max(smax_val[2 * k], max_val[2 * k + 1]);
        } else if (max_val[2 * k] < max_val[2 * k + 1]) {
            max_val[k] = max_val[2 * k + 1];
            max_cnt[k] = max_cnt[2 * k + 1];
            smax_val[k] = max(max_val[2 * k], smax_val[2 * k + 1]);
        } else {
            max_val[k] = max_val[2 * k];
            max_cnt[k] = max_cnt[2 * k] + max_cnt[2 * k + 1];
            smax_val[k] = max(smax_val[2 * k], smax_val[2 * k + 1]);
        }

        if (min_val[2 * k] < min_val[2 * k + 1]) {
            min_val[k] = min_val[2 * k];
            min_cnt[k] = min_cnt[2 * k];
            smin_val[k] = min(smin_val[2 * k], min_val[2 * k + 1]);
        } else if (min_val[2 * k] > min_val[2 * k + 1]) {
            min_val[k] = min_val[2 * k + 1];
            min_cnt[k] = min_cnt[2 * k + 1];
            smin_val[k] = min(min_val[2 * k], smin_val[2 * k + 1]);
        } else {
            min_val[k] = min_val[2 * k];
            min_cnt[k] = min_cnt[2 * k] + min_cnt[2 * k + 1];
            smin_val[k] = min(smin_val[2 * k], smin_val[2 * k + 1]);
        }
    }

    template <OpType TYPE>
    void tag(int k, T x) {
        if (TYPE == CHMIN) {
            sum[k] += (x - max_val[k]) * max_cnt[k];
            if (max_val[k] == min_val[k]) min_val[k] = x;
            else if (max_val[k] == smin_val[k]) smin_val[k] = x;
            max_val[k] = x;
        } else if (TYPE == CHMAX) {
            sum[k] += (x - min_val[k]) * min_cnt[k];
            if (min_val[k] == max_val[k]) max_val[k] = x;
            else if (min_val[k] == smax_val[k]) smax_val[k] = x;
            min_val[k] = x;
        } else if (TYPE == ADD) {
            min_val[k] += x;
            if (smin_val[k] != INF) smin_val[k] += x;
            max_val[k] += x;
            if (smax_val[k] != NINF) smax_val[k] += x;
            sum[k] += x * len[k];
            lazy[k] += x;
        }
    }

    void push(int k) {
        if (lazy[k] != 0) {
            tag<ADD>(2 * k, lazy[k]);
            tag<ADD>(2 * k + 1, lazy[k]);
            lazy[k] = 0;
        }
        if (max_val[k] < max_val[2 * k]) tag<CHMIN>(2 * k, max_val[k]);
        if (min_val[k] > min_val[2 * k]) tag<CHMAX>(2 * k, min_val[k]);
        if (max_val[k] < max_val[2 * k + 1]) tag<CHMIN>(2 * k + 1, max_val[k]);
        if (min_val[k] > min_val[2 * k + 1]) tag<CHMAX>(2 * k + 1, min_val[k]);
    }

    template <OpType TYPE>
    inline bool break_cond(int k, T x) {
        if (TYPE == CHMIN) return max_val[k] <= x;
        if (TYPE == CHMAX) return min_val[k] >= x;
        if (TYPE == ADD) return false;
    }

    template <OpType TYPE>
    inline bool tag_cond(int k, T x) {
        if (TYPE == CHMIN) return smax_val[k] < x;
        if (TYPE == CHMAX) return smin_val[k] > x;
        if (TYPE == ADD) return true;
    }

    template <OpType TYPE>
    void update(int a, int b, T x, int k, int l, int r) {
        if (r <= a || b <= l || break_cond<TYPE>(k, x)) return;
        if (a <= l && r <= b && tag_cond<TYPE>(k, x)) {
            tag<TYPE>(k, x);
            return;
        }
        push(k);
        int m = (l + r) / 2;
        update<TYPE>(a, b, x, 2 * k, l, m);
        update<TYPE>(a, b, x, 2 * k + 1, m, r);
        recalc(k);
    }

    template <QueryType TYPE>
    T fold(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            if (TYPE == MIN) return INF;
            if (TYPE == MAX) return NINF;
            if (TYPE == SUM) return 0;
        }
        if (a <= l && r <= b) {
            if (TYPE == MIN) return min_val[k];
            if (TYPE == MAX) return max_val[k];
            if (TYPE == SUM) return sum[k];
        }
        push(k);
        int m = (l + r) / 2;
        T vl = fold<TYPE>(a, b, 2 * k, l, m);
        T vr = fold<TYPE>(a, b, 2 * k + 1, m, r);
        if (TYPE == MIN) return min(vl, vr);
        if (TYPE == MAX) return max(vl, vr);
        if (TYPE == SUM) return vl + vr;
        return -1;
    }
};
#line 4 "test/yosupo/range_chmin_chmax_add_range_sum.test.cpp"

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    SegmentTreeBeats<ll> st(a);
    for (int i = 0; i < Q; i++) {
        int t, l, r;
        ll b;
        cin >> t >> l >> r;
        if (t != 3) cin >> b;
        if (t == 0) {
            st.chmin(l, r, b);
        } else if (t == 1) {
            st.chmax(l, r, b);
        } else if (t == 2) {
            st.add(l, r, b);
        } else {
            cout << st.fold_sum(l, r) << "\n";
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

