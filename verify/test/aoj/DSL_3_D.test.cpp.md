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


# :heavy_check_mark: test/aoj/DSL_3_D.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_3_D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 10:49:49+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data-structure/sparse_table.cpp.html">Sparse Table <small>(data-structure/sparse_table.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include "../../data-structure/sparse_table.cpp"

int f(const int a, const int b) { return min(a, b); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, L;
    cin >> N >> L;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    SparseTable<int, f> st(a);

    for (int i = 0; i < N - L + 1; i++) {
        cout << st.fold(i, i + L);
        if (i < N - L) cout << " ";
        else cout << "\n";
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_3_D.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

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
#line 4 "test/aoj/DSL_3_D.test.cpp"

int f(const int a, const int b) { return min(a, b); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, L;
    cin >> N >> L;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    SparseTable<int, f> st(a);

    for (int i = 0; i < N - L + 1; i++) {
        cout << st.fold(i, i + L);
        if (i < N - L) cout << " ";
        else cout << "\n";
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

