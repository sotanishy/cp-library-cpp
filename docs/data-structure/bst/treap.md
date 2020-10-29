# Treap

Treap は，平衡二分探索木の一種である．キーと別に，ランダムに割り当てられた優先度を用いてヒープ性を持たせることで，木の平衡を保つ．

空間計算量: $O(n)$

## Template parameters

- `M`
    - モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的な二項演算 $\cdot: T \times T \rightarrow T$

## Member functions

- `static Treap join(Treap l, Treap r)`
    - `l` と `r` を融合させた treap を返す
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `pair<Treap, Treap> split(int k)`
    - Treap を $[0, k)$ と $[k, n)$ に分割する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void set(int k, T x)`
    - $k$ 番目の要素の値を $x$ に変更する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void reverse(int l, int r)`
    - 区間 $[l, r)$ を反転する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void insert(int k, T x)`
    - $k$ 番目に $x$ を挿入する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void erase(int k)`
    - $k$ 番目の要素を削除する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void push_front(T x)`
- `void push_back(T x)`
- `void pop_front()`
- `void pop_back()`
    - 先頭/末尾に $x$ を追加する/の要素を削除する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `int size()`
    - 要素数を返す
    - 時間計算量: $O(1)$
- `bool empty()`
    - treap が空か判定する
    - 時間計算量: $O(1)$