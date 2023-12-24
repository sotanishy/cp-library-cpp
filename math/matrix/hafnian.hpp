#include <cassert>
#include <vector>

#include "../set_power_series.hpp"

template <typename T, int N>
T hafnian(std::vector<std::vector<T>> mat) {
    const int n = mat.size();
    assert(n % 2 == 0);
    const int n2 = n / 2;

    // cyc[S]: number of alternating cycles using all edges in S
    SetPowerSeries<T, N> cyc(1 << n2);

    for (int i = 0; i < n2; ++i) {
        int ui = 2 * i, vi = 2 * i + 1;
        // ui-vi=ui
        cyc[1 << i] += mat[ui][vi];

        // dp[S][v]: number of alternating paths between ui and v
        // using all edges in S
        std::vector dp(1 << i, std::vector<mint>(2 * i));
        for (int j = 0; j < i; ++j) {
            int uj = 2 * j, vj = 2 * j + 1;
            dp[1 << j][uj] += mat[ui][vj];  // ui-vj=uj
            dp[1 << j][vj] += mat[ui][uj];  // ui-uj=vj
        }

        for (int S = 0; S < (1 << i); ++S) {
            for (int j = 0; j < i; ++j) {
                int uj = 2 * j, vj = 2 * j + 1;
                cyc[S | (1 << i)] +=
                    dp[S][uj] * mat[vi][uj];  // ui-...=uj-vi=ui
                cyc[S | (1 << i)] +=
                    dp[S][vj] * mat[vi][vj];  // ui-...=vj-vi=ui

                for (int k = 0; k < i; ++k) {
                    if (!(S >> k & 1)) {
                        int uk = 2 * k, vk = 2 * k + 1;
                        int nS = S | (1 << k);

                        dp[nS][uk] +=
                            dp[S][uj] * mat[uj][vk];  // ui-...=uj-vk=uk
                        dp[nS][uk] +=
                            dp[S][vj] * mat[vj][vk];  // ui-...=vj-vk=uk
                        dp[nS][vk] +=
                            dp[S][uj] * mat[uj][uk];  // ui-...=uj-uk=vk
                        dp[nS][vk] +=
                            dp[S][vj] * mat[vj][uk];  // ui-...=vj-uk=vk
                    }
                }
            }
        }
    }
    return cyc.exp().back();
}