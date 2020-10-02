#include <bits/stdc++.h>
#include "../graph/edge.cpp"

/*
 * @brief Diameter of a Tree
 * @docs docs/tree/tree_diameter.md
 */
class TreeDiameter {
public:
    TreeDiameter() = delete;

    static int diameter(const std::vector<std::vector<int>>& G) {
        auto p = dfs(G, 0, -1);
        auto q = dfs(G, p.second, -1);
        return q.first;
    }

    template <typename T>
    static T diameter(const std::vector<std::vector<Edge<T>>>& G) {
        auto p = dfs(G, 0, -1);
        auto q = dfs(G, p.second, -1);
        return q.first;
    }

private:
    static std::pair<int, int> dfs(const std::vector<std::vector<int>>& G, int v, int p) {
        std::pair<int, int> ret(0, v);
        for (int c : G[v]) {
            if (c == p) continue;
            auto weight = dfs(G, c, v);
            ++weight.first;
            ret = std::max(ret, weight);
        }
        return ret;
    }

    template <typename T>
    static std::pair<T, int> dfs(const std::vector<std::vector<Edge<T>>>& G, int v, int p) {
        std::pair<T, int> ret(0, v);
        for (auto& e : G[v]) {
            if (e.to == p) continue;
            auto weight = dfs(G, e.to, v);
            weight.first += e.weight;
            ret = std::max(ret, weight);
        }
        return ret;
    }
};