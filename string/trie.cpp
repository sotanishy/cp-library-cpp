#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    Trie() : nodes(1) {}

    void add(string& s, int id) {
        int node = 0;
        for (char c : s) {
            if (nodes[node].child[c - 'a'] == -1) {
                nodes[node].child[c - 'a'] = nodes.size();
                nodes.emplace_back();
            }
            nodes[node].count++;
            node = nodes[node].child[c - 'a'];
        }
        nodes[node].is_end = true;
    }

    int query(string& s) const {
        int node = 0;
        for (char c : s) {
            if (nodes[node].child[c - 'a'] == -1) return 0;
            node = nodes[node].child[c - 'a'];
        }
        return nodes[node].count;
    }

private:
    struct Node {
        vector<int> child;
        bool is_end = false;
        int count = 0;

        Node() : child(26, -1) {}
    };

    vector<Node> nodes;
};