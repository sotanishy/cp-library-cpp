# Sliding Window Minimum

スライド最小値は，全順序集合 $T$ を扱い，要素の最小値を求めることができるキューである．

## Template parameters

- `T`
    - 要素の型．二項関係 `<` が定義されている必要がある

- `Compare`
    - 要素の比較に用いる型．デフォルトは `std::less<>`

## Member functions

- `void push(T x)`
    - $x$ をキューの末尾に追加する
    - 時間計算量: $\mathrm{amortized}\ O(1)$
- `void pop()`
    - キューの先頭要素を削除する
    - 時間計算量: $O(1)$
- `T get()`
    - キューの要素全体の最小値/最大値を返す
    - 時間計算量: $O(1)$