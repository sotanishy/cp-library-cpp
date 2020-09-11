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
    - Last commit date: 2020-09-11 18:56:12+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data-structure/sparse_table.cpp.html">Sparse Table <small>(data-structure/sparse_table.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include "../../data-structure/sparse_table.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, L;
    cin >> N >> L;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    SparseTable<int> st(a);

    for (int i = 0; i < N - L + 1; i++) {
        cout << st.query(i, i + L);
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
template <typename T>
struct SparseTable {
private:
    vector<vector<T>> lookup;
    vector<int> len;

public:
    SparseTable(const vector<int>& v) {
        int n = 1;
        int b = 0;
        while (n <= v.size()) {
            n <<= 1;
            b++;
        }
        lookup.resize(v.size(), vector<int>(b));
        for (int i = 0; i < v.size(); i++) lookup[i][0] = v[i];
        for (int j = 1; j < b; j++) {
            for (int i = 0; i + (1 << j) <= v.size(); i++) {
                lookup[i][j] = min(lookup[i][j-1], lookup[i + (1 << (j-1))][j-1]);
            }
        }
        len.resize(v.size() + 1);
        for (int i = 2; i <= v.size(); i++) {
            len[i] = len[i / 2] + 1;
        }
    }

    T query(int l, int r) {
        int b = len[r - l];
        return min(lookup[l][b], lookup[r - (1 << b)][b]);
    }
};
#line 4 "test/aoj/DSL_3_D.test.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, L;
    cin >> N >> L;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    SparseTable<int> st(a);

    for (int i = 0; i < N - L + 1; i++) {
        cout << st.query(i, i + L);
        if (i < N - L) cout << " ";
        else cout << "\n";
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

