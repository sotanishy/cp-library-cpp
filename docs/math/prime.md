# Prime Number Algorithms

素数に関するアルゴリズム詰め合わせ

## Primality Test

$n$ を試し割り法で素数判定する．

- `bool is_prime(long long n)`
    - $n$ を素数判定する
    - 時間計算量: $O(\sqrt{n})$

## Prime Table

エラトステネスの篩を用いて，$n$ 以下の整数の素数表を構築する．

_**NOT VERIFIED**_

- `vector<bool> prime_table(int n)`
    - $n$ 以下の整数の素数表を構築する
    - 時間計算量: $O(n\ln\ln n)$

## Prime Factorization

$n$ を試し割り法で素因数分解する．

- `map<long long, int> prime_factor(long long n)`
    - $n$ を素因数分解し，素因数とその個数の map を返す．
    - 時間計算量: $O(\sqrt{n})$