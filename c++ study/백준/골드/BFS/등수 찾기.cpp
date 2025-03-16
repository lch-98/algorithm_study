#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, X;
vector<vector<int>> graph;        // 성적 비교 그래프
vector<vector<int>> reverseGraph; // 역방향 그래프
vector<int> visited;              // 방문 체크 배열

void init() {
	graph = vector<vector<int>>(N + 1);
	reverseGraph = vector<vector<int>>(N + 1);
	visited = vector<int>(N + 1, 0);
}

// BFS 또는 DFS로 그래프 탐색, 도달할 수 있는 노드 수를 반환
int countReachableNodes(const vector<vector<int>>& graph, int start_node) {
	queue<int> q;
	q.push(start_node);
	visited[start_node] = 1;
	int count = 0;

	while (!q.empty()) {
		int curr_node = q.front();
		q.pop();
		count++;

		for (int neighbor : graph[curr_node]) {
			if (visited[neighbor] == 0) {
				q.push(neighbor);
				visited[neighbor] = 1;
			}
		}
	}

	return count - 1; // 자기 자신 제외
}

int main() {
	cin >> N >> M >> X;
	init();

	// 그래프 입력 받기
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);         // a가 b보다 더 잘했음
		reverseGraph[b].push_back(a);   // b가 a보다 성적이 낮음 (역방향)
	}

	// X보다 성적이 낮은 학생 수 계산 (그래프에서 X가 도달할 수 있는 노드 수)
	fill(visited.begin(), visited.end(), 0);
	int lower_count = countReachableNodes(graph, X);

	// X보다 성적이 높은 학생 수 계산 (역방향 그래프에서 X가 도달할 수 있는 노드 수)
	fill(visited.begin(), visited.end(), 0);
	int higher_count = countReachableNodes(reverseGraph, X);

	// U는 X보다 성적이 낮은 학생 수 + 1, V는 X보다 성적이 높은 학생 수 + 1
	int U = higher_count + 1;
	int V = N - lower_count;

	cout << U << " " << V << endl;
	return 0;
}
