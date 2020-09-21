#include <bits/stdc++.h>

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

    int check_position(const Point& point, const Point& start, const Point& end, int axis) const {
        if (axis == 0) {
            if (start.x <= point.x && point.x <= end.x) return 0;
            if (point.x < start.x) return -1;
            return 1;
        } else {
            if (start.y <= point.y && point.y <= end.y) return 0;
            if (point.y < start.y) return -1;
            return 1;
        }
    }

    void build(int left, int right, int depth) {
        if (left > right) return;

        int axis = depth % 2;
        if (axis == 0) {
            std::sort(points.begin() + left, points.begin() + right + 1, [](const auto& p1, const auto& p2) { return p1.x < p2.x; });
        } else {
            std::sort(points.begin() + left, points.begin() + right + 1, [](const auto& p1, const auto& p2) { return p1.y < p2.y; });
        }
        int mid = (left + right) / 2;
        build(left, mid - 1, depth + 1);
        build(mid + 1, right, depth + 1);
    }

    void search(const Point& start, const Point& end, std::vector<int>& res, int left, int right, int depth) const {
        if (left > right) return;

        int axis = depth % 2;
        int mid = (left + right) / 2;
        bool contained = true;
        for (int i = 0; i < 2; i++) contained &= check_position(points[mid], start, end, i) == 0;
        if (contained) res.push_back(points[mid].id);
        if (left == right) return;
        int pos = check_position(points[mid], start, end, axis);
        if (pos != -1) search(start, end, res, left, mid - 1, depth + 1);
        if (pos != 1) search(start, end, res, mid + 1, right, depth + 1);
    }
};