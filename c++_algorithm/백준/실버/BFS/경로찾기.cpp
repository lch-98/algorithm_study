#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> graph;
vector<vector<int>> visited;

void init() {
	graph = vector<vector<int>>(N);
	visited = vector<vector<int>>(N, vector<int>(N, 0));
}

void bfs(int start) {
	queue<int> q;
	vector<int> localVisited(N, 0);

	q.push(start);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (auto neighbor : graph[curr]) {
			if (localVisited[neighbor]) continue;
			localVisited[neighbor] = 1;
			q.push(neighbor);
		}
	}

	for (int j = 0; j < N; j++)
		visited[start][j] = localVisited[j];
}

int main() {
	cin >> N;
	init();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			if (num == 1) {
				graph[i].push_back(j); // 단방향
			}
		}
	}

	for (int i = 0; i < N; i++)
		bfs(i);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << visited[i][j] << " ";
		cout << "\n";
	}
}
