#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
vector<vector<int>> graph;
vector<int> visited;
void init() {
	graph = vector<vector<int>>(N + 1);
	visited = vector<int>(N + 1);
}

int bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	int ans = 0;
	while (!q.empty()) {
		int curr_node = q.front();
		q.pop();

		for (auto neighbor : graph[curr_node])
		{
			if (visited[neighbor] == 1) continue;
			q.push(neighbor);
			visited[neighbor] = 1;
			ans++;
		}
	}
	return ans;
}

int main() {
	cin >> N >> K;
	init();
	
	for (int i = 0; i < K; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int res = bfs(1);
	cout << res;
}