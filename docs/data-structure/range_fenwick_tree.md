# Fenwick Tree with Range Update

接頭辞和を扱う Fenwick tree を2つ使うことで，区間加算を実現できる．

空間計算量: $O(n)$

## Template parameters

- `RangeFenwickTree(int n)`
    - サイズ`n`で要素がすべて $0$ の区間更新 Fenwick tree を構築する
    - 時間計算量: $O(n)$

## Member functions

- `T sum(int i)`
    - $a_0 + a_1 + \dots + a_{i-1}$ を計算する
    - 時間計算量: $O(\lg n)$
- `void add(int l, int r, T x)`
    - $i \in [l, r)$ について $a_i$ を $a_i \cdot x$ に更新する
    - 時間計算量: $O(\lg n)$