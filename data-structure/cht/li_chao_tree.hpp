#pragma once
#include <algorithm>
#include <bit>
#include <limits>
#include <utility>
#include <vector>

template <typename T>
class LiChaoTree {
   public:
    LiChaoTree() = default;
    explicit LiChaoTree(const std::vector<T>& vs) : xs(vs) {
        std::ranges::sort(xs);
        xs.erase(std::ranges::unique(xs).begin(), xs.end());
        size = std::bit_ceil(xs.size());
        node.resize(2 * size, {0, INF});
        while ((int)xs.size() <= size) xs.push_back(xs.back() + 1);
    }

    void add_line(T a, T b) { update({a, b}, 1, 0, size); }

    void add_segment(T a, T b, T xl, T xr) {
        int l = std::ranges::lower_bound(xs, xl) - xs.begin();
        int r = std::ranges::lower_bound(xs, xr) - xs.begin();

        Line line(a, b);
        int len = 1;
        int l0 = l, r0 = r;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1, len <<= 1) {
            if (l & 1) {
                update(line, l++, l0, l0 + len);
                ++l;
                l0 += len;
            }
            if (r & 1) {
                --r;
                r0 -= len;
                update(line, r, r0, r0 + len);
            }
        }
    }

    T get(T x) const {
        int k = std::ranges::lower_bound(xs, x) - xs.begin();
        k += size;
        T res = node[k](x);
        while (k >>= 1) res = std::min(res, node[k](x));
        return res;
    }

   private:
    struct Line {
        T a, b;
        Line(T a, T b) : a(a), b(b) {}
        T operator()(T x) const { return a * x + b; }
    };

    static constexpr T INF = std::numeric_limits<T>::max();

    int size;
    std::vector<T> xs;
    std::vector<Line> node;

    void update(Line line, int k, int l, int r) {
        while (true) {
            int m = std::midpoint(l, r);
            bool left = line(xs[l]) < node[k](xs[l]);
            bool mid = line(xs[m]) < node[k](xs[m]);
            bool right = line(xs[r]) < node[k](xs[r]);

            if (!left && !right) break;
            if (left && right) {
                node[k] = line;
                break;
            }
            if (mid) std::swap(node[k], line);
            if (r - l == 1) break;
            if (left != mid) {
                k = 2 * k;
                r = m;
            } else {
                k = 2 * k + 1;
                l = m;
            }
        }
    }
};
