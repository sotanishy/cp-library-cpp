# Combination

組み合わせ $n \choose r$ および順列 $_n P _r$ を $\mod mod$ で計算する．これらの値を何度も計算する必要があるときは non-static メンバーを，1度でいいときは static メンバーを使用する．また，$n$ の値が配列に入らないほど大きいが $r$ の値は十分小さいときも static メンバーを使用する．

空間計算量: $O(n)$

## Constructor

- `Combination(int n, long long mod)`
    - $n$ 以下の整数の階乗及びその逆元を前計算する
    - 時間計算量: $O(n)$

## Member functions

- `static long long C(int n, int r, long long mod)`
    - $n \choose r$ を計算する．
    - 時間計算量: $O(r)$

- `long long P(int n, int r)`
    - $_n P _r$ を計算する．$r < 0$ または $n < r$ のときは0を返す
    - 時間計算量: $O(1)$

- `long long C(int n, int r)`
    - $n \choose r$ を計算する．$r < 0$ または $n < r$ のときは0を返す
    - 時間計算量: $O(1)$