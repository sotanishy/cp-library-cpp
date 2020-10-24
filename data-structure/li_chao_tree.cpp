#pragma once
#include <algorithm>
#include <limits>
#include <utility>
#include <vector>

/*
 * @brief Li Chao Tree
 * @docs docs/data-structure/li_chao_tree.md
 */
template <typename T>
class LiChaoTree {
public:
    LiChaoTree() = default;
    explicit LiChaoTree(const std::vector<T>& vs) : xs(vs) {
        size = 1;
        while (size < (int) xs.size()) size <<= 1;
        node.resize(2 * size, {0, INF});
        while ((int) xs.size() <= size) xs.push_back(xs.back() + 1);
    }

    void add_line(T a, T b) {
        update({a, b}, 1, 0, size);
    }

    void add_segment(T a, T b, int l, int r) {
        std::pair<T, T> line(a, b);
        int len = 1;
        int l0 = l, r0 = r;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1, len <<= 1) {
            if (l & 1) {
                update(line, l, l0, l0 + len);
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

    T get_min(int k) const {
        const T x = xs[k];
        k += size;
        T res = f(node[k], x);
        while (k >>= 1) res = std::min(res, f(node[k], x));
        return res;
    }

private:
    static constexpr T INF = std::numeric_limits<T>::max();

    int size;
    std::vector<T> xs;
    std::vector<std::pair<T, T>> node;

    inline T f(const std::pair<T, T>& line, T x) const {
        return line.first * x + line.second;
    }

    void update(std::pair<T, T> line, int k, int l, int r) {
        while (true) {
            int m = (l + r) / 2;
            bool left = f(line, xs[l]) < f(node[k], xs[l]);
            bool mid = f(line, xs[m]) < f(node[k], xs[m]);
            bool right = f(line, xs[r]) < f(node[k], xs[r]);

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