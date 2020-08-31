#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y, id;
};

struct KDTree {

    vector<Point>& points;

    KDTree(vector<Point>& points) : points(points) {
        build(0, points.size() - 1, 0);
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

    vector<int> search(Point& start, Point& end) {
        Point s {min(start.x, end.x), min(start.y, end.y)};
        Point t {max(start.x, end.x), max(start.y, end.y)};
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