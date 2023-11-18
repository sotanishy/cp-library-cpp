#include <cmath>
#include <vector>

#include "multipoint_evaluation.cpp"
#include "polynomial.cpp"

template <typename mint>
class Factorial {
   public:
    Factorial() : B(std::sqrt(mint::get_mod())) {
        int n = 1;
        while (n < B) n <<= 1;
        std::vector<Polynomial<mint>> p(2 * n, {1});
        for (int i = 0; i < B; ++i) p[n + i] = {i + 1, 1};
        for (int i = n - 1; i > 0; --i) p[i] = p[2 * i] * p[2 * i + 1];
        std::vector<mint> x(B);
        for (int i = 0; i < B; ++i) x[i] = i * B;
        f = multipoint_evaluation(p[1], x);
    }

    mint query(int n) {
        mint res = 1;
        for (int i = 0; i < n / B; ++i) res *= f[i];
        for (int i = n / B * B + 1; i <= n; ++i) res *= i;
        return res;
    }

   private:
    const int B;
    std::vector<mint> f;
};
