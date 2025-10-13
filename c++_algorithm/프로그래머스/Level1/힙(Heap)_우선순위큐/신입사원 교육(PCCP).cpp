//PCCP 모의고사 2회 2번
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> ability, int number) {
    priority_queue<int, vector<int>, greater<int>> pq(ability.begin(), ability.end());
    for (int i = 0; i < number; i++) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int sum = a + b;
        pq.push(sum);
        pq.push(sum);
    }
    int answer = 0;
    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }
    return answer;
}