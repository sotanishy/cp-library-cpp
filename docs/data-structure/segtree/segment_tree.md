## Description

セグメント木は，モノイド $(T, \cdot, e)$ の列に対する一点更新と区間取得を提供するデータ構造である．

空間計算量: $O(n)$

## Operations

- `SegmentTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e$ のセグメント木を構築する
    - 時間計算量: $O(n)$
- `SegmentTree(vector<T> v)`
    - `v`の要素からサイズ`n = v.size()`のセグメント木を構築する
    - 時間計算量: $O(n)$
- `T operator[](int k)`
    - $k$ 番目の要素を返す
    - 時間計算量: $O(1)$
- `void update(int k, T x)`
    - $k$ 番目の要素を $x$ に更新する
    - 時間計算量: $O(\lg n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $O(\lg n)$
- `int find_first(int l, F cond)`
    - `fold(l, r)` が条件 `cond` を満たすような最小の $r (> l)$ 返す．列の単調性を仮定する．そのような $r$ が存在しない場合は `-1` を返す
    - 時間計算量: $O(\lg n)$
- `int find_last(int r, F cond)`
    - `fold(l, r)` が条件 `cond` を満たすような最大の $l (< r)$ 返す．列の単調性を仮定する．そのような $l$ が存在しない場合は `-1` を返す
    - 時間計算量: $O(\lg n)$

## Reference

- [セグメント木について](https://beet-aizu.hatenablog.com/entry/2017/09/10/132258)
- [セグメント木をソラで書きたいあなたに](https://tsutaj.hatenablog.com/entry/2017/03/29/204841)
- [競技プログラマのための抽象セグメント木実装のすすめ](https://beet-aizu.hatenablog.com/entry/2019/11/27/124437)
- [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html)