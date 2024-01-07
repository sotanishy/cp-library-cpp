#pragma once
#include <map>
#include <ranges>
#include <string>
#include <vector>

class PalindromicTree {
   public:
    PalindromicTree() : nodes(2) {
        nodes[0] = Node(-1, -1, 0);  // root for odd length palindromes
        nodes[1] = Node(0, -1, 0);   // root for even length palindromes
        nodes[1].suffix_link = 0;
        suff = 0;
    }

    explicit PalindromicTree(const std::string& s) : PalindromicTree() {
        for (char c : s) add(c);
    }

    void add(char c) {
        str.push_back(c);

        //  find a palidrome cAc
        int k = find_next_palindrome(suff);

        // the palindrome already exists
        if (nodes[k].link.count(c)) {
            ++nodes[nodes[k].link[c]].cnt;
            suff = nodes[k].link[c];
            return;
        }

        // create a new node
        nodes[k].link[c] = nodes.size();
        suff = nodes.size();
        nodes.emplace_back(nodes[k].len + 2, (int)str.size() - nodes[k].len - 2,
                           1);

        // add a suffix link
        if (nodes.back().len == 1) {
            nodes.back().suffix_link = 1;
        } else {
            const int n = find_next_palindrome(nodes[k].suffix_link);
            nodes.back().suffix_link = nodes[n].link[c];
        }
    }

    std::vector<int> get_suffix_palindromes() const {
        std::vector<int> ret;
        int k = suff;
        while (nodes[k].len > 0) {
            ret.push_back(nodes[k].len);
            k = nodes[k].suffix_link;
        }
        return ret;
    }

    // returns {length, one of the starting indices, count}
    std::vector<std::tuple<int, int, int>> get_palindrome_frequencies() {
        std::vector<std::tuple<int, int, int>> ret;
        for (auto& node : nodes | std::views::drop(1) | std::views::reverse) {
            ret.emplace_back(node.len, node.idx, node.cnt);
            nodes[node.suffix_link].cnt += node.cnt;
        }
        return ret;
    }

   private:
    struct Node {
        std::map<char, int> link;
        int suffix_link;
        int len, idx, cnt;

        Node() = default;
        Node(int len, int idx, int cnt) : len(len), idx(idx), cnt(cnt) {}
    };

    std::vector<Node> nodes;
    int suff;
    std::string str;

    int find_next_palindrome(int k) const {
        const int pos = str.size() - 1;
        while (true) {
            int i = pos - 1 - nodes[k].len;
            if (i >= 0 && str[i] == str[pos]) break;
            k = nodes[k].suffix_link;
        }
        return k;
    }
};
