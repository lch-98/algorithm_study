#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct pos {
	int y;
	int x;
	int cost;
};

int I;
int dy[] = { -1, 1, -2 , 2, -2, 2, -1, 1 };
int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };

int bfs(pair<int, int> start, pair<int, int> target) {
	if (start == target) return 0; // 시작과 끝이 같을 때

	vector<vector<int>> visited(I, vector<int>(I, 0));
	queue<pos> q;
	q.push({ start.first, start.second, 0 });
	visited[start.first][start.second] = 1;

	while (!q.empty()) {
		pos curr = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = curr.y + dy[i];
			int nx = curr.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= I || nx >= I) continue;
			if (visited[ny][nx]) continue;

			if (ny == target.first && nx == target.second)
				return curr.cost + 1;

			visited[ny][nx] = 1;
			q.push({ ny, nx, curr.cost + 1 });
		}
	}
	return -1; // 도달 못할 경우 (이론상 없지만 안전망)
}

int main() {
	int TC;
	cin >> TC;

	while (TC--) {
		cin >> I;

		int sy, sx;
		cin >> sy >> sx;

		int ty, tx;
		cin >> ty >> tx;

		int ans = bfs({ sy, sx }, { ty, tx });
		cout << ans << "\n";
	}
}