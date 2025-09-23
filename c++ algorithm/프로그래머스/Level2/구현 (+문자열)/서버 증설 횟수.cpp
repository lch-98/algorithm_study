// 2025 프로그래머스 코드챌린지 2차 예선
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> add(24 + k + 1, 0);
    int running = 0; // 현재 가동 중인 서버 수

    for (int t = 0; t < 24; t++) {
        // 1. 이번 시각에 반환되는 서버 반영
        running -= add[t];

        // 2. 이번 시각 필요한 서버 수 계산
        /* m=3일 때
        players[t] = 0,1,2 → 0/3=0, 1/3=0, 2/3=0 → 서버 0대
        players[t] = 3,4,5 → 3/3=1, 4/3=1, 5/3=1 → 서버 1대
        players[t] = 6,7,8 → 6/3=2, 7/3=2, 8/3=2 → 서버 2대
        즉, n×m 이상 (n+1)×m 미만이라는 조건이 → n대 필요하다는 말과 동일
        */
        int required = players[t] / m;

        // 3. 부족하다면 증설
        if (required > running) {
            int expansion = required - running;
            answer += expansion;
            running += expansion;

            // k 시간 뒤에 반환됨
            add[t + k] += expansion;
        }
    }
    return answer;
}
