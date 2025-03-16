#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<bool> visited;
bool found = false; // 깊이 4인 경로 찾은 경우에 break를 걸기 위한 변수

void dfs(int node, int depth) {
    if (depth == 4) {  // 깊이가 4인 경로를 찾은 경우
        found = true;
        return;
    }

    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (visited[neighbor] == false) {
            dfs(neighbor, depth + 1);
            if (found == true) return;  // 경로를 찾은 경우 더 이상 탐색하지 않음
        }
    }

    visited[node] = false;  // 원복
}

int main() {
    cin >> N >> M;
    graph.resize(N);
    visited.resize(N, false);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        dfs(i, 0);
        if (found == true) break;
    }

    if (found == true) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
