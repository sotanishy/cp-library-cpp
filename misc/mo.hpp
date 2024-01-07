#pragma once
#include <algorithm>
#include <cmath>
#include <vector>

class Mo {
   public:
    Mo() = default;
    explicit Mo(int n) : n(n), cnt(0) {}

    void query(int l, int r) { queries.emplace_back(cnt++, l, r); }

    template <typename ExL, typename ShL, typename ExR, typename ShR,
              typename Out>
    void run(ExL exl, ShL shl, ExR exr, ShR shr, Out out) {
        int s = sqrt(n);
        std::ranges::sort(
            queries, {}, [&](auto& q) { return std::make_pair(q.l / s, q.r); });
        int curL = 0, curR = 0;
        for (auto [id, l, r] : queries) {
            while (curL > l) exl(--curL);
            while (curR < r) exr(curR++);
            while (curL < l) shl(curL++);
            while (curR > r) shr(--curR);
            out(id);
        }
    }

   private:
    struct Query {
        int id, l, r;
    };

    int n, cnt;
    std::vector<Query> queries;
};