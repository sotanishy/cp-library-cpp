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


# :heavy_check_mark: Disjoint Sparse Table <small>(data-structure/disjoint_sparse_table.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/disjoint_sparse_table.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 01:20:21+09:00




# Disjoint Sparse Table

A disjoint sparse table is a data structure that can quickly answer range queries on a static sequence of a semigroup $(T, \cdot)$.

The binary operation $\cdot$ is not required to be idempotent; for idempotent operations, [a sparse table](sparse_table.md) might be faster by a constant factor.

Space complexity: $O(n \lg n)$

## Template parameters

- `T`
    - The type of the elements.

- `T op(T, T)`
    - An associative binary operation $\cdot: T \times T \rightarrow T$.

## Constructor

- `DisjointSparseTable(const vector<T>& v)`
    - Constructs a disjoint sparse table from `v`
    - Time complexity: $O(n \lg n)$

## Member functions

- `T query(int l, int r)`
    - Calculates $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$.
    - Time complexity: $O(1)$

## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/staticrmq.test.cpp.html">test/yosupo/staticrmq.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Disjoint Sparse Table
 * @docs docs/data-structure/disjoint_sparse_table.md
 */
template <typename T, T (*op)(T, T)>
struct DisjointSparseTable {
    vector<vector<T>> lookup;

    DisjointSparseTable(const vector<T>& v) {
        int n = v.size(), b = 0;
        while ((1 << b) < n) b++;
        lookup.resize(b + 1, vector<T>(n));
        copy(v.begin(), v.end(), lookup[0].begin());
        for (int i = 1; i <= b; i++) {
            int len = 1 << i;
            for (int l = 0; l + len / 2 < n; l += len) {
                int m = l + len / 2;
                lookup[i][m - 1] = v[m - 1];
                for (int j = m - 2; j >= l; j--) {
                    lookup[i][j] = op(v[j], lookup[i][j + 1]);
                }
                lookup[i][m] = v[m];
                for (int j = m + 1; j < min(l + len, n); j++) {
                    lookup[i][j] = op(lookup[i][j - 1], v[j]);
                }
            }
        }
    }

    T query(int l, int r) {
        if (r - l == 1) return lookup[0][l];
        int i = 32 - __builtin_clz(l ^ (r - 1));
        return op(lookup[i][l], lookup[i][r - 1]);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/disjoint_sparse_table.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Disjoint Sparse Table
 * @docs docs/data-structure/disjoint_sparse_table.md
 */
template <typename T, T (*op)(T, T)>
struct DisjointSparseTable {
    vector<vector<T>> lookup;

    DisjointSparseTable(const vector<T>& v) {
        int n = v.size(), b = 0;
        while ((1 << b) < n) b++;
        lookup.resize(b + 1, vector<T>(n));
        copy(v.begin(), v.end(), lookup[0].begin());
        for (int i = 1; i <= b; i++) {
            int len = 1 << i;
            for (int l = 0; l + len / 2 < n; l += len) {
                int m = l + len / 2;
                lookup[i][m - 1] = v[m - 1];
                for (int j = m - 2; j >= l; j--) {
                    lookup[i][j] = op(v[j], lookup[i][j + 1]);
                }
                lookup[i][m] = v[m];
                for (int j = m + 1; j < min(l + len, n); j++) {
                    lookup[i][j] = op(lookup[i][j - 1], v[j]);
                }
            }
        }
    }

    T query(int l, int r) {
        if (r - l == 1) return lookup[0][l];
        int i = 32 - __builtin_clz(l ^ (r - 1));
        return op(lookup[i][l], lookup[i][r - 1]);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

