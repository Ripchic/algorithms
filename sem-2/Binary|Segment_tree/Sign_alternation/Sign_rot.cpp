#include <iostream>
#include <algorithm>

template<typename T>
class SegTree {

    struct Node {
        Node *left = nullptr, *right = nullptr;
        int64_t begin = 0, end = 0;
        int64_t semi_sum = 0;

        Node(int64_t begin, int64_t end) : begin(begin), end(end) {
            if (begin + 1 < end) {
                int64_t mid = (begin + end) / 2;
                left = new Node(begin, mid);
                right = new Node(mid, end);
            }
        }

        void add(int64_t index, T value) {
            if (left != nullptr) {
                if (index < left->end) {
                    left->add(index, value);
                } else {
                    right->add(index, value);
                }
            }
            if (begin + 1 == end) {
                if (index % 2 == 0) {
                    semi_sum = -value;
                } else {
                    semi_sum = value;
                }
            } else {
                semi_sum = left->semi_sum + right->semi_sum;
            }
        }

        T get_semi_sum(int64_t qleft, int64_t qright) {
            if (qleft <= begin && end <= qright) {
                return qleft % 2 == 0 ? -semi_sum : semi_sum;
            }
            if (qright <= begin || end <= qleft) {
                return 0;
            }
            return left->get_semi_sum(qleft, qright) + right->get_semi_sum(qleft, qright);
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

    void add(int64_t index, T value) {
        root->add(index, value);
    }


    T get_semi_sum(int64_t qleft, int64_t qright) {
        return root->get_semi_sum(qleft, qright);
    }

    ~SegTree() {
        delete root;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t n = 0;
    std::cin >> n;
    SegTree<int64_t> segTree(1, n + 1);
    for (int64_t i = 1; i <= n; ++i) {
        int64_t a = 0;
        std::cin >> a;
        segTree.add(i, a);
    }
    int64_t m = 0;
    std::cin >> m;
    for (int64_t i = 0; i < m; ++i) {
        int64_t type = 0;
        std::cin >> type;
        if (type == 0) {
            int ind, val;
            std::cin >> ind >> val;
            segTree.add(ind, val);
        } else {
            int64_t l = 0, r = 0;
            std::cin >> l >> r;
            std::cout << segTree.get_semi_sum(l, r + 1) << '\n';
        }
    }
    return 0;
}