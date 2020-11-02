# Wavelet Matrix

ウェーブレット行列は，静的な整数列に対する様々なクエリが処理できるデータ構造である．整数列を上位ビットからソートして完備辞書を構築する．

空間計算量: $O(n \lg m)$, $m$ は数列の最大値

## Operations

- `WaveletMatrix(vector<int> v)`
    - `v` からウェーブレット行列を構築する
    - 時間計算量: $O(n \lg m)$
- `int access(int k)`
    - $k$ 番目の要素を取得する
    - 時間計算量: $O(\lg m)$
- `int rank(int k, int x)`
    - $[0, k)$ での $x$ の個数を返す
    - 時間計算量: $O(\lg m)$
- `int rank_less(int k, int x)`
    - $[0, k)$ で $x$ より小さい要素の個数を返す
    - 時間計算量: $O(\lg m)$
- `int select(int k, int x)`
    - $k$ 番目の $x$ の位置を返す
    - 時間計算量: $O(\lg n \lg m)$
- `int quantile(int l, int r, int k)`
    - $[l, r)$ で $k$ 番目に小さい値を返す
    - 時間計算量: $O(\lg m)$

## Reference

- [ウェーブレット行列(wavelet matrix)](https://miti-7.hatenablog.com/entry/2018/04/28/152259)

## TODO

- 他の処理も実装
- [これ](https://www.slideshare.net/pfi/ss-15916040) 読む
- Wavelet tree 実装
- 動的 [https://miti-7.hatenablog.com/entry/2019/02/01/143655]()