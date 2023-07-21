#include <iostream>
#include <algorithm>
#include <set>
#include <tuple>
#include <climits>

class SegTree {

    struct Node {
        Node *left = nullptr, *right = nullptr;
        int64_t begin = 0, end = 0;

        int64_t assign = INT64_MAX;
        int64_t min = 0;

        Node(int64_t begin, int64_t end) : begin(begin), end(end) {
            if (begin + 1 < end) {
                int64_t mid = (begin + end) / 2;
                left = new Node(begin, mid);
                right = new Node(mid, end);
            }
        }

        void push() {
            if (assign != INT64_MAX) {
                min = assign;
                if (left != nullptr) {
                    left->assign = assign;
                    right->assign = assign;
                }
                assign = INT64_MAX;
            }
        }

        void update(int64_t qleft, int64_t qright, int64_t value) {
            push();
            if (begin >= qleft && end <= qright) {
                assign = value;
                push();
            } else if (begin < qright && end > qleft) {
                left->update(qleft, qright, value);
                right->update(qleft, qright, value);
                min = std::min(left->min, right->min);
            }
        }

        void add(int64_t index, int64_t value) {
            min = std::min(min, value);
            if (left != nullptr) {
                if (index < left->end) {
                    left->add(index, value);
                } else {
                    right->add(index, value);
                }
            }
        }

        int64_t get_min(int64_t qleft, int64_t qright) {
            push();
            if (qleft <= begin && end <= qright) {
                return min;
            }
            if (qright <= begin || end <= qleft) {
                return INT64_MAX;
            }
            return std::min(left->get_min(qleft, qright), right->get_min(qleft, qright));
        }

        void print_leafs() {
            push();
            if (left == nullptr) {
                std::cout << min << ' ';
            } else {
                left->print_leafs();
                right->print_leafs();
            }
        }

        ~Node() {
            delete left;
            delete right;
        }
    } *root;

public:

    SegTree(int64_t begin, int64_t end) {
        root = new Node(begin, end);
    }

    void add(int64_t index, int64_t value) {
        root->add(index, value);
    }

    int64_t get_min(int64_t qleft, int64_t qright) {
        return root->get_min(qleft, qright);
    }

    ~SegTree() {
        delete root;
    }

    void update(int64_t qleft, int64_t qright, int64_t value) {
        root->update(qleft, qright, value);
    }

    void print_leafs() {
        root->print_leafs();
    }

};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::set<std::tuple<int, int, int>> data;
    int n = 0, m = 0;
    std::cin >> n >> m;
    SegTree segTree(1, n + 1);
    for (int i = 1; i <= n; ++i) {
        segTree.add(i, 0);
    }
    for (int i = 0; i < m; ++i) {
        int l = 0, r = 0, v = 0;
        std::cin >> l >> r >> v;
        data.insert({v, l, r});
    }
    for (const auto &i: data) {
        int l = std::get<1>(i), r = std::get<2>(i), v = std::get<0>(i);
        segTree.update(l, r + 1, v);
    }
    for (const auto &i: data) {
        int l = std::get<1>(i), r = std::get<2>(i), v = std::get<0>(i);
        if (segTree.get_min(l, r + 1) != v) {
            std::cout << "inconsistent";
            return 0;
        }
    }
    std::cout << "consistent" << '\n';
    segTree.print_leafs();
    return 0;
}