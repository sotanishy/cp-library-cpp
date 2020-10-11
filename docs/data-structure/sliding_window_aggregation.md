# Sliding Window Aggregation

Sliding window aggregation は，半群 $(T, \cdot)$ を扱い，要素全体の演算が可能なキューである．スタックを2つ用いてキューをシミュレートする．

## Template parameters

- `M`
    - 半群 $(T, \cdot)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T op(T, T)`: 結合的な二項演算 $\cdot: T \times T \rightarrow T$

## Member functions

- `void push(T x)`
    - $x$ をキューの末尾に追加する
    - 時間計算量: $O(1)$
- `void pop()`
    - キューの先頭要素を削除する
    - 時間計算量: $\mathrm{amortized}\ O(1)$
- `T fold()`
    - キューの要素全体の演算結果を返す
    - 時間計算量: $O(1)$