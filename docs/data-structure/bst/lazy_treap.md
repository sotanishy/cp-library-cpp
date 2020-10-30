# Treap with Lazy Propagation

遅延伝搬 treap は，区間更新が可能な treap である．扱える代数的構造は遅延伝搬セグメント木と同様なので，そちらを参照．

基本的には非可換のモノイドも扱えるが，`reverse` 操作をする場合は可換性が必要がある．非可換も実装を少しいじれば扱えるがめんどくさいので実装していない．

空間計算量: $O(n)$

## Template parameters

- `M`
    - モノイド $(T, \cdot, e_M)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e_M$
        - `T op(T, T)`: 結合的な二項演算 $\cdot: T \times T \rightarrow T$
- `O`
    - 作用素モノイド $(E, \circ, e_O)$. 以下のメンバーが定義されている:
        - `T`: 集合 $E$ の型
        - `T id`: 単位元 $e_O$
        - `T op(T, T)`: 結合的な二項演算 $\circ: E \times E \rightarrow E$
- `T act(T, E)`
    - 作用 $*: T \times E \rightarrow T$.

## Member functions

- `static Treap join(Treap l, Treap r)`
    - `l` と `r` を融合させた treap を返す
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `pair<Treap, Treap> split(int k)`
    - Treap を $[0, k)$ と $[k, n)$ に分割する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void update(int l, int r, E x)`
    - 区間 $[l, r)$ の値に $x$ を作用させる．
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