---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: data-structure/trie.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/trie.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 10:11:59+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node {
        vector<int> child;
        bool is_end = false;
        int count = 0;

        Node() : child(26, -1) {}
    };

    vector<Node> nodes;

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

    int query(string& s) {
        int node = 0;
        for (char c : s) {
            if (nodes[node].child[c - 'a'] == -1) return 0;
            node = nodes[node].child[c - 'a'];
        }
        return nodes[node].count;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/trie.cpp"
#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node {
        vector<int> child;
        bool is_end = false;
        int count = 0;

        Node() : child(26, -1) {}
    };

    vector<Node> nodes;

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

    int query(string& s) {
        int node = 0;
        for (char c : s) {
            if (nodes[node].child[c - 'a'] == -1) return 0;
            node = nodes[node].child[c - 'a'];
        }
        return nodes[node].count;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

