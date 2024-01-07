#pragma once
#include <algorithm>
#include <map>
#include <random>
#include <utility>
#include <vector>

#include "tree_diameter.hpp"

class TreeHasher {
   public:
    TreeHasher() : rng(rd()), rand(1, mod - 1) {}

    long long hash_all(const std::vector<std::vector<int>>& G, int root = -1) {
        long long res;
        if (root == -1) {
            auto [d, path] = tree_diameter(G);
            res = dfs_all(G, path[d / 2], -1).first;
            if (d % 2 == 1) {
                res = std::min(res, dfs_all(G, path[d / 2 + 1], -1).first);
            }
        } else {
            res = dfs_all(G, root, -1).first;
        }
        return res;
    }

    std::vector<long long> hash_subtrees(const std::vector<std::vector<int>>& G,
                                         int root) {
        std::vector<long long> hash(G.size());
        dfs_subtrees(G, hash, root, -1);
        return hash;
    }

   private:
    static constexpr long long mod = (1LL << 61) - 1;

    static inline long long add(long long a, long long b) {
        if ((a += b) >= mod) a -= mod;
        return a;
    }

    static inline long long mul(long long a, long long b) {
        __int128_t c = (__int128_t)a * b;
        return add(c >> 61, c & mod);
    }

    std::random_device rd;
    std::mt19937_64 rng;
    std::uniform_int_distribution<long long> rand;
    std::vector<long long> R;

    std::pair<long long, int> dfs_all(const std::vector<std::vector<int>>& G,
                                      int v, int p) {
        int maxd = 0;
        std::vector<long long> hash;
        for (int c : G[v]) {
            if (c != p) {
                auto [h, d] = dfs_all(G, c, v);
                maxd = std::max(maxd, d + 1);
                hash.push_back(h);
            }
        }
        if ((int)R.size() == maxd) {
            R.push_back(rand(rng));
        }
        long long res = 1;
        for (auto h : hash) {
            res = mul(res, add(R[maxd], h));
        }
        return {res, maxd};
    }

    int dfs_subtrees(const std::vector<std::vector<int>>& G,
                     std::vector<long long>& hash, int v, int p) {
        int maxd = 0;
        for (int c : G[v]) {
            if (c != p) {
                maxd = std::max(maxd, dfs_subtrees(G, hash, c, v) + 1);
            }
        }
        if ((int)R.size() == maxd) {
            R.push_back(rand(rng));
        }
        long long res = 1;
        for (int c : G[v]) {
            if (c != p) {
                res = mul(res, add(R[maxd], hash[c]));
            }
        }
        hash[v] = res;
        return maxd;
    }
};

class TreeEncoder {
   public:
    TreeEncoder() { mp[{}] = 0; }

    std::vector<int> encode(const std::vector<std::vector<int>>& G, int root) {
        std::vector<int> val(G.size());
        dfs(G, val, root, -1);
        return val;
    }

   private:
    std::map<std::vector<int>, int> mp;
    std::vector<long long> R;

    void dfs(const std::vector<std::vector<int>>& G, std::vector<int>& val,
             int v, int p) {
        std::vector<int> ch;
        for (int c : G[v]) {
            if (c != p) {
                dfs(G, val, c, v);
                ch.push_back(val[c]);
            }
        }
        std::ranges::sort(ch);
        if (!mp.contains(ch)) {
            mp[ch] = mp.size();
        }
        val[v] = mp[ch];
    }
};