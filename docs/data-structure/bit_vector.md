## Description

完備辞書 (fully indexable dictionary)，または rank/select 辞書は，ビット列を扱うデータ構造である．`rank` 操作 ($k$ 番目までの1の個数) と `select` 操作 ($k$ 番目の1の位置) を提供する．

本来完備辞書は簡潔データ構造であるが，この実装ではコンパクト表現を採用している．競技プログラミングにおいてはコンパクト表現で十分であることと，コンパクト表現の方が実装が簡単であり，実測では高速であったことが理由である．コンパクト表現なら単純な累積和でも同じことを実現できるが，こちらの実装の方が省メモリである．


## Operations

- `BitVector(vector<bool> v)`
    - ビット列 `v` の完備辞書を構築する
    - 時間計算量: $O(n)$
- `bool access(int k)`
    - $k$ 番目の要素を取得する
    - 時間計算量: $O(1)$
- `int rank(int k)`
    - 区間 $[0, k)$ 中の1の数を返す
    - 時間計算量: $O(1)$
- `int select(int k)`
    - `rank(i) = k` となる最初の $i$ を返す
    - 時間計算量: $O(\log n)$

## Reference

- [完備辞書](https://miti-7.hatenablog.com/entry/2018/04/15/155638)
- [完備辞書（簡潔ビットベクトル）の解説](https://takeda25.hatenablog.jp/entry/20140201/1391250137)