#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>  // INT_MAX 사용을 위한 헤더

using namespace std;

vector<vector<pair<int, int>>> graph; // 그래프 정보 (인접 리스트)
vector<int> dist;  // 최단 거리 배열
int N, M;

void dijkstra(int start_node) {
	// 우선순위 큐 사용 (비용, 노드)
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start_node });  // 시작 노드 (비용 0)
	dist[start_node] = 0;      // 시작 노드까지의 비용은 0

	while (!pq.empty()) {
		int curr_cost = pq.top().first;  // 현재 비용
		int curr_node = pq.top().second; // 현재 노드
		pq.pop();

		// 현재 노드의 최단 비용이 더 크면 갱신할 필요가 없음
		if (curr_cost > dist[curr_node]) continue;

		// 현재 노드의 모든 인접 노드에 대해 최단 거리 갱신 시도
		for (auto neighbor : graph[curr_node]) {
			int next_node = neighbor.first;
			int next_cost = neighbor.second;

			// 새로운 경로가 더 짧다면 갱신
			if (dist[next_node] > curr_cost + next_cost) {
				dist[next_node] = curr_cost + next_cost;
				pq.push({ dist[next_node], next_node });  // 새로운 비용과 노드 추가
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;  // 도시의 개수
	graph.resize(N + 1);  // 도시 번호는 1부터 시작하므로 N+1 크기로 생성
	dist.resize(N + 1, INT_MAX);  // 초기 거리는 모두 무한대로 설정

	cin >> M;  // 버스의 개수
	for (int i = 0; i < M; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		graph[u].push_back({ v, cost });  // u에서 v로 가는 비용이 cost
	}

	int start_node, end_node;
	cin >> start_node >> end_node;

	// 다익스트라 실행 (시작 노드로부터)
	dijkstra(start_node);

	// 도착 노드까지의 최소 비용 출력
	cout << dist[end_node] << "\n";

	return 0;
}