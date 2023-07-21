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
    if (existence(root, value)) return;
    Node *tmp = new Node(value);
    auto q = split(root, value);
    root = merge(merge(q.first, tmp), q.second);
}

int min(Node *node) {
    if (node == nullptr) {
        return -1;
    }
    while (node->left) {
        node = node->left;
    }
    return node->value;
}

int next(int value) {
    auto q1 = split(root, value);
    int res = min(q1.second);
    root = merge(q1.first, q1.second);
    return res;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string s;
    int prev = 0;
    bool what = false;
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> s;
        if (s == "+" && (i == 0 || !what)) {
            what = false;
            int x = 0;
            std::cin >> x;
            insert(x);
        } else if (s == "+" && what) {
            what = false;
            int x = 0;
            std::cin >> x;
            insert((x + prev) % 1000000000);
        } else {
            what = true;
            int x;
            std::cin >> x;
            prev = next(x);
            std::cout << prev << '\n';
        }
    }
}