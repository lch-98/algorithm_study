#include <string>
#include <vector>

using namespace std;

int divisor_chk(int num) {
    int cnt = 0;
    for (int i=1; i<=num; i++) {
        if (num % i == 0) { cnt++; }
    }
    if (cnt % 2 == 0) { return num; }
    else {return (-1 * num);}
}

int solution(int left, int right) {
    int answer = 0;
    for (int i=left; i<=right; i++) {
        answer += divisor_chk(i);
    }
    return answer;
}