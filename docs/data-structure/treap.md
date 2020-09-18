# Treap

Treap は，平衡二分探索木の一種である．キーと別に，ランダムに割り当てられた優先度を用いてヒープ性を持たせることで，木の平衡を保つ．

## Template parameters

- `T`
    - キーの型

## Member functions

- `int count(T key)`
    - $key$ をキーとするノードの個数 (0 か 1) を返す
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void insert(T key, int priority = -1)`
    - $key$ をキー，$priority$ を優先度とするノードを追加する．$priority$ は指定しない場合ランダムに決定される
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void erase(T key)`
    - $key$ をキーとするノードを削除する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$