---
title: Hafnian
documentation_of: ../../../math/matrix/hafnian.hpp
---

## Description

偶数次対称行列のハフニアンを求める． $2n \times 2n$ 対称行列 $A$ のハフニアンは次式で定義される．
$$
\operatorname{haf}(A) = \sum_{\rho \in P_{2n}^2} \prod_{\{i,j\} \in \rho} A_{i,j}
$$
ここで， $P_{2n}^n$ は $\{1,2,\dots,2n\}$ の大きさ $2$ の部分集合への分割の全体である．

これは， $A$ を隣接行列として持つ無向グラフの完全マッチングの個数である．

## Operations

- `T hafnian(vector<vector<T>> mat)`
    - 与えられた偶数次対称行列のハフニアンを求める
    - 時間計算量: $O(n^2 2^{n/2})$

## Reference

- [Hafnian of Matrix - @tko919, HackMD](https://hackmd.io/@tko919/HyTPhjWco)
- [集合べき級数関連 (4) 問題例 - maspyのHP](https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-4-%e5%95%8f%e9%a1%8c%e4%be%8b)