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


# :x: Disjoint Sparse Table <small>(data-structure/disjoint_sparse_table.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/disjoint_sparse_table.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 12:09:22+09:00




# Disjoint Sparse Table

A disjoint sparse table is a data structure that can quickly answer range queries on a static sequence of a semigroup $(T, \cdot)$.

If the binary operation $\cdot$ is idempotent, a sparse table might be faster by a constant factor.

Space complexity: $O(n \lg n)$

## Template parameters

- `T`
    - The type of the set $T$.

- `T op(T, T)`
    - An associative binary operation $\cdot: T \times T \rightarrow T$.

## Constructor

- `DisjointSparseTable(const vector<T>& v)`
    - Constructs a disjoint sparse table from `v`
    - Time complexity: $O(n \lg n)$

## Member functions

- `T fold(size_t l, size_t r)`
    - Calculates $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$.
    - Time complexity: $O(1)$

## Verified with

* :x: <a href="../../verify/test/yosupo/staticrmq.test.cpp.html">test/yosupo/staticrmq.test.cpp</a>


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
        size_t n = v.size(), b = 0;
        while ((1 << b) < n) b++;
        lookup.resize(b + 1, vector<T>(n));
        copy(v.begin(), v.end(), lookup[0].begin());
        for (size_t i = 1; i <= b; i++) {
            size_t len = 1 << i;
            for (size_t l = 0; l + len / 2 < n; l += len) {
                size_t m = l + len / 2;
                lookup[i][m - 1] = v[m - 1];
                for (size_t j = 1; j < len / 2; j++) {
                    lookup[i][m - 1 - j] = op(v[j], lookup[i][m - j]);
                }
                lookup[i][m] = v[m];
                for (size_t j = 1; m + j < min(l + len, n); j++) {
                    lookup[i][m + j] = op(lookup[i][m + j - 1], v[j]);
                }
            }
        }
    }

    T fold(size_t l, size_t r) {
        if (r - l == 1) return lookup[0][l];
        size_t i = 32 - __builtin_clz(l ^ (r - 1));
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
        size_t n = v.size(), b = 0;
        while ((1 << b) < n) b++;
        lookup.resize(b + 1, vector<T>(n));
        copy(v.begin(), v.end(), lookup[0].begin());
        for (size_t i = 1; i <= b; i++) {
            size_t len = 1 << i;
            for (size_t l = 0; l + len / 2 < n; l += len) {
                size_t m = l + len / 2;
                lookup[i][m - 1] = v[m - 1];
                for (size_t j = 1; j < len / 2; j++) {
                    lookup[i][m - 1 - j] = op(v[j], lookup[i][m - j]);
                }
                lookup[i][m] = v[m];
                for (size_t j = 1; m + j < min(l + len, n); j++) {
                    lookup[i][m + j] = op(lookup[i][m + j - 1], v[j]);
                }
            }
        }
    }

    T fold(size_t l, size_t r) {
        if (r - l == 1) return lookup[0][l];
        size_t i = 32 - __builtin_clz(l ^ (r - 1));
        return op(lookup[i][l], lookup[i][r - 1]);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

