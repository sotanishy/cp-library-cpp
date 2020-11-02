## Description

二分トライ木 (binary trie) は，非負整数の多重集合を扱うデータ構造である．整数をビット列とみなしてトライ木に格納する．平衡二分木による多重集合の実装よりも実装が簡単であるほか，要素全体をある値で xor した時の最大/最小値を求めるなどの操作が可能である．

空間計算量: $O(nb)$

## Operations

- `int size()`
    - 集合の大きさを返す
    - 時間計算量: $O(1)$
- `bool empty()`
    - 集合が空か判定する
    - 時間計算量: $O(1)$
- `int count(T x)`
    - 集合内の $x$ の数を返す
    - 時間計算量: $O(b)$
- `void insert(T x)`
    - $x$ を集合に追加する．
    - 時間計算量: $O(b)$
- `void erase(T x)`
    - $x$ が存在すればそれを1つ集合から取り除く
    - 時間計算量: $O(b)$
- `T min_element(T x)`
    - 集合全体を $\oplus x$ した時の最小値を返す
    - 時間計算量: $O(b)$
- `T max_element(T x)`
    - 集合全体を $\oplus x$ した時の最大値を返す
    - 時間計算量: $O(b)$

## Reference

- [非負整数値を扱う Trie について](https://kazuma8128.hatenablog.com/entry/2018/05/06/022654)
- [binaryTrie: A digital search tree](http://opendatastructures.org/ods-java/13_1_binaryTrie_digital_sea.html)

## TODO

- ポインタを使った実装
- `lower_bound`, `upper_bound`, `kth_element` の実装
- jump ポインタによる高速化
- 遅延評価
- 永続化