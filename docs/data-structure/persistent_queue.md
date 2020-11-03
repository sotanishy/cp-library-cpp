## Description

永続キューは，過去のバージョンを保持するキューである．この実装では内部で永続配列を用いている．

空間計算量: $O(m \log n)$, $m$ は変更の数

## Operations

- `int size()`
    - キューの要素数を返す
    - 時間計算量: $O(1)$
- `bool empty()`
    - 時間計算量: $O(1)$
- `T front()`
    - 先頭の要素を返す
    - 時間計算量: $O(1)$
- `T back()`
    - 末尾の要素を返す
    - 時間計算量: $O(1)$
- `PersistentQueue push(T val)`
    - `val` をキューの末尾に追加する
    - 時間計算量: $O(\log n)$
- `PersistentQueue pop()`
    - キューの先頭要素を削除する
    - 時間計算量: $O(1)$

## TODO

- ダブリングによる実装
- [これ](https://www.cs.cmu.edu/~rwh/theses/okasaki.pdf) 読む