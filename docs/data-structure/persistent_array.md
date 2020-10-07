# Persistent Array

永続配列は，過去のバージョンを保持する配列である．永続配列の要素を変更したとき，変更された値を保持する新しい配列を生成する．これによって非破壊的な操作を提供する．

空間計算量: $O(n + m A \log_A n)$, $m$ は変更の数

## Template parameter

- `T`
    - 要素の型
- `A`
    - 子ノードの数．デフォルトは `2`

## Constructor

- `PersistentArray(vector<T> v)`
    - `v` の要素から永続配列を構築する
    - 時間計算量: $O(nA \log_A n)$

## Member functions

- `T get(int k)`
    - $k$ 番目の要素を返す
    - 時間計算量: $O(\log_A n)$
- `PersistentArray set(int k, T x)`
    - $k$ 番目の要素を $x$ に変更した永続配列を返す
    - 時間計算量: $O(A \log_A n)$
