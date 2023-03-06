#pragma once
#include <algorithm>
#include <map>
#include <set>
#include <vector>

class PartitionRefinement {
   public:
    PartitionRefinement() = default;
    explicit PartitionRefinement(int n) : sets(1), cls(n, 0) {
        for (int i = 0; i < n; ++i) sets[0].insert(i);
    }

    int find(int x) { return cls[x]; }

    bool same(int x, int y) { return find(x) == find(y); }

    int size(int i) { return sets[i].size(); }

    std::vector<int> members(int i) {
        return std::vector<int>(sets[i].begin(), sets[i].end());
    }

    std::vector<std::pair<int, int>> refine(const std::vector<int>& pivot) {
        std::map<int, std::vector<int>> split;
        for (auto x : pivot) {
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