#include <string>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>>& computers, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (int i = 0; i < computers.size(); i++) {
            if (computers[current][i] == 1 && visited[i] != 1) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i, computers, visited);
            answer++;
        }
    }

    return answer;
}