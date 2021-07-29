#pragma once
#include <algorithm>
#include <vector>

class RangeTree {
public:
    RangeTree() = default;
    explicit RangeTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        node.resize(2 * size);
    }

    void add_point(int x, int y) {
        node[size + x].push_back(y);
    }

    void build() {
        for (int i = 0; i < size; ++i) {
            sort(node[size + i].begin(), node[size + i].end());
        }
        for (int i = size - 1; i > 0; --i) {
            std::merge(node[2*i].begin(), node[2*i].end(), node[2*i+1].begin(), node[2*i+1].end(), std::back_inserter(node[i]));
        }
    }

    int count(int sx, int tx, int sy, int ty) const {
        int cnt = 0;
        for (int l = size + sx, r = size + tx; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                auto hi = std::lower_bound(node[l].begin(), node[l].end(), ty);
                auto lo = std::lower_bound(node[l].begin(), node[l].end(), sy);
                cnt += hi - lo;
                ++l;
            }
            if (r & 1) {
                --r;
                auto hi = std::lower_bound(node[r].begin(), node[r].end(), ty);
                auto lo = std::lower_bound(node[r].begin(), node[r].end(), sy);
                cnt += hi - lo;
            }
        }
        return cnt;
    }


private:
    int size;
    std::vector<std::vector<int>> node;
};
