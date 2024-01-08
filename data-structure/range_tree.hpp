#pragma once
#include <algorithm>
#include <bit>
#include <utility>
#include <vector>

template <typename X, typename Y, typename T>
class RangeTree {
   public:
    RangeTree() = default;
    explicit RangeTree(const std::vector<std::tuple<X, Y, T>>& pts) {
        for (auto& [x, y, v] : pts) xs.push_back(x);
        std::ranges::sort(xs);
        xs.erase(std::ranges::unique(xs).begin(), xs.end());

        const int n = xs.size();
        size = std::bit_ceil((unsigned int)n);

        node.resize(2 * size);
        sum.resize(2 * size);

        for (auto& [x, y, v] : pts) {
            int i = std::ranges::lower_bound(xs, x) - xs.begin();
            node[size + i].emplace_back(y, v);
        }

        for (int i = 0; i < n; ++i) {
            std::ranges::sort(node[size + i]);
        }
        for (int i = size - 1; i > 0; --i) {
            std::ranges::merge(node[2 * i], node[2 * i + 1],
                               std::back_inserter(node[i]));
        }
        for (int i = 0; i < size + n; ++i) {
            sum[i].resize(node[i].size() + 1);
            for (int j = 0; j < (int)node[i].size(); ++j) {
                sum[i][j + 1] = sum[i][j] + node[i][j].second;
            }
        }
    }

    T fold(X sx, X tx, Y sy, Y ty) const {
        int l = std::ranges::lower_bound(xs, sx) - xs.begin();
        int r = std::ranges::lower_bound(xs, tx) - xs.begin();
        T ret = 0;
        auto proj = [&](const auto& p) { return p.first; };
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                int hi = std::ranges::lower_bound(node[l], ty, {}, proj) -
                         node[l].begin();
                int lo = std::ranges::lower_bound(node[l], sy, {}, proj) -
                         node[l].begin();
                ret += sum[l][hi] - sum[l][lo];
                ++l;
            }
            if (r & 1) {
                --r;
                int hi = std::ranges::lower_bound(node[r], ty, {}, proj) -
                         node[r].begin();
                int lo = std::ranges::lower_bound(node[r], sy, {}, proj) -
                         node[r].begin();
                ret += sum[r][hi] - sum[r][lo];
            }
        }
        return ret;
    }

   private:
    int size;
    std::vector<X> xs;
    std::vector<std::vector<std::pair<Y, T>>> node;
    std::vector<std::vector<T>> sum;
};
