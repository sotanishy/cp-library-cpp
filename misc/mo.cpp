#pragma once
#include <algorithm>
#include <cmath>
#include <vector>

class Mo {
public:
    Mo() = default;
    explicit Mo(int n) : n(n), cnt(0) {}

    void query(int l, int r) {
        queries.emplace_back(cnt++, l, r);
    }

    template <typename ExL, typename ShL, typename ExR, typename ShR, typename Out>
    void run(ExL exl, ShL shl, ExR exr, ShR shr, Out out) {
        int s = sqrt(n);
        std::sort(queries.begin(), queries.end(), [&](const auto& a, const auto& b) {
            if (a.l / s != b.l / s) return a.l < b.l;
            return a.r < b.r;
        });
        int curL = 0, curR = 0;
        for (auto [id, l, r] : queries) {
            while (curL > l) exl(--curL);
            while (curL < l) shl(curL++);
            while (curR < r) exr(curR++);
            while (curR > r) shr(--curR);
            out(id);
        }
    }

private:
    struct Query {
        int id, l, r;
        Query(int id, int l, int r) : id(id), l(l), r(r) {}
    };

    int n, cnt;
    std::vector<Query> queries;
};