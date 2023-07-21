#include <iostream>
#include <random>
#include <string>
#include <ctime>

std::mt19937_64 rd(time(0));

struct Node {
    int value = 0;
    uint64_t prior = rd();
    Node *left = nullptr, *right = nullptr;

    Node(int value) : value(value) {}
} *root = nullptr;

std::pair<Node *, Node *> split(Node *node, int key) {
    if (node == nullptr) return {nullptr, nullptr};
    else if (key > node->value) {
        auto q = split(node->right, key);
        node->right = q.first;
        return {node, q.second};
    } else {
        auto q = split(node->left, key);
        node->left = q.second;
        return {q.first, node};
    }

}

Node *merge(Node *left, Node *right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;
    if (left->prior > right->prior) {
        left->right = merge(left->right, right);
        return left;
    } else {
        right->left = merge(left, right->left);
        return right;
    }
}

bool existence(Node *node, int value) {
    if (node) {
        if (node->value == value) return true;
        if (node->value < value) return existence(node->right, value);
        else return existence(node->left, value);
    }
    return false;
}

void insert(int value) {
    Node *tmp = new Node(value);
    auto q = split(root, value);
    root = merge(merge(q.first, tmp), q.second);
}

void remove(int value) {
    auto q1 = split(root, value);
    auto q2 = split(q1.second, value + 1);
    root = merge(q1.first, q2.second);
}

Node *next(Node *node, int value) {
    if (node) {
        if (node->value <= value) {
            return next(node->right, value);
        } else {
            Node *tmp = next(node->left, value);
            if (tmp == nullptr) return node;
            return tmp;
        }
    }
    return nullptr;
}

Node *prev(Node *node, int value) {
    if (node) {
        if (node->value >= value) {
            return prev(node->left, value);
        } else {
            Node *tmp = prev(node->right, value);
            if (tmp == nullptr) return node;
            return tmp;
        }
    }
    return nullptr;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string s;
    while (std::cin >> s) {
        if (s == "insert") {
            int x;
            std::cin >> x;
            insert(x);
        } else if (s == "exists") {
            int x;
            std::cin >> x;
            if (existence(root, x)) {
                std::cout << "true" << '\n';
            } else {
                std::cout << "false" << '\n';
            }
        } else if (s == "delete") {
            int x;
            std::cin >> x;
            remove(x);
        } else if (s == "next") {
            int x;
            std::cin >> x;
            Node *res = next(root, x);
            if (res == nullptr) {
                std::cout << "none" << '\n';
            } else {
                std::cout << res->value << '\n';
            }
        } else if (s == "prev") {
            int x;
            std::cin >> x;
            Node *res = prev(root, x);
            if (res == nullptr) {
                std::cout << "none" << '\n';
            } else {
                std::cout << res->value << '\n';
            }
        }
    }
    return 0;
}