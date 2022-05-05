---
title: Stable Matching
documentation_of: ../../misc/stable_matching.hpp
---

## Description

(男性最適) 安定マッチングを返す．

$n$ 人の男性と $n$ 人の女性がいる状況を考える．各人は異性に対して選好順序を持っている．このとき，安定マッチングとは，$n$ 組の男女のマッチングであって，互いに現在組んでいる相手よりもお互いのことが好きであるような男女のペア (ブロッキングペア) が存在しないようなものである．

どの男性も安定マッチングでペアになれる女性のうち，もっとも好きな女性とペアになっているような安定マッチングを男性最適安定マッチングと言う．男性最適安定マッチングは Gale-Shapley アルゴリズムによって $O(n^2)$ 時間で求めることができる．

## Operations

- `vector<int> stable_matching(vector<vector<int>> man, vector<vector<int>> woman)`
    - 男性と女性の各人の選好順序が与えられたとき，(男性最適) 安定マッチングの1つにおいて，各女性と婚約している男性を返す．
    - 時間計算量: $O(n^2)$


## Reference

- [Stable marriage problem - Wikipedia](https://en.wikipedia.org/wiki/Stable_marriage_problem)
- [Gale-Shapley algorithm - Wikipedia](https://en.wikipedia.org/wiki/Gale%E2%80%93Shapley_algorithm)
