#pragma once
#include <algorithm>
#include <vector>

/*
 * @brief k-d Tree
 * @docs docs/data-structure/kd_tree.md
 */
template <typename T>
class KDTree {
public:
    void add_point(int id, T x, T y) {
        points.emplace_back(id, x, y);
    }

    void build() {
        build(0, points.size() - 1, 0);
    }

    std::vector<int> search(T sx, T tx, T sy, T ty) const {
        Point s(std::min(sx, tx), std::min(sy, ty));
        Point t(std::max(sx, tx), std::max(sy, ty));
        std::vector<int> res;
        search(s, t, res, 0, points.size() - 1, 0);
        return res;
    }

private:
    struct Point {
        int id;
        T x, y;
        Point(T x, T y) : x(x), y(y) {}
        Point(int id, T x, T y) : id(id), x(x), y(y) {}
    };

    std::vector<Point> points;

    int check_position(const Point& p, const Point& s, const Point& t, int axis) const {
        if (axis == 0) {
            if (p.x < s.x) return -1;
            if (t.x < p.x) return 1;
            return 0;
        } else {
            if (p.y < s.y) return -1;
            if (t.y < p.y) return 1;
            return 0;
        }
    }

    void build(int l, int r, int axis) {
        if (l > r) return;
        std::sort(points.begin() + l, points.begin() + r + 1, [&](const auto& p1, const auto& p2) {
            return axis == 0 ? p1.x < p2.x : p1.y < p2.y;
        });
        int m = (l + r) / 2;
        build(l, m - 1, 1 - axis);
        build(m + 1, r, 1 - axis);
    }

    void search(const Point& s, const Point& t, std::vector<int>& res, int l, int r, int axis) const {
        if (l > r) return;
        int m = (l + r) / 2;
        bool contained = true;
        for (int i = 0; i < 2; i++) contained &= check_position(points[m], s, t, i) == 0;
        if (contained) res.push_back(points[m].id);
        if (l == r) return;
        int pos = check_position(points[m], s, t, axis);
        if (pos != -1) search(s, t, res, l, m - 1, 1 - axis);
        if (pos != 1) search(s, t, res, m + 1, r, 1 - axis);
    }
};