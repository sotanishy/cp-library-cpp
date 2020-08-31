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


# :heavy_check_mark: test/aoj/DSL_1_B.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_1_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 10:11:59+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data-structure/weighted_union_find.cpp.html">data-structure/weighted_union_find.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

#include "../../data-structure/weighted_union_find.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    WeightedUnionFind<int> wuf(n);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int x, y, z;
            cin >> x >> y >> z;
            wuf.unite(x, y, z);
        } else {
            int x, y;
            cin >> x >> y;
            if (wuf.same(x, y)) cout << wuf.diff(x, y) << "\n";
            else cout << "?\n";
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_1_B.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

#line 1 "data-structure/weighted_union_find.cpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct WeightedUnionFind {
    vector<int> par;
    vector<T> ws;

    WeightedUnionFind(int n) : par(n, -1), ws(n) {}

    int find(int x) {
        if (par[x] < 0) return x;
        int r = find(par[x]);
        ws[x] += ws[par[x]];
        return par[x] = r;
    }

    T weight(int x) {
        find(x);
        return ws[x];
    }

    bool unite(int x, int y, T w) {
        w += weight(x);
        w -= weight(y);
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (par[x] > par[y]) {
            swap(x, y);
            w = -w;
        }
        par[x] += par[y];
        par[y] = x;
        ws[y] = w;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    T diff(int x, int y) {
        return weight(y) - weight(x);
    }

    int size(int x) {
        return -par[find(x)];
    }
};
#line 4 "test/aoj/DSL_1_B.test.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    WeightedUnionFind<int> wuf(n);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int x, y, z;
            cin >> x >> y >> z;
            wuf.unite(x, y, z);
        } else {
            int x, y;
            cin >> x >> y;
            if (wuf.same(x, y)) cout << wuf.diff(x, y) << "\n";
            else cout << "?\n";
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

