#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> maze;
vector<vector<int>> visited;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int bfs(pair<int, int> curr) {
	queue<pair<int,int>> q;
	q.push(curr);
	visited[curr.first][curr.second] = 1;
	int cnt = 1;

	while (!q.empty()) {
		int curr_row = q.front().first;
		int curr_col = q.front().second;
		q.pop();

		for (int dr=0; dr<4; dr++) {
			int ny = curr_row + dy[dr];
			int nx = curr_col + dx[dr];
			if (ny < 0 || ny >= maze.size() || nx < 0 || nx >= maze[0].size()) continue;
			if (maze[ny][nx] == 1) continue;
			if (visited[ny][nx] == 1) continue;
			q.push({ ny,nx });
			cnt++;
			visited[ny][nx] = 1;
		}
	}
	return cnt;
}

void color(int ly, int lx, int ry, int rx) {
	for (int i = ly; i < ry; i++)
	{
		for (int j = lx; j < rx; j++)
		{
			maze[i][j] = 1;
		}
	}
}

int main() {
	int M, N, K; // ROW, COL, POSITION
	cin >> M >> N >> K;

	maze = vector<vector<int>>(M, vector<int>(N, 0));
	visited = vector<vector<int>>(M, vector<int>(N, 0));

	for (int i = 0; i < K; i++) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		color(ly, lx, ry, rx);
	}

	int answer = 0;
	vector<int> ans_arr;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (maze[i][j] == 0 && visited[i][j] == 0) {
				int ans = bfs({ i,j });
				ans_arr.push_back(ans);
				answer++;
			}
		}
	}
	cout << answer << "\n";
	sort(ans_arr.begin(), ans_arr.end());
	for (int i = 0; i < ans_arr.size(); i++)
	{
		cout << ans_arr[i] << " ";
	}
	return 0;
}