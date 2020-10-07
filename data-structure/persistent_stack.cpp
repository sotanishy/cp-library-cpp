#include <bits/stdc++.h>

/*
 * @brief Persistent Stack
 */
template <typename T>
class PersistentStack {
public:
    PersistentStack() = default;

    T top() const {
        return last->val;
    }

    PersistentStack push(const T& val) const {
        return PersistentStack(std::make_shared<Node>(val, last));
    }

    PersistentStack pop() const {
        return PersistentStack(last->prev);
    }

private:
    struct Node {
        T val;
        std::shared_ptr<Node> prev;
    };

    std::shared_ptr<Node> last;

    explicit PersistentStack(std::shared_ptr<Node> last) : last(last) {}
};