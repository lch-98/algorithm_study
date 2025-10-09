// 다잌스트라 풀이
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
vector<vector<int>> graph;
vector<int> dist;

void dijkstra(int start_node) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start_node] = 0;
    pq.push({0, start_node});

    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        // 이미 더 짧은 거리로 방문된 경우 스킵
        if (curr_dist > dist[curr_node]) continue;

        for (int neighbor : graph[curr_node]) {
            if (dist[neighbor] > curr_dist + 1) {
                dist[neighbor] = curr_dist + 1;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, K, X;
    cin >> N >> M >> K >> X;

    graph = vector<vector<int>>(N + 1);
    dist = vector<int>(N + 1, INF);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    dijkstra(X);

    bool found = false;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == K) {
            cout << i << "\n";
            found = true;
        }
    }

    if (!found) cout << -1;
}


/*
// bfs 풀이
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> dist;

void bfs(int start_node) {
	queue<int> q;
	q.push(start_node);
	dist[start_node] = 0;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		
		for (int neighbor : graph[curr])
		{
			if (dist[neighbor] != -1) continue;
			dist[neighbor] = dist[curr] + 1;
			q.push(neighbor);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, K, X;
	cin >> N >> M >> K >> X;
	graph = vector<vector<int>>(N + 1); // 1부터 시작해서  + 1
	dist = vector<int>(N + 1, -1);
	// 도시의 개수, 도로의 개수, 최단 거리 정보, 출발 도시의 번호
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
	}
	bfs(X);

	// 출력 부분
	int flag = 0;
	for (int i = 1; i < dist.size(); i++)
	{
		if (dist[i] == K) {
			flag = 1;
			cout << i << "\n";
		}
	}
	if (flag == 0) cout << -1;
}
*/