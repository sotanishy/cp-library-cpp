## Description

永続配列は，過去のバージョンを保持する配列である．永続配列の要素を変更したとき，変更された値を保持する新しい配列を生成する．

空間計算量: $O(m b \log_b n)$, $m$ は変更の数

## Operations

- `PersistentArray(vector<T> v)`
    - `v` の要素から永続配列を構築する
    - 時間計算量: $O(nb \log_b n)$
- `T get(int k)`
    - $k$ 番目の要素を返す
    - 時間計算量: $O(\log_b n)$
- `PersistentArray set(int k, T x)`
    - $k$ 番目の要素を $x$ に変更した永続配列を返す
    - 時間計算量: $O(b \log_b n)$

## Reference

- [ゼロから作る永続データ構造](https://qiita.com/wotsushi/items/72e7f8cdd674741ffd61)