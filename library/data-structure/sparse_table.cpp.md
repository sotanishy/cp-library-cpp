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
    - Last commit date: 2020-09-12 22:11:54+09:00




# Sparse Table

A sparse table is a data structure that can quickly answer range queries on a static sequence of a semigroup $(T, \cdot)$.

The binary operation $\cdot: T \times T \rightarrow T$ must be idempotent i.e. $\forall a \in T, a \cdot a = a$

Idempotent binary operations include: max, min, gcd, bitwise and, and bitwise or.

Space complexity: $O(n \lg n)$

## Template parameters

- `T`
    - The type of the elements.

- `T op(T, T)`
    - An associative and idempotent binary operation $\cdot: T \times T \rightarrow T$.

## Constructor

- `SparseTable(const vector<T>& v)`
    - Constructs a sparse table from `v`
    - Time complexity: $O(n \lg n)$

## Member functions

- `T query(int l, int r)`
    - Calculates $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$.
    - Time complexity: $O(1)$

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
private:
    vector<vector<T>> lookup;
    vector<int> len;

public:
    SparseTable(const vector<T>& v) {
        int n = 1;
        int b = 0;
        while (n <= v.size()) {
            n <<= 1;
            b++;
        }
        lookup.resize(v.size(), vector<T>(b));
        for (int i = 0; i < v.size(); i++) lookup[i][0] = v[i];
        for (int j = 1; j < b; j++) {
            for (int i = 0; i + (1 << j) <= v.size(); i++) {
                lookup[i][j] = op(lookup[i][j-1], lookup[i + (1 << (j-1))][j-1]);
            }
        }
        len.resize(v.size() + 1);
        for (int i = 2; i <= v.size(); i++) {
            len[i] = len[i / 2] + 1;
        }
    }

    T query(int l, int r) {
        int b = len[r - l];
        return op(lookup[l][b], lookup[r - (1 << b)][b]);
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
private:
    vector<vector<T>> lookup;
    vector<int> len;

public:
    SparseTable(const vector<T>& v) {
        int n = 1;
        int b = 0;
        while (n <= v.size()) {
            n <<= 1;
            b++;
        }
        lookup.resize(v.size(), vector<T>(b));
        for (int i = 0; i < v.size(); i++) lookup[i][0] = v[i];
        for (int j = 1; j < b; j++) {
            for (int i = 0; i + (1 << j) <= v.size(); i++) {
                lookup[i][j] = op(lookup[i][j-1], lookup[i + (1 << (j-1))][j-1]);
            }
        }
        len.resize(v.size() + 1);
        for (int i = 2; i <= v.size(); i++) {
            len[i] = len[i / 2] + 1;
        }
    }

    T query(int l, int r) {
        int b = len[r - l];
        return op(lookup[l][b], lookup[r - (1 << b)][b]);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

