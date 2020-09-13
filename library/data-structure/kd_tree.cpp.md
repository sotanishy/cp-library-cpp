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


# :heavy_check_mark: k-d Tree <small>(data-structure/kd_tree.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/kd_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 11:39:41+09:00




# k-d Tree

A k-d tree is a data structure that stores points in a $k$-dimensional space, which allows for efficient range searches.

This k-d tree supports axis-aligned rectangular range searches in a 2-dimensional space.

Space complexity: $O(n)$

## Member functions

- `void add_point(int id, T x, T y)`
    - Adds the point $(x, y)$ labeled `id`.
    - Time complexity: $O(1)$
- `void build()`
    - Builds a k-d tree.
    - Time complexity: $O(n\lg^2 n)$
- `vector<int> search(T sx, T tx, T sy, T ty)`
    - Returns the labels of points in the rectangular range from $(sx, sy)$ to $(tx, ty)$.
    - Time complexity: $O(\sqrt{N} + m)$, where $m$ is the number of reported points

## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_C.test.cpp.html">test/aoj/DSL_2_C.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
        build_rec(0, points.size() - 1, 0);
    }

    vector<int> search(T sx, T tx, T sy, T ty) {
        Point s(min(sx, tx), min(sy, ty));
        Point t(max(sx, tx), max(sy, ty));
        vector<int> res;
        search_rec(s, t, res, 0, points.size() - 1, 0);
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

    void build_rec(int left, int right, int depth) {
        if (left > right) return;

        int axis = depth % 2;
        if (axis == 0) sort(points.begin() + left, points.begin() + right + 1, [](const auto& p1, const auto& p2) { return p1.x < p2.x; });
        else sort(points.begin() + left, points.begin() + right + 1, [](const auto& p1, const auto& p2) { return p1.y < p2.y; });
        int mid = (left + right) / 2;
        build_rec(left, mid - 1, depth + 1);
        build_rec(mid + 1, right, depth + 1);
    }

    void search_rec(Point& start, Point& end, vector<int>& res, int left, int right, int depth) {
        if (left > right) return;

        int axis = depth % 2;
        int mid = (left + right) / 2;
        bool contained = true;
        for (int i = 0; i < 2; i++) contained &= check_position(points[mid], start, end, i) == 0;
        if (contained) res.push_back(points[mid].id);
        if (left == right) return;
        int pos = check_position(points[mid], start, end, axis);
        if (pos != -1) search_rec(start, end, res, left, mid - 1, depth + 1);
        if (pos != 1) search_rec(start, end, res, mid + 1, right, depth + 1);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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
        build_rec(0, points.size() - 1, 0);
    }

    vector<int> search(T sx, T tx, T sy, T ty) {
        Point s(min(sx, tx), min(sy, ty));
        Point t(max(sx, tx), max(sy, ty));
        vector<int> res;
        search_rec(s, t, res, 0, points.size() - 1, 0);
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

    void build_rec(int left, int right, int depth) {
        if (left > right) return;

        int axis = depth % 2;
        if (axis == 0) sort(points.begin() + left, points.begin() + right + 1, [](const auto& p1, const auto& p2) { return p1.x < p2.x; });
        else sort(points.begin() + left, points.begin() + right + 1, [](const auto& p1, const auto& p2) { return p1.y < p2.y; });
        int mid = (left + right) / 2;
        build_rec(left, mid - 1, depth + 1);
        build_rec(mid + 1, right, depth + 1);
    }

    void search_rec(Point& start, Point& end, vector<int>& res, int left, int right, int depth) {
        if (left > right) return;

        int axis = depth % 2;
        int mid = (left + right) / 2;
        bool contained = true;
        for (int i = 0; i < 2; i++) contained &= check_position(points[mid], start, end, i) == 0;
        if (contained) res.push_back(points[mid].id);
        if (left == right) return;
        int pos = check_position(points[mid], start, end, axis);
        if (pos != -1) search_rec(start, end, res, left, mid - 1, depth + 1);
        if (pos != 1) search_rec(start, end, res, mid + 1, right, depth + 1);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

