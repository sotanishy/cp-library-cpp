---
title: Persistent Stack
documentation_of: ../../data-structure/persistent_stack.cpp
---

## Description

永続スタックは，過去のバージョンを保持するスタックである．

空間計算量: $O(m)$, $m$ は変更の数

## Operations

- `bool empty()`
    - 時間計算量: $O(1)$
- `T top()`
    - 先頭の要素を返す
    - 時間計算量: $O(1)$
- `PersistentStack push(T val)`
    - `val` を先頭に追加する
    - 時間計算量: $O(1)$
- `PersistentStack pop()`
    - 先頭の要素を削除する
    - 時間計算量: $O(1)$

## Reference

- [ゼロから作る永続データ構造](https://qiita.com/wotsushi/items/72e7f8cdd674741ffd61)