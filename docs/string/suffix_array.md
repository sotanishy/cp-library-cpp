# Suffix Array

接尾辞配列は，文字列のインデックスを接尾辞の辞書順に並べたものである．文字列検索が効率的に行える．

この実装では Manber-Myers のアルゴリズムを用いている．ソートに基数ソートを用いることで時間計算量を $O(n\lg^2 n)$ から $O(n\lg n)$ に改善している．

線形時間で構築を行う SA-IS というより高速なアルゴリズムもある．

## Constructor

- `SuffixArray(string str)`
    - `str` から接尾辞配列を構築する
    - 時間計算量: $O(n\lg n)$

## Member functions

- `int operator[](int k)`
    - 接尾辞配列の $k$ 番目の要素を返す
    - 時間計算量: $O(1)$
- `int lower_bound(string t)`
    - $k$ 番目の接尾辞が `t` より辞書順で等しいか大きくなるような最小の $k$ を返す
    - 時間計算量: $O(m\lg n)$
- `int upper_bound(string t)`
    - $k$ 番目の接尾辞が `t` より辞書順で大きくなるような最小の $k$ を返す
    - 時間計算量: $O(m\lg n)$