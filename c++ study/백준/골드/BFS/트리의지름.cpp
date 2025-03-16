#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V;
vector<vector<pair<int, int>>> graph;  // 2차원 벡터 (노드, 거리)
vector<int> visited;

pair<int, int> bfs(int start) {
	visited = vector<int>(V + 1, -1);  // 방문 벡터 초기화
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	visited[start] = 0;

	int maxDist = 0;
	int maxNode = start;

	while (!q.empty()) {
		int node = q.front().first;
		int dist = q.front().second;
		q.pop();

		for (auto& neighbor : graph[node]) {
			int nextNode = neighbor.first;
			int nextDist = dist + neighbor.second;

			if (visited[nextNode] == -1) {
				visited[nextNode] = nextDist;
				q.push({ nextNode, nextDist });

				if (nextDist > maxDist) {
					maxDist = nextDist;
					maxNode = nextNode;
				}
			}
		}
	}

	return { maxNode, maxDist };
}

int main() {
	cin >> V;

	graph = vector<vector<pair<int, int>>>(V + 1);  // 그래프 초기화

	for (int i = 1; i <= V; i++) {
		int u;
		cin >> u;

		while (true) {
			int v, cost;
			cin >> v;
			if (v == -1)
				break;
			cin >> cost;
			graph[u].push_back({ v, cost });
		}
	}

	// 1. 임의의 점(1번 노드)에서 가장 먼 점을 찾음
	pair<int, int> first = bfs(1);

	// 2. 첫 번째 BFS에서 얻은 점에서 다시 BFS하여 트리의 지름을 찾음
	pair<int, int> result = bfs(first.first);

	cout << result.second << "\n";  // 트리의 지름 출력

	return 0;
}
