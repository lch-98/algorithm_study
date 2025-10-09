//PCCP 기출문제 2번
#include <string>
#include <vector>

using namespace std;

long long total_time(const vector<int>& diffs, const vector<int>& times, long long level) {
    long long total = 0;
    int n = diffs.size();

    for (int i = 0; i < n; i++) {
        if (diffs[i] <= level) {
            total += times[i];
        } else {
            // 틀리는 횟수 = diff - level
            long long miss = diffs[i] - level;
            long long prev_time = (i == 0) ? 0 : times[i - 1];  // 첫 퍼즐은 이전이 없음
            total += miss * (prev_time + times[i]) + times[i];
        }
        if (total > 1e15) return total;
    }
    return total;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int left = 1;
    int right = 100000; // 최대 난이도 범위
    int answer = right;

    while (left <= right) {
        int mid = (left + right) / 2;
        long long t = total_time(diffs, times, mid);

        if (t <= limit) {
            // 제한 시간 안에 해결 가능 → 더 낮은 level을 탐색
            answer = mid;
            right = mid - 1;
        } else {
            // 제한 시간 초과 → level을 높여야 함
            left = mid + 1;
        }
    }

    return answer;
}
