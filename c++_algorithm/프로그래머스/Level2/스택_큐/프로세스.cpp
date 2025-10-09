#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> q; // (index, priority)
    priority_queue<int, vector<int>, less<int>> pq;  // 우선순위 최대값 추적용

    for (int i = 0; i < priorities.size(); ++i) {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }

    while (!q.empty()) {
        int idx = q.front().first;
        int priority = q.front().second;
        q.pop();

        if (priority < pq.top()) {
            // 더 높은 우선순위가 있음 → 다시 큐 뒤로
            q.push({idx, priority});
        } else {
            // 현재 가장 높은 우선순위 → 실행
            answer++;
            pq.pop();
            if (idx == location) return answer;
        }
    }

    return answer;
}
