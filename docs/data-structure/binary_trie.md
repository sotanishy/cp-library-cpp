# Binary Trie

Binary trie は，正整数の多重集合を扱うデータ構造である．

空間計算量: $O(n)$

## Template parameter

- `T`
    - 要素の型
- `B`
    - 要素の bit 数．デフォルトは32

## Member functions

- `int size()`
    - 集合の大きさを返す
    - 時間計算量: $O(1)$
- `bool empty()`
    - 集合が空か判定する
    - 時間計算量: $O(1)$
- `int count(T x)`
    - 集合内の $x$ の数を返す
    - 時間計算量: $O(B)$
- `void insert(T x)`
    - $x$ を集合に追加する．
    - 時間計算量: $O(B)$
- `void erase(T x)`
    - $x$ が存在すればそれを1つ集合から取り除く
    - 時間計算量: $O(B)$
- `T min_element(T x)`
    - 集合全体を $\oplus x$ した時の最小値を返す
    - 時間計算量: $O(B)$
- `T max_element(T x)`
    - 集合全体を $\oplus x$ した時の最大値を返す
    - 時間計算量: $O(B)$
