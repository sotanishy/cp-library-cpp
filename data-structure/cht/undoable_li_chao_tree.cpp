#pragma once
#include <algorithm>
#include <cassert>
#include <limits>
#include <utility>
#include <vector>

/*
 * @brief Undoable Li Chao Tree
 */
template <typename T>
class UndoableLiChaoTree {
public:
    UndoableLiChaoTree() = default;
    explicit UndoableLiChaoTree(const std::vector<T>& vs) : xs(vs) {
        std::sort(xs.begin(), xs.end());
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
        size = 1;
        while (size < (int) xs.size()) size <<= 1;
        node.resize(2 * size, {0, INF});
        while ((int) xs.size() <= size) xs.push_back(xs.back() + 1);
    }

    void add(T a, T b) {
        history.emplace_back(-1, Line(0, 0));
        Line line(a, b);
        int k = 1, l = 0, r = size;
        while (true) {
            int m = (l + r) / 2;
            bool left = line(xs[l]) < node[k](xs[l]);
            bool mid = line(xs[m]) < node[k](xs[m]);
            bool right = line(xs[r]) < node[k](xs[r]);

            if (!left && !right) break;
            if (left && right) {
                history.emplace_back(k, node[k]);
                node[k] = line;
                break;
            }
            if (mid) {
                history.emplace_back(k, node[k]);
                std::swap(node[k], line);
            }
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

    T get(T x) const {
        int k = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        k += size;
        T res = node[k](x);
        while (k >>= 1) res = std::min(res, node[k](x));
        return res;
    }

    void undo() {
        assert(!history.empty());
        while (true) {
            auto [k, line] = history.back();
            history.pop_back();
            if (k == -1) break;
            node[k] = line;
        }
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
    std::vector<std::pair<int, Line>> history;
};
