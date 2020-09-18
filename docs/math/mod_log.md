# Discrete Logarithm

離散対数を計算する．すなわち，$a^x = b (\mod p)$ を満たす $x$ を求める．

Baby-step giant-step 法を用いている．

- `int mod_log(long long a, long long b, long long p)`
    - $a^x = b (\mod p)$ を満たす $x$ を求める．存在しない場合は $-1$ を返す．
    - 時間計算量: $O(\sqrt{p})$