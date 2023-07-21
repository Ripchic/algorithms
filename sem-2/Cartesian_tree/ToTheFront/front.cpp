#include <iostream>
#include <vector>
#include <random>
#include <ctime>

std::mt19937_64 rd(time(0));

class Tree {
    struct Node {
        int value = 0;
        int sz = 1;
        uint64_t prior = rd();
        Node *left = nullptr, *right = nullptr;

        Node(int value) : value(value) {

        }
    } *root = nullptr;

    int size(Node *node) {
        return (node != nullptr) ? node->sz : 0;
    }

    void upd(Node *node) {
        node->sz = size(node->left) + size(node->right) + 1;
    }

    std::pair<Node *, Node *> split(Node *node, int count) {
        if (node == nullptr) return {nullptr, nullptr};
        if (size(node->left) + 1 <= count) {
            auto q = split(node->right, count - size(node->left) - 1);
            node->right = q.first;
            upd(node);
            return {node, q.second};
        } else {
            auto q = split(node->left, count);
            node->left = q.second;
            upd(node);
            return {q.first, node};
        }
    }

    Node *merge(Node *less, Node *more) {
        if (less == nullptr) return more;
        if (more == nullptr) return less;
        if (less->prior > more->prior) {
            less->right = merge(less->right, more);
            upd(less);
            return less;
        } else {
            more->left = merge(less, more->left);
            upd(more);
            return more;
        }
    }

    void print(Node *node) {
        if (node == nullptr) return;
        print(node->left);
        std::cout << node->value << ' ';
        print(node->right);
    }

public:
    void insert(int index, int value) {
        auto q = split(root, index);
        root = merge(merge(q.first, new Node(value)), q.second);
    }

    void move(int start, int end) {
        auto q1 = split(root, end + 1);
        auto q2 = split(q1.first, start);
        root = merge(merge(q2.second, q2.first), q1.second);
    }

    void print() {
        print(root);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n = 0, m = 0;
    std::cin >> n >> m;
    Tree tree;
    for (int i = 0; i < n; ++i) {
        tree.insert(i, i + 1);
    }
    for (int i = 0; i < m; ++i) {
        int start = 0, end = 0;
        std::cin >> start >> end;
        --start, --end;
        tree.move(start, end);
    }
    tree.print();
    return 0;
}