#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct KDTree {

    struct Point {
        int id;
        T x, y;
        Point(int id, T x, T y) : id(id), x(x), y(y) {}
    };

    vector<Point> points;

    void add_point(int i, T x, T y) {
        points.emplace_back(i, x, y);
    }

    void build(int left, int right, int depth) {
        if (left > right) return;

        int axis = depth % 2;
        if (axis == 0) sort(points.begin() + left, points.begin() + right + 1, [](const auto& p1, const auto& p2) { return p1.x < p2.x; });
        else sort(points.begin() + left, points.begin() + right + 1, [](const auto& p1, const auto& p2) { return p1.y < p2.y; });
        int mid = (left + right) / 2;
        build(left, mid - 1, depth + 1);
        build(mid + 1, right, depth + 1);
    }

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

    vector<int> search(T sx, T tx, T sy, T ty) {
        Point s {-1, min(sx, tx), min(sy, ty)};
        Point t {-1, max(sx, tx), max(sy, ty)};
        vector<int> res;
        search_rec(s, t, res, 0, points.size() - 1, 0);
        return res;
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