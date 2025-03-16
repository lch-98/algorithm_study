#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

const int INF = 21e8; // 무한대를 의미하는 큰 수
int V, E;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int curr_dist = pq.top().first;
		int curr_node = pq.top().second;
		pq.pop();

		// 현재 노드까지의 최단 거리가 이미 더 크다면 무시
		if (curr_dist > dist[curr_node]) continue;

		for (auto& edge : graph[curr_node]) {
			int next_node = edge.first;
			int weight = edge.second;

			if (dist[next_node] > curr_dist + weight) {
				dist[next_node] = curr_dist + weight;
				pq.push({ dist[next_node], next_node });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E;
	int K;
	cin >> K;

	graph.resize(V + 1);
	dist.assign(V + 1, INF);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}

	return 0;
}
