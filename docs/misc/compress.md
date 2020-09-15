# Coordinate Compression

座標圧縮．与えられた値の大小関係が保たれるように，値を連続した非負整数に変換する．

空間計算量: $O(n)$

## Template parameters

- `T`
    - 要素の型

## Constructor

- `Compress(const vector<T>& vs)`
    - `vs`の値を座標圧縮する
    - 時間計算量: $O(n \lg n)$

## Member functions

- `int compress(const T& x)`
    - $x$ を圧縮した値を返す
    - 時間計算量: $O(\lg n)$
- `T decompress(int i)`
    - $i$ の圧縮前の値を返す
    - 時間計算量: $O(1)$