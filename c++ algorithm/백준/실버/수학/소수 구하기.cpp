#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool chk_prime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    int sqrt_num = static_cast<int>(sqrt(num));
    for (int i = 3; i <= sqrt_num; i += 2) { // 짝수는 건너뛰어서 불필요한 검사 제거
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int M, N;
    cin >> M >> N;
    for (int i = M; i <= N; i++) {
        if (chk_prime(i)) cout << i << "\n";
    }
    return 0;
}