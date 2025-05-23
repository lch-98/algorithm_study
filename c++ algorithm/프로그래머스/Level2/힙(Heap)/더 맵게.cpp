#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    int answer = 0;

    while (pq.size() >= 2 && pq.top() < K) {
        int first = pq.top();
        pq.pop();
        
        int second = pq.top();
        pq.pop();
        
        int new_food = first + (second * 2);
        
        pq.push(new_food);
        answer++;
    }

    if (pq.top() < K) return -1;
    return answer;
}
