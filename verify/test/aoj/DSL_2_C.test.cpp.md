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


# :x: test/aoj/DSL_2_C.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 10:49:49+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C</a>


## Depends on

* :x: <a href="../../../library/data-structure/kd_tree.cpp.html">k-d Tree <small>(data-structure/kd_tree.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C"

#include "../../data-structure/kd_tree.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    KDTree<int> kd_tree;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        kd_tree.add_point(i, x, y);
    }
    kd_tree.build();
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int sx, tx, sy, ty;
        cin >> sx >> tx >> sy >> ty;
        auto res = kd_tree.search(sx, tx, sy, ty);
        sort(res.begin(), res.end());
        for (int j : res) cout << j << "\n";
        cout << "\n";
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_C.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C"

#line 1 "data-structure/kd_tree.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief k-d Tree
 * @docs docs/data-structure/kd_tree.md
 */
template <typename T>
struct KDTree {
public:
    void add_point(int id, T x, T y) {
        points.emplace_back(id, x, y);
    }

    void build() {
        build_rec(0, points.size(), 0);
    }

    vector<int> search(T sx, T tx, T sy, T ty) {
        Point s(min(sx, tx), min(sy, ty));
        Point t(max(sx, tx), max(sy, ty));
        vector<int> res;
        search_rec(s, t, res, 0, points.size(), 0);
        return res;
    }

private:
    struct Point {
        int id;
        T x, y;
        Point(T x, T y) : x(x), y(y) {}
        Point(int id, T x, T y) : id(id), x(x), y(y) {}
    };

    vector<Point> points;

    int check_position(Point& point, Point& start, Point& end, int axis) {
        if (axis == 0) {
            if (start.x <= point.x && point.x <= end.x) return 0;
            if (point.x < start.x) return -1;
            return 1;
        } else {
            if (start.y <= point.y && point.y <= end.y) return 0;
            if (point.y < start.y) return -1;
            return 1;
        }
    }

    void build_rec(size_t left, size_t right, int depth) {
        if (left > right) return;

        int axis = depth % 2;
        if (axis == 0) sort(points.begin() + left, points.begin() + right, [](const auto& p1, const auto& p2) { return p1.x < p2.x; });
        else sort(points.begin() + left, points.begin() + right, [](const auto& p1, const auto& p2) { return p1.y < p2.y; });
        size_t mid = (left + right) / 2;
        build_rec(left, mid, depth + 1);
        build_rec(mid + 1, right, depth + 1);
    }

    void search_rec(Point& start, Point& end, vector<int>& res, size_t left, size_t right, int depth) {
        if (left > right) return;

        int axis = depth % 2;
        size_t mid = (left + right) / 2;
        bool contained = true;
        for (int i = 0; i < 2; i++) contained &= check_position(points[mid], start, end, i) == 0;
        if (contained) res.push_back(points[mid].id);
        if (left == right) return;
        int pos = check_position(points[mid], start, end, axis);
        if (pos != -1) search_rec(start, end, res, left, mid, depth + 1);
        if (pos != 1) search_rec(start, end, res, mid + 1, right, depth + 1);
    }
};
#line 4 "test/aoj/DSL_2_C.test.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    KDTree<int> kd_tree;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        kd_tree.add_point(i, x, y);
    }
    kd_tree.build();
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int sx, tx, sy, ty;
        cin >> sx >> tx >> sy >> ty;
        auto res = kd_tree.search(sx, tx, sy, ty);
        sort(res.begin(), res.end());
        for (int j : res) cout << j << "\n";
        cout << "\n";
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

