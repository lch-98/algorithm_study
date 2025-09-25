#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> maze;
vector<vector<int>> visited;
void print() {
	for (int i = 0; i < maze.size(); i++) {
		for (int j = 0; j < maze[0].size(); j++) {
			if (maze[i][j] == 0) cout << 0 << " ";
			else cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
void bfs(pair<int,int> start_idx) {
	queue<pair<int, int>> q;
	q.push(start_idx);
	visited[start_idx.first][start_idx.second] = 0;

	while (!q.empty()) {
		int curr_dy = q.front().first;
		int curr_dx = q.front().second;
		q.pop();

		for (int dr = 0; dr < 4; dr++) {
			int ny = curr_dy + dy[dr];
			int nx = curr_dx + dx[dr];
			if (ny < 0 || nx < 0 || ny >= maze.size() || nx >= maze[0].size()) continue;
			if (maze[ny][nx] != 1) continue;
			if (visited[ny][nx] != -1) continue;
			visited[ny][nx] = visited[curr_dy][curr_dx] + 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	maze = vector<vector<int>>(n, vector<int>(m, 0));
	visited = vector<vector<int>>(n, vector<int>(m, -1));
	pair<int, int > start_idx = { 0,0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)	{
			cin >> maze[i][j];
			if (maze[i][j] == 2) start_idx = { i,j };
		}
	}
	bfs(start_idx);
	print();
	return 0;
}