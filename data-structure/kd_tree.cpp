#include <bits/stdc++.h>
using namespace std;

/*
 * @brief k-d Tree
 * @docs docs/data-structure/kd_tree.md
 */
template <typename T>
struct KDTree {
public:
    void add_point(int id, T x, T y) {
        points.emplace_back(id, x, y);
    }

    void build() {
        build_rec(0, points.size() - 1, 0);
    }

    vector<int> search(T sx, T tx, T sy, T ty) {
        Point s(min(sx, tx), min(sy, ty));
        Point t(max(sx, tx), max(sy, ty));
        vector<int> res;
        search_rec(s, t, res, 0, points.size() - 1, 0);
        return res;
    }

private:
    struct Point {
        int id;
        T x, y;
        Point(T x, T y) : x(x), y(y) {}
        Point(int id, T x, T y) : id(id), x(x), y(y) {}
    };

    vector<Point> points;

    int check_position(Point& point, Point& start, Point& end, int axis) {
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

    void build_rec(int left, int right, int depth) {
        if (left > right) return;

        int axis = depth % 2;
        if (axis == 0) sort(points.begin() + left, points.begin() + right + 1, [](const auto& p1, const auto& p2) { return p1.x < p2.x; });
        else sort(points.begin() + left, points.begin() + right + 1, [](const auto& p1, const auto& p2) { return p1.y < p2.y; });
        int mid = (left + right) / 2;
        build_rec(left, mid - 1, depth + 1);
        build_rec(mid + 1, right, depth + 1);
    }

    void search_rec(Point& start, Point& end, vector<int>& res, int left, int right, int depth) {
        if (left > right) return;

        int axis = depth % 2;
        int mid = (left + right) / 2;
        bool contained = true;
        for (int i = 0; i < 2; i++) contained &= check_position(points[mid], start, end, i) == 0;
        if (contained) res.push_back(points[mid].id);
        if (left == right) return;
        int pos = check_position(points[mid], start, end, axis);
        if (pos != -1) search_rec(start, end, res, left, mid - 1, depth + 1);
        if (pos != 1) search_rec(start, end, res, mid + 1, right, depth + 1);
    }
};