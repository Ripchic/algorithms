#include <iostream>
#include <algorithm>

template<typename T>
class SegTree {

    struct Node {
        Node *left = nullptr, *right = nullptr;
        int begin = 0, end = 0;

        T max = 0;
        int max_id = 0;

        Node(int begin, int end) : begin(begin), end(end) {
            if (begin + 1 < end) {
                int mid = (begin + end) / 2;
                left = new Node(begin, mid);
                right = new Node(mid, end);
            }
        }

        void add(int index, T value) {
            if (left != nullptr) {
                if (index < left->end) {
                    left->add(index, value);
                } else {
                    right->add(index, value);
                }
            }
            if (begin + 1 == end) {
                max = value;
                max_id = index;
            } else {
                max = std::max(left->max, right->max);
                max_id = left->max > right->max ? left->max_id : right->max_id;
            }
        }

        std::pair<T, int> get_max(int qleft, int qright) {
            if (qleft <= begin && end <= qright) {
                return std::pair<T, int>{max, max_id};
            }
            if (qright <= begin || end <= qleft) {
                return std::pair<T, int>{-2e9, -1};
            }
            auto left_max = left->get_max(qleft, qright);
            auto right_max = right->get_max(qleft, qright);
            if (left_max.first > right_max.first) {
                return left_max;
            } else {
                return right_max;
            }
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
        return root->get_max(qleft, qright).first;
    }

    int get_max_id(int qleft, int qright) {
        return root->get_max(qleft, qright).second;
    }

    ~SegTree() {
        delete root;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
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
        int l = 0, r = 0;
        std::cin >> l >> r;
        std::cout << segTree.get_max(l, r + 1) << ' ' <<
                  segTree.get_max_id(l, r + 1) << '\n';
    }
    return 0;
}