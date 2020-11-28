## Description

素数に関する高速なアルゴリズム

## Primality Test

$n$ を Miller-Rabin 法で素数判定する．

- `bool is_prime(long long n)`
    - $n$ を素数判定する
    - 時間計算量: $O(\log^3 n)$

## Prime Factorization

$n$ を Pollard's Rho 法で素因数分解する．

- `vector<long long> prime_factor(long long n)`
    - $n$ の素因数のリストを返す．
    - 時間計算量: $\mathrm{expected}\ O(n^{\frac{1}{4}} \log n)$