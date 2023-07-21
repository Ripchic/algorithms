#include <iostream>
#include <algorithm>

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
    int n = 0;
    std::cin >> n;
    SegTree<int> segTree(1, n + 1);
    for (int i = 1; i <= n; ++i) {
        int a = 0;
        std::cin >> a;
        segTree.add(i, a);
    }
    int m = 0;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        std::string s;
        std::cin >> s;
        if (s == "m") {
            int l = 0, r = 0;
            std::cin >> l >> r;
            std::cout << segTree.get_max(l, r + 1) << ' ';
        } else {
            int l = 0, r = 0, v = 0;
            std::cin >> l >> r >> v;
            segTree.update(l, r + 1, v);
        }
    }
    return 0;
}