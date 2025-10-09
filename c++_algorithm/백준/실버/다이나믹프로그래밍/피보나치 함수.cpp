#include <iostream>
#include <cstring>
using namespace std;

pair<int, int> memo[41];  // memo[n] = {0이 출력되는 횟수, 1이 출력되는 횟수}

pair<int, int> fibonacci(int n) {
    if (memo[n].first != -1) return memo[n];  // 이미 계산된 경우 반환

    if (n == 0) {
        return memo[0] = { 1, 0 };
    }
    else if (n == 1) {
        return memo[1] = { 0, 1 };
    }
    else {
        pair<int, int> a = fibonacci(n - 1);
        pair<int, int> b = fibonacci(n - 2);
        return memo[n] = { a.first + b.first, a.second + b.second };
    }
}

int main() {
    int T;
    cin >> T;

    // 메모 배열 초기화
    for (int i = 0; i <= 40; i++) {
        memo[i] = { -1, -1 };
    }

    while (T--) {
        int num;
        cin >> num;

        pair<int, int> result = fibonacci(num);
        cout << result.first << " " << result.second << "\n";
    }

    return 0;
}