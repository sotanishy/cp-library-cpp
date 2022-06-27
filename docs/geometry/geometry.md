---
title: Geometry
documentation_of: ../../geometry/geometry.hpp
---

## Description

幾何アルゴリズム詰め合わせ

`Vec` は `std::complex<T>` のエイリアスである．

できるだけ整数だけの計算も扱えるようにした

## Operations

時間計算量は明示しない限り $O(1)$．

### `geometry.hpp`

- `T dot(Vec a, Vec b)`
    - 内積を計算する

- `T cross(Vec a, Vec b)`
    - 外積の $z$ 座標を計算する

- `Vec rot(Vec a, T ang)`
    - $a$ を角 $ang$ だけ回転させる

- `Vec perp(Vec a)`
    - $a$ を角 $\pi/2$ だけ回転させる

- `Vec projection(Line l, Vec p)`
    - 点 $p$ の直線 $l$ 上の射影を求める

- `Vec reflection(Line l, Vec p)`
    - 点 $p$ の直線 $l$ に関して対称な点を求める

- `int ccw(Vec a, Vec b, Vec c)`
    - $a,b,c$ が同一直線上にあるなら0, $a \rightarrow b \rightarrow c$ が反時計回りなら1，そうでなければ-1を返す

- `void sort_by_arg(vector<Vec> pts)`
  - 与えられた点を偏角ソートする (ソート順は[この問題](https://judge.yosupo.jp/problem/sort_points_by_argument)に準拠)
  - 時間計算量: $O(n\log n)$

### `intersect.hpp`

- `bool intersect(Segment s, Vec p)`

  `int intersect(Polygon poly, Vec p)`

  `bool intersect(Segment s, Segment t)`

  `bool intersect(Polygon poly1, Polygon poly2)`

  `int intersect(Circle c1, Circle c2)`
    - 引数で与えられた2つの対象が交差するか判定する．詳細な仕様はコードのコメントを参照

### `dist.hpp`

 - `T dist(Line l, Vec p)`

   `T dist(Segment s, Vec p)`

   `T dist(Segment s, Segment t)`
    - 引数で与えられた2つの対象の距離を計算する

### `intersection.hpp`

- `Vec intersection(Line l, Line m)`

- `vector<Vec> intersection(Circle c, Line l)`

  `vector<Vec> intersection(Circle c1, Circle c2)`
    - 引数で与えられた2つの対象の交点を返す

- `T area_intersection(Circle c1, Circle c2)`
    - 円 $c_1,c_2$ の共通部分の面積を求める

### `bisector.hpp`

- `Line bisector(Segment s)`
    - 線分 $s$ の垂直二等分線を返す

- `pair<Line, Line> bisector(Line l, Line m)`
    - 直線 $l,m$ の角二等分線を返す．$l,m$ が平行なら，両者の中間の線を返す (つまり，$l,m$ から等距離にある点の集合を返す)

### `triangle.hpp`

- `Vec centroid(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の重心を返す
    - ***NOT VERIFIED***

- `Vec incenter(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の内心を返す

- `Vec circumcenter(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の外心を返す

### `tangent.hpp`

- `pair<Vec, Vec> tangent_ponints(Circle c, Vec p)`
    - 点 $p$ を通り円 $c$ に接する接線と $c$ の接点を返す

- `vector<Line> common_tangents(Circle c1, Circle c2)`
    - 円 $c_1,c_2$ の共通接線を返す

### `polygon.hpp`

- `T area(Polygon poly)`
    - 多角形 $poly$ の面積を求める
    - 時間計算量: $O(n)$

- `T is_convex(Polygon poly)`
    - 多角形 $poly$ が凸か判定する．`poly` は反時計回りに与えられる必要がある
    - 時間計算量: $O(n)$

- `vector<Vec> convex_cut(Polygon poly, Line l)`
    - 多角形 $poly$ を直線 $l$ で切断する．詳細な仕様は [凸多角形の切断](https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C) を参照．
    - 時間計算量: $O(n)$

### `closest_pair.hpp`

- `T closest_pair(vector<Vec> pts)`
    - 与えられた点のうち最も近い2点の距離を分割統治法で求める
    - 時間計算量: $O(n\log n)$
