# Splay Tree

Splay tree は，平衡二分探索木の一種である．ノードを根に持ってくるスプレーという操作を利用して様々な操作を実現している．同じ要素への連続アクセスが高速であるという特徴がある．

空間計算量: $O(n)$

## Template parameters

- `M`
    - モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的な二項演算 $\cdot: T \times T \rightarrow T$

## Member functions

- `static SplayTree join(SplayTree l, SplayTree r)`
    - `l` と `r` を融合させた splay tree を返す
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `pair<SplayTree, SplayTree> split(int k)`
    - splay tree を $[0, k)$ と $[k, n)$ に分割する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void update(int k, T x)`
    - $k$ 番目の要素の値を $x$ に変更する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void reverse(int l, int r)`
    - 区間 $[l, r)$ を反転する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void insert(int k, T x)`
    - $k$ 番目に $x$ を挿入する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void erase(int k)`
    - $k$ 番目の要素を削除する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void push_front(T x)`
- `void push_back(T x)`
- `void pop_front()`
- `void pop_back()`
    - 先頭/末尾に $x$ を追加する/の要素を削除する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `int size()`
    - 要素数を返す
    - 時間計算量: $O(1)$
- `bool empty()`
    - treap が空か判定する
    - 時間計算量: $O(1)$