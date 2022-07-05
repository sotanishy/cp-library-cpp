#pragma once
#include <algorithm>
#include <utility>
#include <vector>

template <typename Y, typename T>
class RangeTree {
public:
    RangeTree() = default;
    explicit RangeTree(int n, const std::vector<std::tuple<int, Y, T>>& pts) {
        size = 1;
        while (size < n) size <<= 1;
        node.resize(2 * size);
        sum.resize(2 * size);

        for (auto& [x, y, v] : pts) {
            node[size + x].emplace_back(y, v);
        }

        for (int i = 0; i < n; ++i) {
            std::sort(node[size + i].begin(), node[size + i].end());
        }
        for (int i = size - 1; i > 0; --i) {
            std::merge(node[2*i].begin(), node[2*i].end(), node[2*i+1].begin(), node[2*i+1].end(), std::back_inserter(node[i]));
        }
        for (int i = 0; i < size + n; ++i) {
            sum[i].resize(node[i].size() + 1);
            for (int j = 0; j < (int) node[i].size(); ++j) {
                sum[i][j + 1] = sum[i][j] + node[i][j].second;
            }
        }
    }

    T fold(int sx, int tx, Y sy, Y ty) const {
        T ret = 0;
        auto cmp = [&](const std::pair<Y, T>& p, Y y) { return p.first < y; };
        for (int l = size + sx, r = size + tx; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                int hi = std::lower_bound(node[l].begin(), node[l].end(), ty, cmp) - node[l].begin();
                int lo = std::lower_bound(node[l].begin(), node[l].end(), sy, cmp) - node[l].begin();
                ret += sum[l][hi] - sum[l][lo];
                ++l;
            }
            if (r & 1) {
                --r;
                int hi = std::lower_bound(node[r].begin(), node[r].end(), ty, cmp) - node[r].begin();
                int lo = std::lower_bound(node[r].begin(), node[r].end(), sy, cmp) - node[r].begin();
                ret += sum[r][hi] - sum[r][lo];
            }
        }
        return ret;
    }


private:
    int size;
    std::vector<std::vector<std::pair<Y, T>>> node;
    std::vector<std::vector<T>> sum;
};