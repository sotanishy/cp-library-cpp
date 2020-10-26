# Rolling Hash

文字列または数列のハッシュ値を計算する．Rabin-Karp 法に用いる．

この実装では $\mod 2^{61} - 1$ を用いている．

## Constructor

- `RollingHash(string s, long long base)`
- `RollingHash(vector<T> s, long long base)`
    - `s` のハッシュ値を計算する．
    - 時間計算量: $O(n)$

## Member functions

- `static long long generate_base()`
    - ランダムな基数を返す．
    - 時間計算量: $O(1)$
- `long long query(int l, int r)`
    - 区間 $[l, r)$ のハッシュ値を返す．
    - 時間計算量: $O(1)$
- `long long combine(long long h1, long long h2, int len2)`
    - ハッシュ値 $h1$ と $h2$ を結合する．$h2$ の長さを $len2$ である．
    - 時間計算量: $O(1)$

## Reference

- [安全で爆速なRollingHashの話](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6)