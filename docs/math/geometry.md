---
title: Geometry
documentation_of: ../../math/geometry.cpp
---

## Description

幾何アルゴリズム詰め合わせ

`Vec` は `std::complex<double>` のエイリアスである．

## Operations

時間計算量は明示しない限り $O(1)$．

- `double dot(Vec a, Vec b)`
    - 内積を計算する

- `double cross(Vec a, Vec b)`
    - 外積の $z$ 座標を計算する

- `Vec rot(Vec a, double ang)`
    - $a$ を $ang$ だけ回転させる
    - ***NOT VERIFIED***

- `bool are_colinear(Vec p1, Vec p2, Vec p3)`
    - 3点が共線か判定する
    - ***NOT VERIFIED***

- `bool ccw(Vec a, Vec b, Vec c)`
    - $a \rightarrow b \rightarrow c$ が反時計回りか判定する

- `bool intersect(Vec a, Vec b, Vec c, Vec d)`
    - 線分 $ab$ と線分 $cd$ が交差するか判定する

- `bool on_segment(Vec p1, Vec p2, Vec q)`
    - 点 $q$ が線分 $p_1 p_2$ 上にあるか判定する

 - `double point_line_dist(Vec p1, Vec p2, Vec q)`
    - 点 $q$ と直線 $p_1 p_2$ の距離を返す

- `Vec intersection(Vec p1, Vec p2, Vec q1, Vec q2)`
    - 直線 $p_1 p_2$ と直線 $q_1 q_2$ の交点を返す

- `vector<Vec> intersection_circles(Vec c1, double r1, Vec c2, double r2)`
    - 中心 $c_1$，半径 $r_1$ の円と中心 $c_2$，半径 $r_2$ の円の交点を返す

- `vector<Vec> intersection_circle_line(Vec c, double r, Vec p1, double p2)`
    - 中心 $c$，半径 $r$ の円と直線 $p_1 p_2$ の交点を返す

- `double area(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の面積を返す
    - ***NOT VERIFIED***

- `Vec centroid(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の重心を返す
    - ***NOT VERIFIED***

- `Vec circumcenter(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の外心を返す
    - ***NOT VERIFIED***

- `Vec incenter(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の内心を返す
    - ***NOT VERIFIED***

- `vector<Vec> convex_hull(vector<Vec> points)`
    - 与えられた点の凸包を返す
    - 時間計算量: $O(n)$