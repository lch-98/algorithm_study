#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> maze;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

// 안전 영역을 찾기 위한 BFS 함수
void bfs(int y, int x, vector<vector<bool>>& visited, int height) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty()) {
		int curr_y = q.front().first;
		int curr_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = curr_y + dy[i];
			int nx = curr_x + dx[i];

			// 범위를 벗어나거나 이미 방문했거나 물에 잠긴 지역이면 건너뜀
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (visited[ny][nx] || maze[ny][nx] <= height) continue;

			visited[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
}

int main() {
	cin >> N;

	maze = vector<vector<int>>(N, vector<int>(N));
	int max_height = 0;

	// 입력받기 및 최대 높이 찾기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> maze[i][j];
			max_height = max(max_height, maze[i][j]);
		}
	}

	int max_safe_areas = 0;

	// 높이 0부터 최대 높이까지 물에 잠기는 경우를 시뮬레이션
	for (int height = 0; height <= max_height; height++) {
		vector<vector<bool>> visited(N, vector<bool>(N, false));
		int safe_areas = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// 물에 잠기지 않았고 방문하지 않은 지역이면 BFS 수행
				if (maze[i][j] > height && !visited[i][j]) {
					bfs(i, j, visited, height);
					safe_areas++;
				}
			}
		}

		// 최대 안전 영역 개수 갱신
		max_safe_areas = max(max_safe_areas, safe_areas);
	}

	cout << max_safe_areas << endl;

	return 0;
}
