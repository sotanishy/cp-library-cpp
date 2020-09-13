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


# :heavy_check_mark: Diameter of a Tree <small>(tree/tree_diameter.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/tree_diameter.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 23:11:46+09:00




# Diameter of a Tree

This struct calculates the diameter of the given tree using DFS.

## Methods

- `static int diameter(vector<vector<int>>& G)`
    - Calculates the diameter of the tree $G$ where the  weights of all edges are 1.
    - Time complexity: $O(n)$
- `static T diameter(vector<vector<Edge<T>>>& G)`
    - Calculates the diameter of the tree $G$.
    - Time complexity: $O(n)$

## Depends on

* :question: <a href="../graph/edge.cpp.html">graph/edge.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_A.test.cpp.html">test/aoj/GRL_5_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
#include "../graph/edge.cpp"
using namespace std;

/*
 * @brief Diameter of a Tree
 * @docs docs/tree/tree_diameter.md
 */
struct TreeDiameter {
public:
    static int diameter(vector<vector<int>>& G) {
        auto p = dfs(G, 0, -1);
        auto q = dfs(G, p.second, -1);
        return q.first;
    }

    template <typename T>
    static T diameter(vector<vector<Edge<T>>>& G) {
        auto p = dfs(G, 0, -1);
        auto q = dfs(G, p.second, -1);
        return q.first;
    }

private:
    static pair<int, int> dfs(vector<vector<int>>& G, int v, int p) {
        pair<int, int> ret(0, v);
        for (int c : G[v]) {
            if (c == p) continue;
            auto cost = dfs(G, c, v);
            cost.first++;
            ret = max(ret, cost);
        }
        return ret;
    }

    template <typename T>
    static pair<T, int> dfs(vector<vector<Edge<T>>>& G, int v, int p) {
        pair<T, int> ret(0, v);
        for (auto& e : G[v]) {
            if (e.to == p) continue;
            auto cost = dfs(G, e.to, v);
            cost.first += e.cost;
            ret = max(ret, cost);
        }
        return ret;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tree/tree_diameter.cpp"
#include <bits/stdc++.h>
#line 2 "graph/edge.cpp"
using namespace std;

template <typename T>
struct Edge {
    int from, to;
    T cost;
    Edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};
#line 3 "tree/tree_diameter.cpp"
using namespace std;

/*
 * @brief Diameter of a Tree
 * @docs docs/tree/tree_diameter.md
 */
struct TreeDiameter {
public:
    static int diameter(vector<vector<int>>& G) {
        auto p = dfs(G, 0, -1);
        auto q = dfs(G, p.second, -1);
        return q.first;
    }

    template <typename T>
    static T diameter(vector<vector<Edge<T>>>& G) {
        auto p = dfs(G, 0, -1);
        auto q = dfs(G, p.second, -1);
        return q.first;
    }

private:
    static pair<int, int> dfs(vector<vector<int>>& G, int v, int p) {
        pair<int, int> ret(0, v);
        for (int c : G[v]) {
            if (c == p) continue;
            auto cost = dfs(G, c, v);
            cost.first++;
            ret = max(ret, cost);
        }
        return ret;
    }

    template <typename T>
    static pair<T, int> dfs(vector<vector<Edge<T>>>& G, int v, int p) {
        pair<T, int> ret(0, v);
        for (auto& e : G[v]) {
            if (e.to == p) continue;
            auto cost = dfs(G, e.to, v);
            cost.first += e.cost;
            ret = max(ret, cost);
        }
        return ret;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

