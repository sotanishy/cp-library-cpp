#pragma once
#include <algorithm>
#include <set>
#include <queue>
#include <vector>

// given the ground set E and oracles for M1 and M2
// find the max cardinality set S that is in both I(M1) and I(M2)
template <typename F1, typename F2>
std::set<int> matroid_intersection(int E, F1 oracle1, F2 oracle2) {
    std::set<int> S;
    std::vector<bool> is_source(E), is_sink(E);
    std::vector<int> dist(E, -1), prv(E, -1);
    std::queue<int> que;
    while (true) {
        std::fill(is_source.begin(), is_source.end(), false);
        std::fill(is_sink.begin(), is_sink.end(), false);
        std::fill(dist.begin(), dist.end(), -1);
        std::fill(prv.begin(), prv.end(), -1);
        while (!que.empty()) que.pop();

        // check sink and source
        bool upd = false;
        for (int i = 0; i < E; ++i) {
            if (!S.count(i)) {
                S.insert(i);
                is_source[i] = oracle1(S);
                is_sink[i] = oracle2(S);
                if (is_source[i]) {
                    if (is_sink[i]) {
                        // i is both a source and a sink, so i can be added to S
                        upd = true;
                        break;
                    }
                    dist[i] = 0;
                    que.push(i);
                }
                S.erase(i);
            }
        }
        if (upd) continue;

        // find the shortest path with BFS
        while (!que.empty()) {
            int i = que.front();
            que.pop();
            if (is_sink[i]) {
                // shortest source-sink path found, update S
                do {
                    if (S.count(i)) {
                        S.erase(i);
                    } else {
                        S.insert(i);
                    }
                    i = prv[i];
                } while (i != -1);
                upd = true;
                break;
            }
            if (S.count(i)) {
                // i -> j
                for (int j = 0; j < E; ++j) {
                    if (dist[j] == -1 && !is_source[j] && !S.count(j)) {
                        S.erase(i);
                        S.insert(j);
                        if (oracle1(S)) {
                            dist[j] = dist[i] + 1;
                            prv[j] = i;
                            que.push(j);
                        }
                        S.insert(i);
                        S.erase(j);
                    }
                }
            } else {
                // j <- i
                for (int j = 0; j < E; ++j) {
                    if (dist[j] == -1 && S.count(j)) {
                        S.erase(j);
                        S.insert(i);
                        if (oracle2(S)) {
                            dist[j] = dist[i] + 1;
                            prv[j] = i;
                            que.push(j);
                        }
                        S.insert(j);
                        S.erase(i);
                    }
                }
            }
        }
        if (!upd) {
            // no source-sink path found
            break;
        }
    }
    return S;
}