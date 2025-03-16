#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;
vector<vector<int>> map_; // 배추밭을 나타내는 2D 배열
vector<vector<bool>> visited; // 방문 여부를 나타내는 2D 배열
int dx[] = { 0, 0, -1, 1 }; // 상하좌우 이동을 위한 배열
int dy[] = { -1, 1, 0, 0 }; // 상하좌우 이동을 위한 배열

//void print()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			cout << visited[i][j] << " ";
//		}
//		cout << "\n";
//	}
//}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
				if (visited[ny][nx] == false && map_[ny][nx] == 1) {
					q.push({ ny, nx });
					visited[ny][nx] = true;
				}
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> M >> N >> K;
		map_ = vector<vector<int>>(N, vector<int>(M, 0));
		visited = vector<vector<bool>>(N, vector<bool>(M, false));

		// 배추 위치 입력
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			map_[y][x] = 1;
		}

		int cnt = 0; // 필요한 지렁이 수

		// 배추밭을 순회하며 BFS로 군집 탐색
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map_[i][j] == 1 && visited[i][j] == false) {
					bfs(i, j);
					//print();
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
	}
	return 0;
}
