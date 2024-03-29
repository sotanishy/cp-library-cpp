---
title: Rolling Hash
documentation_of: ../../string/rolling_hash.hpp
---

## Description

文字列または数列のハッシュ値を計算する．Rabin-Karp 法に用いる．

この実装では $\mod 2^{61} - 1$ を用いている．

この実装は内部で `__int128_t` を用いているが，Codeforces ではそれが使用できないので注意．Codeforces で rolling hash を使いたいときは，`mod` を 32 bit 以下の適当な整数 (素数?) に設定し，`long long` で乗算を行えばよい．

## Operations

- `RollingHash(string s, long long base)`
- `RollingHash(vector<T> s, long long base)`
    - `s` のハッシュ値を計算する
    - 時間計算量: $O(n)$
- `static long long generate_base()`
    - ランダムな基数を返す
    - 時間計算量: $O(1)$
- `long long query(int l, int r)`
    - 区間 $[l, r)$ のハッシュ値を返す
    - 時間計算量: $O(1)$
- `long long combine(long long h1, long long h2, int len2)`
    - ハッシュ値 $h1$ と $h2$ を結合する．$h2$ の長さを $len2$ である
    - 時間計算量: $O(1)$
- `void push_back(char c)`
    - 文字 $c$ を末尾に結合する
    - 時間計算量: $O(1)$

## Reference

- [安全で爆速なRollingHashの話](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6)