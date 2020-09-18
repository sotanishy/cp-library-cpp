# Prime Factor

$n$ を試し割り法で素因数分解する．

- `map<long long, int> prime_factor(long long n)`
    - $n$ を素因数分解し，素因数とその個数の map を返す．
    - 時間計算量: $O(\sqrt{n})$