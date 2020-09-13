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


# :heavy_check_mark: test/yosupo/unionfind.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/unionfind.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 10:49:49+09:00


* see: <a href="https://judge.yosupo.jp/problem/unionfind">https://judge.yosupo.jp/problem/unionfind</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data-structure/union_find.cpp.html">Union Find <small>(data-structure/union_find.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../data-structure/union_find.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    for (int i = 0; i < Q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) uf.unite(u, v);
        else cout << uf.same(u, v) << "\n";
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/unionfind.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#line 1 "data-structure/union_find.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Union Find
 * @docs docs/data-structure/union_find.md
 */
struct UnionFind {
    vector<int> par;

    UnionFind(size_t n) : par(n, -1) {}

    size_t find(size_t x) {
        if (par[x] < 0) return x;
        return par[x] = find(par[x]);
    }

    void unite(size_t x, size_t y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }

    bool same(size_t x, size_t y) {
        return find(x) == find(y);
    }

    size_t size(size_t x) {
        return -par[find(x)];
    }
};
#line 4 "test/yosupo/unionfind.test.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    for (int i = 0; i < Q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) uf.unite(u, v);
        else cout << uf.same(u, v) << "\n";
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

