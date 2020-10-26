# Undoable Union Find

Undo 可能 union find は，操作の undo が可能な union find である．

変更前の値を保存しておき，経路圧縮をしないことによって操作前の状態の復元が可能となる．

また，連結成分の頂点の値の fold も可能である．

空間計算量: $O(n + m)$, $m$ は操作回数

## Template parameters

- `M`
    - 可換モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的かつ可換な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `UndoableUnionFind(int n)`
    - サイズ`n`で頂点の値がすべて単位元 $e$ の undo 可能 union find を構築する
    - 時間計算量: $O(n)$
- `UndoableUnionFind(vector<T> v)`
    - `v`の要素からサイズ`n = v.size()`の undo 可能 union find を構築する
    - 時間計算量: $O(n)$

## Member functions

- `int find(int x)`
    - $x$ が属する木の根を返す
    - 時間計算量: $O(\log n)$
- `void unite(int x, int y)`
    - $x$ が属する集合と $y$ が属する集合を連結する
    - 時間計算量: $O(\log n)$
- `void undo()`
    - 操作を undo する．
    - 時間計算量: $O(1)$
- `bool same(int x, int y)`
    - $x$ と $y$ が同じ集合に属するかを判定する
    - 時間計算量: $O(\log n)$
- `int size(int x)`
    - $x$ が属する集合の大きさを返す
    - 時間計算量: $O(\log n)$
- `T component_fold(int x)`
    - $x$ が属する連結成分の頂点の値を fold する
    - 時間計算量: $O(1)$
- `void update(int x, T v)`
    - $a_x$ を $a_x \cdot v$ に更新する
    - 時間計算量: $O(1)$