#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> graph;
vector<int> parent;  // 부모 노드를 저장할 벡터
vector<int> visited;

void bfs(int start_node) {
	queue<int> q;
	q.push(start_node);
	visited[start_node] = 1;

	while (!q.empty()) {
		int curr_node = q.front();
		q.pop();

		for (int neighbor : graph[curr_node]) {
			if (visited[neighbor] == 1) continue;
			q.push(neighbor);
			visited[neighbor] = 1;
			parent[neighbor] = curr_node;  // neighbor의 부모는 curr_node
		}
	}
}

int main() {
	cin >> N;
	graph = vector<vector<int>>(N + 1);
	parent = vector<int>(N + 1);  // 각 노드의 부모를 저장하는 배열
	visited = vector<int>(N + 1, 0);

	// 트리의 간선 정보를 입력받음
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);  // 양방향 연결
	}

	bfs(1);  // 루트 노드 1에서 BFS 탐색 시작

	// 2번 노드부터 N번 노드까지의 부모 노드를 출력
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}

	return 0;
}
