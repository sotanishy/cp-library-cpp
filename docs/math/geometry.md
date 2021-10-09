---
title: Geometry
documentation_of: ../../math/geometry.cpp
---

## Description

幾何アルゴリズム詰め合わせ

`Vec` は `std::complex<T>` のエイリアスである．

できるだけ整数だけの計算も扱えるようにした

## Operations

時間計算量は明示しない限り $O(1)$．

- `T dot(Vec a, Vec b)`
    - 内積を計算する

- `T cross(Vec a, Vec b)`
    - 外積の $z$ 座標を計算する

- `Vec rot(Vec a, T ang)`
    - $a$ を角 $ang$ だけ回転させる
    - ***NOT VERIFIED***

- `Vec projection(Vec a, Vec b, Vec c)`
    - 点 $c$ の直線 $ab$ 上の射影を求める

- `Vec reflection(Vec a, Vec b, Vec c)`
    - 点 $c$ の直線 $ab$ に関して対称な点を求める

- `bool ccw(Vec a, Vec b, Vec c)`
    - $a,b,c$ が同一直線上にあるなら0, $a \rightarrow b \rightarrow c$ が反時計回りなら1，そうでなければ-1を返す

- `bool on_segment(Vec a, Vec b, Vec c)`
    - 点 $c$ が線分 $ab$ 上にあるか判定する

- `bool intersect_segments(Vec a, Vec b, Vec c, Vec d)`
    - 線分 $ab$ と線分 $cd$ が交差するか判定する

 - `T dist_line_point(Vec a, Vec b, Vec c)`
    - 直線 $ab$ と点 $c$ の距離を求める

 - `T dist_segment_point(Vec a, Vec b, Vec c)`
    - 線分 $ab$ と点 $c$ の距離を求める

 - `T dist_segments(Vec a, Vec b, Vec c, Vec d)`
    - 線分 $ab$ と線分 $cd$ の距離を求める

- `Vec intersection_lines(Vec a, Vec b, Vec c, Vec d)`
    - 直線 $ab$ と直線 $cd$ の交点を求める

- `vector<Vec> intersection_circle_line(Vec c, T r, Vec a, Vec b)`
    - 中心 $c$，半径 $r$ の円と直線 $ab$ の交点を求める

- `vector<Vec> intersection_circles(Vec c1, T r1, Vec c2, T r2)`
    - 中心 $c_1$，半径 $r_1$ の円と中心 $c_2$，半径 $r_2$ の円の交点を求める

- `T area(vector<Vec> pts)`
    - 多角形 $pts$ の面積を求める
    - 時間計算量: $O(n)$

- `T area(vector<Vec> pts)`
    - 多角形 $pts$ が凸か判定する．`pts` は反時計回りに与えられる必要がある
    - 時間計算量: $O(n)$

- `int contains(vector<Vec> pts, Vec q)`
    - 多角形 $pts$ が点 $q$ を含むか判定する．内部に含むなら2，境界に含むから1，外部に含むなら0を返す
    - 時間計算量: $O(n)$

- `Vec centroid(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の重心を返す
    - ***NOT VERIFIED***

- `Vec incenter(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の内心を返す

- `Vec circumcenter(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の外心を返す

- `vector<Vec> convex_hull(vector<Vec> pts)`
    - 与えられた点の凸包を返す
    - 時間計算量: $O(n\log n)$

- `T closest_pair(vector<Vec> pts)`
    - 与えられた点のうち最も近い2点の距離を分割統治法で求める
    - 時間計算量: $O(n\log n)$


## TODO

- 多角形の直径
- convex cut
- 円の接線
- 共通接線
- 円と多角形の共通部分の面積
- 2円の共通部分の面積