#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_D"

#include "../../data-structure/treap.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;
    Treap<int> treap;
    for (int i = 0; i < m; i++) {
        string op;
        cin >> op;
        if (op == "insert") {
            int k, p;
            cin >> k >> p;
            treap.insert(k, p);
        } else if (op == "find") {
            int k;
            cin >> k;
            if (treap.count(k)) cout << "yes\n";
            else cout << "no\n";
        } else if (op == "delete") {
            int k;
            cin >> k;
            treap.erase(k);
        } else {
            treap.print_inorder();
            treap.print_preorder();
        }
    }
}