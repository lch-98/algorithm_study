#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, M;
vector<string> maze;
vector<vector<int>> visited;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void visited_chk() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}

int bfs(pair<int,int> start, bool flag) {
	int cnt = 1; // 병사 수를 세는 변수
	queue<pair<int, int>> q;
	if (flag == true) visited[start.first][start.second] = 2;
	else visited[start.first][start.second] = 1;
	q.push(start);

	while (!q.empty()) {
		int curr_row = q.front().first;
		int curr_col = q.front().second;
		q.pop();

		for (int dr = 0; dr < 4; dr++) {
			int ny = curr_row + dy[dr];
			int nx = curr_col + dx[dr];
			if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
			if (visited[ny][nx] != 0) continue;

			if (flag == true && maze[ny][nx] == 'W') {
				visited[ny][nx] = 2;
				q.push({ ny, nx });
				cnt++;
			}
			else if (flag == false && maze[ny][nx] == 'B') {
				visited[ny][nx] = 1;
				q.push({ ny, nx });
				cnt++;
			}
		}
	}
	return cnt * cnt;
}

int main() {
	cin >> N >> M;
	maze = vector<string>(M);
	visited = vector<vector<int>>(M, vector<int>(N, 0));
	for (int i = 0; i < M; i++) {
		cin >> maze[i];
	}
	
	int White_nation = 0;
	int Blue_nation = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (maze[i][j] == 'W' && visited[i][j] == 0) {
				White_nation += bfs({i,j}, true);
			}
			else if (maze[i][j] == 'B' && visited[i][j] == 0) {
				Blue_nation += bfs({ i,j }, false);
			}
		}
	}
	//visited_chk();
	cout << White_nation << " " << Blue_nation << "\n";
	return 0;
}