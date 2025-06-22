#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int A, B, N, M;
	cin >> A >> B >> N >> M;
    vector<int> visited(100001, 0);

    queue<int> q;
    q.push(N);
    visited[N] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == M) {
            cout << visited[curr] << "\n";
            return 0;
        }

        vector<int> nextMoves = {
            curr + 1, curr - 1,
            curr + A, curr - A,
            curr + B, curr - B,
            curr * A, curr * B
        };

        for (int next : nextMoves) {
            if (next < 0 || next > 100000) continue;
            if (visited[next] != 0 || next == N) continue; // 맨 처음간 곳도 다시 방문하면 안됨
            visited[next] = visited[curr] + 1;
            q.push(next);
        }
    }
}