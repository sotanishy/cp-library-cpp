#include <bits/stdc++.h>
#include "lowlink.cpp"
using namespace std;
using ll = long long;

/*
 * @brief Two-Edge-Connected Components
 * @docs docs/graph/two_edge_connected_components.md
 */
class TwoEdgeConnectedComponents {
public:
    TwoEdgeConnectedComponents() = default;
    explicit TwoEdgeConnectedComponents(const std::vector<std::vector<int>>& G)
        : G(G), lowlink(G) {


    }

private:
    vector<vector<int>> G;
    Lowlink lowlink;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


}