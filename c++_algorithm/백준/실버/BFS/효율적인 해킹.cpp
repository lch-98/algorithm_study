#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> result;
int N, M;

int bfs(int start_node) {
    queue<int> q;
    q.push(start_node);
    visited[start_node] = 1;
    int count = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto next : graph[curr]) {
            if (visited[next]) continue;
            visited[next] = 1;
            q.push(next);
            count++;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    int max_hack = 0;
    result.resize(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        visited.assign(N + 1, 0);
        int cnt = bfs(i);
        result[i] = cnt;
        max_hack = max(max_hack, cnt);
    }

    for (int i = 1; i <= N; i++) {
        if (result[i] == max_hack) cout << i << " ";
    }
    cout << "\n";

    return 0;
}
