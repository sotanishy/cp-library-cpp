#define PROBLEM \
    "https://judge.yosupo.jp/problem/chordal_graph_recognition.test.cpp"

// #include "../../tree/centroid_decomposition.hpp"
// #include "../../convolution/fft.hpp"
#include "../../data-structure/partition_refinement.hpp"
#include "../../graph/lex_bfs.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, t) for (int i = (int)(s); i < (int)(t); ++i)
#define revrep(i, t, s) for (int i = (int)(t)-1; i >= (int)(s); --i)
#define all(x) begin(x), end(x)
template <typename T>
bool chmax(T& a, const T& b) {
    return a < b ? (a = b, 1) : 0;
}
template <typename T>
bool chmin(T& a, const T& b) {
    return a > b ? (a = b, 1) : 0;
}

class PartitionRefinement {
   public:
    PartitionRefinement() = default;
    explicit PartitionRefinement(int n) : sets(1), cls(n, 0) {
        for (int i = 0; i < n; ++i) sets[0].insert(i);
    }

    int find(int x) const { return cls[x]; }

    bool same(int x, int y) const {
        int cx = find(x), cy = find(y);
        return cx != -1 && cy != -1 && cx == cy;
    }

    bool contains(int x) const { return cls[x] != -1; }

    void erase(int x) {
        if (contains(x)) {
            sets[cls[x]].erase(x);
            cls[x] = -1;
        }
    }

    int size(int i) const { return sets[i].size(); }

    int member(int i) const {
        assert(0 <= i && i < (int)sets.size());
        return *sets[i].begin();
    }

    std::vector<int> members(int i) const {
        assert(0 <= i && i < (int)sets.size());
        return std::vector<int>(sets[i].begin(), sets[i].end());
    }

    std::vector<std::pair<int, int>> refine(const std::vector<int>& pivot) {
        std::map<int, std::vector<int>> split;
        for (auto x : pivot) {
            if (!contains(x)) continue;
            int i = cls[x];
            split[i].push_back(x);
            sets[i].erase(x);
        }
        std::vector<std::pair<int, int>> updated;
        for (auto& [i, s] : split) {
            int ni = sets.size();
            sets.emplace_back(s.begin(), s.end());
            if (sets[i].size() < sets[ni].size()) {
                std::swap(sets[i], sets[ni]);
            }
            if (sets[ni].empty()) {
                sets.pop_back();
                continue;
            }
            for (auto x : sets[ni]) {
                cls[x] = ni;
            }
            updated.push_back({i, ni});
        }
        return updated;
    }

   private:
    std::vector<std::set<int>> sets;
    std::vector<int> cls;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    rep(i, 0, M) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    auto [ans, vec] = recognize_chordal_graph(G);
    cout << (ans ? "YES" : "NO") << "\n";
    if (!ans) cout << vec.size() << "\n";
    for (int i = 0; i < (int)vec.size(); ++i) {
        cout << vec[i] << (i < (int)vec.size() - 1 ? " " : "\n");
    }
}