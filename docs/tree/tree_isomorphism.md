---
title: Tree Isomorphism
documentation_of: ../../tree/tree_hash.hpp
---

## Description

同型な木に同一のラベルを付与するアルゴリズム．

## Operations

- `TreeHasher`
    - 確率的だが高速．ハッシュを用いている．
    - `long long hash_all(vector<vector<int>> G, int root)`
        - 木 $G$ の隣接リストが与えられたとき，$G$ のハッシュを計算する．`root` が与えられた場合はそれを根とする．そうでない場合は，直径の中心を根とする．直径の中心が複数ある場合は，ハッシュ値が小さくなる方を返す
        - 時間計算量: $O(n)$
    - `vector<long long> hash_subtrees(vector<vector<int>> G, int root)`
        - 木 $G$ の隣接リストが与えられたとき，$G$ の各部分木のハッシュを計算する．
        - 時間計算量: $O(n)$
- `TreeEncoder`
    - 決定的だが低速．AHU algorithm を用いている．
    - `vector<int> encode(vector<vector<int>> G, int root)`
        - 木 $G$ の隣接リストが与えられたとき，$G$ の各部分木のラベルを計算する．
        - 時間計算量: $O(n\log n)$


## Reference

- [Tree Isomorphism - My Algorithm](https://kopricky.github.io/code/Graph/tree_isomorphism.html)
- [根付き木のハッシュ - あなたは嘘つきですかと聞かれたら「YES」と答えるブログ](https://snuke.hatenablog.com/entry/2017/02/03/054210)
- [Tree isomorphism](https://logic.pdmi.ras.ru/~smal/files/smal_jass08_slides.pdf)