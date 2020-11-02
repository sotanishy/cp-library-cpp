#pragma once
#include <memory>

/*
 * @brief Persistent Stack
 * @docs docs/data-structure/persistent_stack.md
 */
template <typename T>
class PersistentStack {
public:
    PersistentStack() = default;

    T top() const {
        return last->val;
    }

    bool empty() const {
        return last == nullptr;
    }

    PersistentStack push(const T& val) const {
        return PersistentStack(std::make_shared<Node>(val, last));
    }

    PersistentStack pop() const {
        return PersistentStack(last->prev);
    }

private:
    struct Node;
    using node_ptr = std::shared_ptr<Node>;

    struct Node {
        T val;
        node_ptr prev;
        Node(T val, node_ptr prev) : val(val), prev(prev) {}
    };

    node_ptr last;

    explicit PersistentStack(node_ptr last) : last(last) {}
};