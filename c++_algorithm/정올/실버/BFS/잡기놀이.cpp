#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
vector<int> visited(100001, -1);

int bfs(int start, int end) {
    queue<int> q;

    q.push(start);
    visited[start] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == end)
            return visited[curr];

        int nexts[3] = {
            curr - 1,
            curr + 1,
            curr * 2
        };

        for (int i = 0; i < 3; i++) {
            int next = nexts[i];

            if (next < 0 || next > 100000)
                continue;

            if (visited[next] != -1)
                continue;

            visited[next] = visited[curr] + 1;
            q.push(next);
        }
    }

    return -1;
}

int main() {
    cin >> N >> K;

    cout << bfs(N, K);

    return 0;
}