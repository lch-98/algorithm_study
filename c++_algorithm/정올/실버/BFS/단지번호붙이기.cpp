#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

vector<string> maze;
vector<vector<int>> visited;
int N;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

struct pos {
	int y; // 행
	int x; // 열
};

int bfs(pos start) {
	int cnt = 1;
	queue<pos> q;
	q.push(start);
	visited[start.y][start.x] = 1;

	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		q.pop();

		for (int dr = 0; dr < 4; dr++) {
			int ny = cy + dy[dr];
			int nx = cx + dx[dr];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (visited[ny][nx] == 1) continue;
			if (maze[ny][nx] == '0') continue;
			q.push({ ny, nx });
			visited[ny][nx] = 1;
			cnt += 1;
		}
	}
	return cnt;
}

int main() {
	cin >> N;
	visited = vector<vector<int>>(N, vector<int>(N, 0));

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		maze.push_back(str);
	}

	int ans = 0;
	int cnt = 0;
	vector<int> ans_arr;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (maze[row][col] == '0') continue;
			if (visited[row][col] == 1) continue;
			cnt = bfs({ row, col });
			ans_arr.push_back(cnt);
			ans++;
		}
	}

	cout << ans << "\n";
	sort(ans_arr.begin(), ans_arr.end());
	for (int i = 0; i < ans_arr.size(); i++) {
		cout << ans_arr[i] << "\n";
	}
	return 0;
}