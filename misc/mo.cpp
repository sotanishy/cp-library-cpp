#pragma once
#include <algorithm>
#include <cmath>
#include <vector>

/*
 * @brief Mo's Algorithm
 */
class Mo {
public:
    Mo() = default;
    explicit Mo(int n) : n(n), cnt(0) {}

    void query(int l, int r) {
        queries.emplace_back(cnt++, l, r);
    }

    template <typename T, typename ExL, typename ShL, typename ExR, typename ShR>
    std::vector<T> run(T init, ExL exl, ShL shl, ExR exr, ShR shr) {
        int s = sqrt(n);
        std::sort(queries.begin(), queries.end(), [&](const auto& a, const auto& b) {
            if (a.l / s != b.l / s) return a.l < b.l;
            return a.r < b.r;
        });

        std::vector<T> ret(cnt);
        int curL = 0, curR = 0;
        T res = init;
        for (auto [id, l, r] : queries) {
            while (curL > l) res = exl(res, --curL);
            while (curL < l) res = shl(res, curL++);
            while (curR < r) res = exr(res, curR++);
            while (curR > r) res = shr(res, --curR);
            ret[id] = res;
        }
        return ret;
    }

private:
    struct Query {
        int id, l, r;
        Query(int id, int l, int r) : id(id), l(l), r(r) {}
    };

    int n, cnt;
    std::vector<Query> queries;
};
