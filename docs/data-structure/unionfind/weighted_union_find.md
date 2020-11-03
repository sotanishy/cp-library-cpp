## Description

重み付き union find は，union find の操作に加えて，同じ集合に属する他の要素に対する要素の相対的な重みを管理する．

空間計算量: $O(n)$

## Operations

- `WeightedUnionFind(int n)`
    - サイズ`n`の重み付き union find を構築する．
    - 時間計算量: $O(n)$
- `int find(int x)`
    - $x$ が属する木の根を返す
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `T weight(int x)`
    - 木の根に対する $x$ の重みを返す
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `void unite(int x, int y, T w)`
    - $x$ が属する集合と $y$ が属する集合を $weight(y) - weight(x) = w$ となるように連結する
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `bool same(int x, int y)`
    - $x$ と $y$ が同じ集合に属するかを判定する
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `T diff(int x, int y)`
    - $x$ に対する $y$ の重み，すなわち $weight(y) - weight(x)$ を返す
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `int size(int x)`
    - $x$ が属する集合の大きさを返す
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$

## TODO

- 抽象化