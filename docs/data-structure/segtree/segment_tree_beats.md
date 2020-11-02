## Description

Segment tree beats は，遅延伝搬セグメント木の亜種で，区間 chmin/chmax/add 更新と区間 min/max/sum 取得を提供する．sum クエリがないときは遅延伝搬セグメント木で十分である．

空間計算量: $O(n)$

## Operations

- `SegmentTreeBeats(int n)`
    - サイズ`n`で要素がすべて 0 の segment tree beats を構築する
    - 時間計算量: $O(n)$
- `SegmentTreeBeats(vector<T> v)`
    - `v`の要素からサイズ`n = v.size()`の segment tree beats を構築する
    - 時間計算量: $O(n)$
- `T operator[](int k)`
    - $k$ 番目の要素を返す
    - 時間計算量: $O(\lg^2 n)$
- `void chmin(int l, int r, T x)`
    - 区間 $[l, r)$ の値を $x$ で chmin する
    - 時間計算量: $O(\lg^2 n)$
- `void chmax(int l, int r, T x)`
    - 区間 $[l, r)$ の値を $x$ で chmax する
    - 時間計算量: $O(\lg^2 n)$
- `void add(int l, int r, T x)`
    - 区間 $[l, r)$ の値に $x$ を加算する
    - 時間計算量: $O(\lg^2 n)$
- `T fold_min(int l, int r)`
    - 区間 $[l, r)$ の値の最小値を返す
    - 時間計算量: $O(\lg^2 n)$
- `T fold_max(int l, int r)`
    - 区間 $[l, r)$ の値の最大値を返す
    - 時間計算量: $O(\lg^2 n)$
- `T fold_sum(int l, int r)`
    - 区間 $[l, r)$ の値の総和を返す
    - 時間計算量: $O(\lg^2 n)$

## Note

時間計算量は $O(\lg^2 n)$ ではなく $O(\lg n)$かもしれない．よくわからないので安全を取ってここでは前者を使用する．

## Reference

- [A simple introduction to "Segment tree beats"](https://codeforces.com/blog/entry/5731)
- [Segment Tree Beatsの実装メモ (基本まわり)](https://smijake3.hatenablog.com/entry/2019/04/28/021457)

## TODO

- Codeforces の記事をちゃんと読む
