# Mod Exponentiation

$a^p \mod mod$ を二分累乗法で計算する．

また，$mod$ が素数であるとき，フェルマーの小定理を利用して $n$ の $\mod mod$ での逆元を計算することができる．(拡張ユークリッド互除法を用いた逆元の計算では $mod$ が素数である必要がなく，定数倍速いため，基本的にはそちらを用いる)

- `long long mod_pow(long long a, long long p, long long mod)`
    - $a^p \mod mod$ を計算する
    - 時間計算量: $O(\lg p)$

- `long long mod_inv(long long a, long long mod)`
    - $a$ の $\mod mod$ での逆元を計算する
    - 時間計算量: $O(\lg mod)$