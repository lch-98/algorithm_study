// 약수 관련 문제
#include <cmath>
int solution(int number, int limit, int power) {
    int answer = 0;
    for (int i=1; i<=number; i++) {
        int cnt = 0;
        int root = (int)sqrt(i);
        for (int j=1; j<=root; j++) {
            if (i % j == 0) {
                if (j * j == i) cnt++;
                else cnt += 2;
            }
        }
        if (cnt > limit) cnt = power;
        answer += cnt;
    }
    return answer;
}
