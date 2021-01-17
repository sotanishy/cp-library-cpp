#pragma once
#include <algorithm>
#include <cassert>
#include <stack>
#include <utility>
#include <vector>

template <typename M>
class UndoableUnionFind {
    using T = typename M::T;

public:
    UndoableUnionFind() = default;
    explicit UndoableUnionFind(int n) : UndoableUnionFind(std::vector<T>(n, M::id)) {}
    explicit UndoableUnionFind(const std::vector<T>& v)
        : data(v.size(), -1), val(v.begin(), v.end()) {}

    int find(int x) const {
        if (data[x] < 0) return x;
        return find(data[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        history.emplace(-1, 0, M::id);
        history.emplace(x, data[x], val[x]);
        history.emplace(y, data[y], val[y]);
        if (x == y) return;
        if (data[x] > data[y]) std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
        val[x] = M::op(val[x], val[y]);
    }

    void undo() {
        assert(!history.empty());
        while (true) {
            auto [x, dx, vx] = history.top();
            history.pop();
            if (x == -1) break;
            data[x] = dx;
            val[x] = vx;
        }
    }

    bool same(int x, int y) const {
        return find(x) == find(y);
    }

    int size(int x) const {
        return -data[find(x)];
    }

    T component_fold(int x) const {
        return val[find(x)];
    }

    void update(int x, const T& v) {
        x = find(x);
        history.emplace(-1, 0, M::id);
        history.emplace(x, data[x], val[x]);
        val[x] = M::op(val[x], v);
    }

private:
    std::vector<int> data;
    std::vector<T> val;
    std::stack<std::tuple<int, int, T>> history;
};