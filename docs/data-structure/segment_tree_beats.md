# Segment Tree Beats

Segment tree beats は，遅延伝搬セグメント木の亜種で，区間 chmin/chmax/add 更新と区間 min/max/sum クエリを処理できる．

sum クエリがないときは遅延伝搬セグメント木で十分である．

時間計算量は $O(\lg^2 n)$ ではなく $O(\lg n)$かもしれない．よくわからないのでここでは前者を使用する（表記として間違ってはいない）．

空間計算量: $O(n)$

## Template parameters

- `T`
    - 要素の型

## Constructor

- `SegmentTreeBeats(int n)`
    - サイズ`n`で要素がすべて 0 の segment tree beats を構築する
    - 時間計算量: $O(n)$
- `SegmentTreeBeats(vector<T> v)`
    - `v`の要素からサイズ`n = v.size()`の segment tree beats を構築する
    - 時間計算量: $O(n)$

## Member functions

- `T operator[](int k)`
    - $a_k$ を返す
    - 時間計算量: $O(\lg^2 n)$
- `void chmin(int l, int r, T x)`
    - $i \in [l, r)$ について $a_i$ を $min(a_i, x)$ に更新する
    - 時間計算量: $O(\lg^2 n)$
- `void chmax(int l, int r, T x)`
    - $i \in [l, r)$ について $a_i$ を $max(a_i, x)$ に更新する
    - 時間計算量: $O(\lg^2 n)$
- `void add(int l, int r, T x)`
    - $i \in [l, r)$ について $a_i$ を $a_i + x$ に更新する
    - 時間計算量: $O(\lg^2 n)$
- `T fold_min(int l, int r)`
    - $min(a_l, a_{l+1}, \cdots, a_{r-1})$ を計算する
    - 時間計算量: $O(\lg^2 n)$
- `T fold_max(int l, int r)`
    - $min(a_l, a_{l+1}, \cdots, a_{r-1})$ を計算する
    - 時間計算量: $O(\lg^2 n)$
- `T fold_sum(int l, int r)`
    - $min(a_l, a_{l+1}, \cdots, a_{r-1})$ を計算する
    - 時間計算量: $O(\lg^2 n)$

## Reference

[A simple introduction to "Segment tree beats"](https://codeforces.com/blog/entry/5731)