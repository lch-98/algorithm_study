#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> maze;
int cnt;
void init() {
	maze = vector<vector<int>>(n, vector<int>(n, 0));
	cnt = 0;
}

// 0은 가로, 1은 세로, 2는 대각선인 상태
int dy[] = { 0, 1, 1 };
int dx[] = { 1, 0, 1 };
vector<vector<int>> chk = { {0, 2}, {1, 2}, {0, 1, 2} };
void dfs(pair<int, int> curr, int dr) {
	if (curr.first == n - 1 && curr.second == n - 1)
	{
		cnt++;
		return;
	}

	// 현재 방향에서 갈 수 있는 방향을 체크해서 갈 수 있으면 방향 최신화 및 다음 거리로 갈 수 있게 해줌
	for (auto i : chk[dr])
	{
		int ny = curr.first + dy[i];
		int nx = curr.second + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (maze[ny][nx] == 1) continue;

		if (i == 2 && (maze[ny - 1][nx] == 1 || maze[ny][nx - 1] == 1 || maze[ny - 1][nx - 1] == 1)) continue;

		dfs({ ny,nx }, i);
	}
}

int main() {
	// 행과 열의 번호는 1부터 시작한다.
	// 가장 처음에 파이프느 (1,1), (1,2)를 차지하고 있음
	cin >> n;
	init();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maze[i][j];
		}
	}
	dfs({ 0,1 }, 0);
	cout << cnt;
}