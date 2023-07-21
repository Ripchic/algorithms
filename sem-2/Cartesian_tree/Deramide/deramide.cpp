#include <iostream>
#include <set>
#include <map>
#include <vector>


struct Node {
    int id = 0;
    int value = 0;
    int prior = 0;
    int prev = 0;
    Node *left = nullptr, *right = nullptr;

    Node(int value, int prior) : value(value), prior(prior) {}
} *root = nullptr;

std::pair<Node *, Node *> split(Node *node, int key) {
    if (node == nullptr) return {nullptr, 0};
    if (node->value <= key) {
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

void insert(int value, int prior, int id) {
    Node *tmp = new Node(value, prior);
    tmp->id = id;
    auto q = split(root, value);
    root = merge(merge(q.first, tmp), q.second);
}

void driver(Node *node, int value, std::map<int, std::vector<int>> &res) {
    node->prev = value;
    res[node->id].push_back(node->prev);
    if (node->left) {
        res[node->id].push_back(node->left->id);
        driver(node->left, node->id, res);
    } else res[node->id].push_back(0);
    if (node->right) {
        res[node->id].push_back(node->right->id);
        driver(node->right, node->id, res);
    } else res[node->id].push_back(0);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::map<int, std::vector<int>> ans;
    int n = 0;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        int key = 0, prior = 0;
        std::cin >> key >> prior;
        insert(key, -prior, i);
    }
    driver(root, 0, ans);
    std::cout << "YES" << '\n';
    for (auto &i: ans) {
        std::cout << i.second[0] << " " << i.second[1] << " " << i.second[2] << "\n";
    }
    return 0;
}