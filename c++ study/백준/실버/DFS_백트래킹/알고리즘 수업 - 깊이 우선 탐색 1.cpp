#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, R;
vector<vector<int>> graph;
vector<int> visited;
int visit_order = 1; // 방문 순서를 기록할 카운터

// DFS 함수
void dfs(int curr_node) {
	visited[curr_node] = visit_order++; // 방문 순서를 기록

	// 인접 노드를 순회하면서 DFS
	for (int neighbor : graph[curr_node]) {
		if (visited[neighbor] == 0) {  // 방문하지 않은 노드만 탐색
			dfs(neighbor);
		}
	}
}

int main() {
	cin >> N >> M >> R;
	graph = vector<vector<int>>(N + 1); // 정점의 개수는 N, 정점 번호는 1부터 시작
	visited = vector<int>(N + 1, 0); // 방문 순서를 기록할 배열, 0으로 초기화

	// 간선 입력
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// 인접 리스트를 오름차순으로 정렬 (작은 번호부터 방문하기 위해)
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	// DFS 시작
	dfs(R);

	// 각 정점의 방문 순서 출력 (방문하지 않은 정점은 0)
	for (int i = 1; i <= N; i++) {
		cout << visited[i] << "\n";
	}

	return 0;
}
