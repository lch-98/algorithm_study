#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long left = 1, right = n;
    while (left <= right) {
        long long mid = (left + right) / 2; // left + (right + left) / 2; 오버플로우 방지 표현

        if (mid > n / mid) right = mid - 1;
        else if (mid < n / mid) left = mid + 1;
        else {
            // mid == n / mid 라도 mid * mid == n 인지 꼭 확인!
            if (mid * mid == n) return (mid + 1) * (mid + 1);
            else return -1;
        }
    }
    return -1;
}
/*
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long square = mid * mid;

        if (square == n) return (mid + 1) * (mid + 1);
        else if (square < n) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
*/