#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
class SegTree {

    struct Node {
        Node *left = nullptr, *right = nullptr;
        int begin = 0, end = 0;

        T assign = 0;
        T max = -2e9;

        Node(int begin, int end) : begin(begin), end(end) {
            if (begin + 1 < end) {
                int mid = (begin + end) / 2;
                left = new Node(begin, mid);
                right = new Node(mid, end);
            }
        }

        void push() {
            if (assign != 0) {
                max += assign;
                if (left != nullptr) {
                    left->assign += assign;
                    right->assign += assign;
                }
                assign = 0;
            }
        }

        void update(int qleft, int qright, T value) {
            push();
            if (begin >= qleft && end <= qright) {
                assign += value;
                push();
            } else if (begin < qright && end > qleft) {
                left->update(qleft, qright, value);
                right->update(qleft, qright, value);
                max = std::max(left->max, right->max);
            }
        }

        void add(int index, T value) {
            max = std::max(max, value);
            if (left != nullptr) {
                if (index < left->end) {
                    left->add(index, value);
                } else {
                    right->add(index, value);
                }
            }
        }

        T get_max(int qleft, int qright) {
            push();
            if (qleft <= begin && end <= qright) {
                return max;
            }
            if (qright <= begin || end <= qleft) {
                return -2e9;
            }
            return std::max(left->get_max(qleft, qright), right->get_max(qleft, qright));
        }

        ~Node() {
            delete left;
            delete right;
        }
    } *root;

public:

    SegTree(int begin, int end) {
        root = new Node(begin, end);
    }

    void add(int index, T value) {
        root->add(index, value);
    }

    T get_max(int qleft, int qright) {
        return root->get_max(qleft, qright);
    }

    ~SegTree() {
        delete root;
    }

    void update(int qleft, int qright, T value) {
        root->update(qleft, qright, value);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n = 0, k = 0;
    std::cin >> n >> k;
    SegTree<int> tree(1, n + 1);
    for (int i = 1; i <= n; ++i) {
        tree.add(i, 0);
    }
    std::vector<std::pair<int, int>> colors(n + 1, {0, 0});
    for (int i = 1; i <= k; ++i) {
        int type = 0;
        std::cin >> type;
        if (type == 1) {
            int l = 0, r = 0;
            std::cin >> l >> r;
            colors[i] = {l, r};
            if (tree.get_max(l, r + 1) == 0) {
                tree.update(l, r + 1, i);
                std::cout << 1 << '\n';
            } else {
                std::cout << 0 << '\n';
            }
        } else {
            int index = 0;
            std::cin >> index;
            int ind = tree.get_max(index, index + 1);
            std::cout << colors[ind].first << ' ' << colors[ind].second << '\n';
            tree.update(colors[ind].first, colors[ind].second + 1, -ind);
        }
    }
    return 0;
}