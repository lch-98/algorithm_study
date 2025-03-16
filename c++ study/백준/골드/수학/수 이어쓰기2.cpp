#include <iostream>
#include <string>
using namespace std;

int main() {
    long long N, k;
    cin >> N >> k;

    long long left = 1, digit = 1, count = 9;

    // 1. k번째 숫자가 속하는 자리수를 찾음
    while (k > digit * count) {
        k -= digit * count;
        digit++;
        count *= 10;
        left *= 10;
    }

    // 2. k번째 숫자가 위치한 숫자를 찾음
    long long number = left + (k - 1) / digit;

    // 만약 찾은 숫자가 N보다 크다면, k번째 숫자는 존재하지 않음
    if (number > N) {
        cout << -1 << endl;
        return 0;
    }

    // 3. 해당 숫자에서 k번째 자리에 해당하는 자리 구하기
    string numberStr = to_string(number);
    int idx = (k - 1) % digit;

    cout << numberStr[idx] << endl;

    return 0;
}
