#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int answer = -1;
int N, M;
vector<vector<int>> maze;
vector<pair<int, int>> start;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int bfs() {
	vector<vector<int>> visited(N, vector<int>(M, 0));
	queue<pair<int, int>> q;
	for (int i = 0; i < start.size(); i++) {
		q.push(start[i]);
		visited[start[i].first][start[i].second] = 3;
	}

	while (!q.empty()) {
		int curr_row = q.front().first;
		int curr_col = q.front().second;
		q.pop();

		for (int dr = 0; dr < 4; dr++) {
			int ny = curr_row + dy[dr];
			int nx = curr_col + dx[dr];
			if (ny < 0 || nx < 0 || ny >= maze.size() || nx >= maze[0].size()) continue;
			if (visited[ny][nx] != 0) continue;
			if (maze[ny][nx] != 0) continue;
			visited[ny][nx] = 3;
			q.push({ ny,nx });
		}
	}

	int safe_zone = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (maze[i][j] == 0 && visited[i][j] == 0)
				safe_zone++;
		}
	}
	return safe_zone;
}

void install_wall(int depth) {
	if (depth == 3) {
		answer = max(answer, bfs());
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (maze[i][j] == 1 || maze[i][j] == 2) continue;
			maze[i][j] = 1;
			install_wall(depth + 1);
			maze[i][j] = 0;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;

	maze = vector<vector<int>>(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 2) start.push_back({ i,j });
		}
	}

	install_wall(0);
	cout << answer << "\n";
	return 0;
}
