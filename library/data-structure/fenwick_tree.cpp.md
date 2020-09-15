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


# :heavy_check_mark: Fenwick Tree <small>(data-structure/fenwick_tree.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/fenwick_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 16:31:52+09:00




# Fenwick Tree

Fenwick tree，または binary indexed tree は，可換モノイド $(T, \cdot, e)$ の列 $(a_0, a_1, \dots, a_{n-1})$ を管理し，一点更新と接頭辞へのクエリを処理できるデータ構造である．

セグメント木より制約が強く，操作が限られているが，実装が簡潔で定数倍速い．

空間計算量: $O(n)$

## Template parameters

- `M`
    - 可換モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的かつ可換な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `FenwickTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e$ の Fenwick tree を構築する
    - 時間計算量: $O(n)$

## Member functions

- `T prefix_fold(int i)`
    - $a_0 \cdot a_1 \cdot \cdots \cdot a_{i-1}$ を計算する
    - 時間計算量: $O(\lg n)$
- `void update(int i, T x)`
    - $a_i$ を $a_i \cdot x$ に更新する
    - 時間計算量: $O(\lg n)$
- `int find_first(const function<bool(T)>& cond)`
    - $a_0 \cdot a_1 \cdot \cdots \cdot a_{i-1}$ が条件 `cond` を満たすような最小の $i$ を返す．列の単調性を仮定する．そのような $i$ が存在しない場合は $n$ を返す．
    - 時間計算量: $O(\lg n)$

## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_B.test.cpp.html">test/aoj/DSL_2_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Fenwick Tree
 * @docs docs/data-structure/fenwick_tree.md
 */
template <typename M>
struct FenwickTree {
    using T = typename M::T;

    int n;
    vector<T> data;

    FenwickTree(int n) : n(n), data(n+1, M::id) {}

    T prefix_fold(int i) {
        T ret = M::id;
        for (; i > 0; i -= i & -i) ret = M::op(ret, data[i]);
        return ret;
    }

    void update(int i, T x) {
        for (i++; i <= n; i += i & -i) data[i] = M::op(data[i], x);
    }

    int find_first(const function<bool(T)>& cond) {
        int k = 1;
        while (k * 2 <= n) k <<= 1;
        int i = 0;
        T x = M::id;
        for (; k > 0; k >>= 1) {
            if (i + k <= n && !cond(M::op(x, data[i+k]))) {
                x = M::op(x, data[i+k]);
                i += k;
            }
        }
        return i - 1;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/fenwick_tree.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Fenwick Tree
 * @docs docs/data-structure/fenwick_tree.md
 */
template <typename M>
struct FenwickTree {
    using T = typename M::T;

    int n;
    vector<T> data;

    FenwickTree(int n) : n(n), data(n+1, M::id) {}

    T prefix_fold(int i) {
        T ret = M::id;
        for (; i > 0; i -= i & -i) ret = M::op(ret, data[i]);
        return ret;
    }

    void update(int i, T x) {
        for (i++; i <= n; i += i & -i) data[i] = M::op(data[i], x);
    }

    int find_first(const function<bool(T)>& cond) {
        int k = 1;
        while (k * 2 <= n) k <<= 1;
        int i = 0;
        T x = M::id;
        for (; k > 0; k >>= 1) {
            if (i + k <= n && !cond(M::op(x, data[i+k]))) {
                x = M::op(x, data[i+k]);
                i += k;
            }
        }
        return i - 1;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

