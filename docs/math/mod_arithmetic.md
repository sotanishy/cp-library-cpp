# Modular Arithmetic

モジュラ計算アルゴリズム詰め合わせ

## Modular Exponentiation

$a^p \mod mod$ を二分累乗法で計算する．

また，$mod$ が素数であるとき，フェルマーの小定理を利用して $n$ の $\mod mod$ での逆元を計算することができる．(拡張ユークリッド互除法を用いた逆元の計算では $mod$ が素数である必要がなく，定数倍速いため，基本的にはそちらを用いる)

- `long long mod_pow(long long a, long long p, int mod)`
    - $a^p \mod mod$ を計算する
    - 時間計算量: $O(\lg p)$

- `long long mod_inv(long long a, int mod)`
    - $a$ の $\mod mod$ での逆元を計算する
    - 時間計算量: $O(\lg mod)$

## Discrete Logarithm

離散対数を計算する．すなわち，$a^x = b (\mod mod)$ を満たす $x$ を求める．

Baby-step giant-step 法を用いている．

- `int mod_log(long long a, long long b, int mod)`
    - $a^x = b (\mod mod)$ を満たす $x$ を求める．存在しない場合は $-1$ を返す．
    - 時間計算量: $O(\sqrt{mod})$

## Quadratic Residue

平方剰余を計算する．すなわち，$r^2 = n (\mod p)$ を満たす $r$ を求める．

Tonelli-Shanks algorithm を用いている．時間計算量はよくわからない．

- `long long mod_sqrt(long long n, long long p)`
    - $r^2 = n (\mod p)$ を満たす $r$ を求める．$n = 0$ のときは $0$ を返す．$n$ と $p$ が互いに素でないときと $r$ が存在しないときは$-1$ を返す．