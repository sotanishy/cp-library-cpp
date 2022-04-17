---
title: Offline Deletable Convex Hull Trick
documentation_of: ../../../data-structure/cht/offline_deletable_convex_hull_trick.cpp
---

## Description

直線の多重集合に対する以下のクエリをオフラインで処理する:
- 直線の追加
- 直線の削除
- $x$ における最小値の取得

Undo 可能 Li Chao tree を用いて，offline dynamic connectivity の要領でこれを実現する．

空間計算量: $O(q\log q)$

## Operations

- `void add(T a, T b)`
    - 直線 $ax + b$ を追加する
    - 時間計算量: $O(\log q)$
- `void erase(T a, T b)`
    - 直線 $ax + b$ を削除する
    - 時間計算量: $O(\log q)$
- `void get(T x)`
    - $x$ における最小値を取得する
    - 時間計算量: $O(\log q)$
- `vector<T> run()`
    - クエリを実行し，`get`の結果を返す
    - 時間計算量: $O(q\log^2 q)$

## Reference

- [オフライン 削除可能 Convex Hull Trick - procon](https://mugen1337.github.io/procon/DataStructure/DeletableLiChaoTreeOffline.cpp)
- verify: [https://codeforces.com/contest/678/submission/131471122](https://codeforces.com/contest/678/submission/131471122)