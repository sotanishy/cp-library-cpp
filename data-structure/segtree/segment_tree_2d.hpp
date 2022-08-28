#include <algorithm>
#include <utility>
#include <vector>
#include "segment_tree.cpp"

template <typename X, typename Y, typename M>
class SegmentTree2D {
    using T = typename M::T;

public:
    SegmentTree2D() = default;
    explicit SegmentTree2D(const std::vector<std::pair<X, Y>>& pts) {
        for (auto& [x, y] : pts) {
            xs.push_back(x);
        }
        std::sort(xs.begin(), xs.end());
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());

        const int n = xs.size();
        size = 1;
        while (size < n) size <<= 1;
        ys.resize(2 * size);
        seg.resize(2 * size);

        for (auto& [x, y] : pts) {
            int k = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();
            ys[size + k].push_back(y);
        }

        for (int i = 0; i < n; ++i) {
            std::sort(ys[size + i].begin(), ys[size + i].end());
            ys[size + i].erase(std::unique(ys[size + i].begin(), ys[size + i].end()), ys[size + i].end());
        }
        for (int i = size - 1; i > 0; --i) {
            std::merge(ys[2*i].begin(), ys[2*i].end(), ys[2*i+1].begin(), ys[2*i+1].end(), std::back_inserter(ys[i]));
        }
        for (int i = 0; i < size + n; ++i) {
            seg[i] = SegmentTree<M>(ys[i].size());
        }
    }

    void update(X x, Y y, T val) {
        int k = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin() + size;
        while (k) {
            int i = std::lower_bound(ys[k].begin(), ys[k].end(), y) - ys[k].begin();
            seg[k].update(i, val);
            k >>= 1;
        }
    }

    T fold(X sx, X tx, Y sy, Y ty) const {
        T ret = M::id();
        int l = std::lower_bound(xs.begin(), xs.end(), sx) - xs.begin();
        int r = std::lower_bound(xs.begin(), xs.end(), tx) - xs.begin();
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                int hi = std::lower_bound(ys[l].begin(), ys[l].end(), ty) - ys[l].begin();
                int lo = std::lower_bound(ys[l].begin(), ys[l].end(), sy) - ys[l].begin();
                ret = M::op(ret, seg[l].fold(lo, hi));
                ++l;
            }
            if (r & 1) {
                --r;
                int hi = std::lower_bound(ys[r].begin(), ys[r].end(), ty) - ys[r].begin();
                int lo = std::lower_bound(ys[r].begin(), ys[r].end(), sy) - ys[r].begin();
                ret = M::op(ret, seg[r].fold(lo, hi));
            }
        }
        return ret;
    }

private:
    int size;
    std::vector<X> xs;
    std::vector<std::vector<Y>> ys;
    std::vector<SegmentTree<M>> seg;
};