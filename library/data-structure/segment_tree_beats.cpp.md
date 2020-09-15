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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: Segment Tree Beats <small>(data-structure/segment_tree_beats.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/segment_tree_beats.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-15 16:09:04+09:00




# Segment Tree Beats

Segment tree beats は，遅延伝搬セグメント木の亜種で，区間 chmin/chmax/add 更新と区間 min/max/sum クエリを処理できる．

時間計算量は $O(\lg^2 n)$ ではなく $O(\lg n)$かもしれない．よくわからないのでここでは前者を使用する（表記として間違ってはいない）．

空間計算量: $O(n)$

## Template parameters

- `T`
    - 要素の型

## Constructor

- `SegmentTreeBeats(int n)`
    - サイズ`n`で要素がすべて 0 の segment tree beats を構築する
    - 時間計算量: $O(n)$
- `SegmentTreeBeats(const vector<T>& v)`
    - `v`の要素からサイズ`n = v.size()`の segment tree beats を構築する
    - 時間計算量: $O(n)$

## Member functions

- `T operator[](int k)`
    - $a_k$ を返す
    - 時間計算量: $O(\lg^2 n)$
- `void chmin(int l, int r, T x)`
    - $i \in [l, r)$ について $a_i$ を $min(a_i, x)$ に更新する
    - 時間計算量: $O(\lg^2 n)$
- `void chmax(int l, int r, T x)`
    - $i \in [l, r)$ について $a_i$ を $max(a_i, x)$ に更新する
    - 時間計算量: $O(\lg^2 n)$
- `void add(int l, int r, T x)`
    - $i \in [l, r)$ について $a_i$ を $a_i + x$ に更新する
    - 時間計算量: $O(\lg^2 n)$
- `T fold_min(int l, int r)`
    - $min(a_l, a_{l+1}, \cdots, a_{r-1})$ を計算する
    - 時間計算量: $O(\lg^2 n)$
- `T fold_max(int l, int r)`
    - $min(a_l, a_{l+1}, \cdots, a_{r-1})$ を計算する
    - 時間計算量: $O(\lg^2 n)$
- `T fold_sum(int l, int r)`
    - $min(a_l, a_{l+1}, \cdots, a_{r-1})$ を計算する
    - 時間計算量: $O(\lg^2 n)$

## Reference

[A simple introduction to "Segment tree beats"](https://codeforces.com/blog/entry/5731)

## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/range_chmin_chmax_add_range_sum.test.cpp.html">test/yosupo/range_chmin_chmax_add_range_sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

