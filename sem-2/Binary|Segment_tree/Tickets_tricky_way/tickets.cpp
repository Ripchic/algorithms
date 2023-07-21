#include <iostream>
#include <array>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N = 0, K = 0, M = 0;
    std::cin >> N >> K >> M;
    static std::array<int, 200000> a;
    a.fill(K);
    for (int i = 0; i < M; ++i) {
        int l = 0, r = 0;
        std::cin >> l >> r;
        bool seat_check = false;
        for (int j = l; j < r; ++j) {
            if (a[j] == 0) {
                seat_check = true;
                break;
            }
        }
        if (seat_check) {
            std::cout << 0 << '\n';
        } else {
            std::cout << 1 << '\n';
            for (int j = l; j < r; ++j) {
                --a[j];
            }
        }
    }
    return 0;
}