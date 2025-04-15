#include <vector>
using namespace std;

int answer = 0;

void dfs(const vector<int>& numbers, int depth, int sum, int target) {
    if (depth == numbers.size()) {
        if (sum == target) answer++;
        return;
    }

    // 두 가지 경우: + 또는 -
    dfs(numbers, depth + 1, sum + numbers[depth], target);
    dfs(numbers, depth + 1, sum - numbers[depth], target);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    dfs(numbers, 0, 0, target);
    return answer;
}

/* bfs
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<pair<int, int>> q;

    // 시작점: 합 0, 인덱스 0부터 시작
    q.push({0, 0});

    while (!q.empty()) {
        int sum = q.front().first;
        int idx = q.front().second;
        q.pop();

        // 모든 숫자를 다 사용했을 때
        if (idx == numbers.size()) {
            if (sum == target) answer++;
        } else {
            // 다음 숫자를 더하거나 빼서 큐에 넣기
            q.push({sum + numbers[idx], idx + 1});
            q.push({sum - numbers[idx], idx + 1});
        }
    }

    return answer;
}
*/