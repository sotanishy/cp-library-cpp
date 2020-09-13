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


# :heavy_check_mark: Sparse Table <small>(data-structure/sparse_table.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/sparse_table.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 10:49:49+09:00




# Sparse Table

A sparse table is a data structure that can quickly answer range queries on a static sequence of an idempotent semigroup $(T, \cdot)$.

An idempotent binary operation is a mapping $\cdot: T \times T \rightarrow T$ such that $\forall a \in T, a \cdot a = a$.Idempotent binary operations include: max, min, gcd, bitwise and, and bitwise or.

Space complexity: $O(n \lg n)$

## Template parameters

- `T`
    - The type of the set $T$.

- `T op(T, T)`
    - An associative and idempotent binary operation $\cdot: T \times T \rightarrow T$.

## Constructor

- `SparseTable(const vector<T>& v)`
    - Constructs a sparse table from `v`
    - Time complexity: $O(n \lg n)$

## Member functions

- `T fold(size_t l, size_t r)`
    - Calculates $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$.
    - Time complexity: $O(1)$

## Note

$\cdot$ is not required to be commutative, as the overlapping part reduces to a single sequence due to idempotence.

## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_3_D.test.cpp.html">test/aoj/DSL_3_D.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Sparse Table
 * @docs docs/data-structure/sparse_table.md
 */
template <typename T, T (*op)(T, T)>
struct SparseTable {
    vector<vector<T>> lookup;

    SparseTable(const vector<T>& v) {
        size_t n = v.size(), b = 0;
        while ((1 << b) <= n) b++;
        lookup.resize(b, vector<T>(n));
        copy(v.begin(), v.end(), lookup[0].begin());
        for (size_t i = 1; i < b; i++) {
            for (size_t j = 0; j + (1 << i) <= n; j++) {
                lookup[i][j] = op(lookup[i - 1][j], lookup[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T fold(size_t l, size_t r) {
        size_t i = 31 - __builtin_clz(r - l);
        return op(lookup[i][l], lookup[i][r - (1 << i)]);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/sparse_table.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Sparse Table
 * @docs docs/data-structure/sparse_table.md
 */
template <typename T, T (*op)(T, T)>
struct SparseTable {
    vector<vector<T>> lookup;

    SparseTable(const vector<T>& v) {
        size_t n = v.size(), b = 0;
        while ((1 << b) <= n) b++;
        lookup.resize(b, vector<T>(n));
        copy(v.begin(), v.end(), lookup[0].begin());
        for (size_t i = 1; i < b; i++) {
            for (size_t j = 0; j + (1 << i) <= n; j++) {
                lookup[i][j] = op(lookup[i - 1][j], lookup[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T fold(size_t l, size_t r) {
        size_t i = 31 - __builtin_clz(r - l);
        return op(lookup[i][l], lookup[i][r - (1 << i)]);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

