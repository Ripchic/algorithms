#include <iostream>
#include <vector>
#include <numeric>

template<typename T>
class SegTree {

    struct Node {
        Node *left = nullptr, *right = nullptr;
        int begin = 0, end = 0;

        T gcd = 0;

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
                gcd = value;
            } else {
                gcd = std::gcd(left->gcd, right->gcd);
            }
        }

        T get_gcd(int qleft, int qright) {
            if (qleft <= begin && end <= qright) {
                return gcd;
            }
            if (qright <= begin || end <= qleft) {
                return 0;
            }
            return std::gcd(left->get_gcd(qleft, qright), right->get_gcd(qleft, qright));
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

    T get_gcd(int qleft, int qright) {
        return root->get_gcd(qleft, qright);
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
        std::string s;
        std::cin >> s;
        if (s == "s") {
            int l = 0, r = 0;
            std::cin >> l >> r;
            std::cout << segTree.get_gcd(l, r + 1) << ' ';
        } else {
            int index = 0, value = 0;
            std::cin >> index >> value;
            segTree.add(index, value);
        }
    }
    return 0;
}