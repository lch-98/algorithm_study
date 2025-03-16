#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k; // n은 미로 크기, k는 최대 공사 가능 깊이
vector<vector<int>> maze;
vector<vector<int>> visited;
vector<pair<int, int>> start_lst;
int max_height;
int ans;

void init() {
	maze = vector<vector<int>>(n, vector<int>(n, 0));
	visited = vector<vector<int>>(n, vector<int>(n, 0));
	start_lst.clear(); // 시작 점 리스트를 각 케이스마다 초기화 시켜줘야 함
	max_height = -1;
	ans = -1;
}

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void dfs(pair<int, int> curr, int move_cnt, bool cut_chk) {
	// 최장 경로 갱신
	ans = max(ans, move_cnt);

	for (int dr = 0; dr < 4; dr++) {
		int ny = curr.first + dy[dr];
		int nx = curr.second + dx[dr];

		// 범위 초과 및 방문 여부 확인
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (visited[ny][nx] != 0) continue;

		// 등산로 정상 전진
		if (maze[curr.first][curr.second] > maze[ny][nx]) {
			visited[ny][nx] = 1;
			dfs({ ny, nx }, move_cnt + 1, cut_chk);
			visited[ny][nx] = 0;
		}

		// 등산로를 깎고 전진
		else if (!cut_chk && maze[curr.first][curr.second] > maze[ny][nx] - k) {
			int original_height = maze[ny][nx]; // 현재 높이 저장
			maze[ny][nx] = maze[curr.first][curr.second] - 1; // 깎기 + 최소한으로 즉, -1 만큼만 깍아야 다음으로 갈 때 갈 수 있는 선택지가 많아짐
			// ex) -k만큼 파버리면 10일 때 k=2라면 8이 되는데 다음칸이 다 8이라면 가지 못하는 경우가 생겨버림
			// 하지만 -1만큼 한다면 9가 되어서 다음 한 칸을 더 갈 수 있게된다.

			visited[ny][nx] = 1;
			dfs({ ny, nx }, move_cnt + 1, true);
			visited[ny][nx] = 0;

			maze[ny][nx] = original_height; // 원상 복구
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> k;
		init();

		// 지도와 최고 높이 계산
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> maze[i][j];
				max_height = max(max_height, maze[i][j]);
			}
		}

		// 최고 높이 봉우리 위치 저장
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (maze[i][j] == max_height) {
					start_lst.push_back({ i, j });
				}
			}
		}

		// 각 최고 높이 봉우리에서 DFS 탐색 시작
		for (auto start : start_lst) {
			visited = vector<vector<int>>(n, vector<int>(n, 0)); // 방문 초기화
			visited[start.first][start.second] = 1;
			dfs(start, 1, false); // 시작 카운트를 1로 설정
		}

		cout << "#" << tc << " " << ans << "\n";
	}
}
