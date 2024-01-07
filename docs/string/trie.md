---
title: Trie
documentation_of: ../../string/trie.hpp
---

## Description

トライ木は，文字列の集合を管理するデータ構造である．

トライ木は実現したい処理に応じて，関数や持たせるデータを自分で書くことが多いので，これはあくまでテンプレ．

## Operations

- `void insert(string s, int id)`
    - 文字列 $s$ を挿入する
    - 時間計算量: $O(\vert s\vert)$
- `void compress()`
    - トライ木を圧縮して Patricia trie を構築する．これにより，木の木の深さが $O(\sqrt{\sum \vert s \vert})$ になる．
    - 時間計算量: $O(\sum \vert s\vert)$