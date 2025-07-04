#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long n = num;
    int answer = 0;

    while (answer < 500) {
        if (n == 1) break; 
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        answer++;
    }

    return (n == 1) ? answer : -1;
}
