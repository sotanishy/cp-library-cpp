# Fenwick Tree

Fenwick tree，または binary indexed tree は，可換モノイド $(T, \cdot, e)$ の列 $(a_0, a_1, \dots, a_{n-1})$ を管理し，一点更新と接頭辞へのクエリを処理できるデータ構造である．

セグメント木より制約が強く，操作が限られているが，実装が簡潔で定数倍速い．

空間計算量: $O(n)$

## Template parameters

- `M`
    - 可換モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的かつ可換な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `FenwickTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e$ の Fenwick tree を構築する
    - 時間計算量: $O(n)$

## Member functions

- `T prefix_fold(int i)`
    - $a_0 \cdot a_1 \cdot \cdots \cdot a_{i-1}$ を計算する
    - 時間計算量: $O(\lg n)$
- `void update(int i, T x)`
    - $a_i$ を $a_i \cdot x$ に更新する
    - 時間計算量: $O(\lg n)$
- `int find_first(const function<bool(T)>& cond)`
    - $a_0 \cdot a_1 \cdot \cdots \cdot a_{i-1}$ が条件 `cond` を満たすような最小の $i$ を返す．列の単調性を仮定する．そのような $i$ が存在しない場合は $n$ を返す．
    - 時間計算量: $O(\lg n)$