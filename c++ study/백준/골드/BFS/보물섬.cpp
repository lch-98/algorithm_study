#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<string> maze;
vector<vector<int>> visited;
int cnt;
void init() {
	maze = vector<string> (N);
	visited = vector<vector<int>>(N, vector<int>(M, -1));
	cnt = 0;
}

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
void bfs(pair<int,int> start) {
	queue<pair<int, int>> q;
	visited[start.first][start.second] = 0;
	q.push(start);
	int curr_cnt = 0;
	// 보물은 서로 간에 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는
	// 육지 두 곳에 나뉘어 묻혀있음
	while (!q.empty())
	{
		int curr_row = q.front().first;
		int curr_col = q.front().second;
		q.pop();

		for (int dr = 0; dr < 4; dr++)
		{
			int ny = curr_row + dy[dr];
			int nx = curr_col + dx[dr];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (maze[ny][nx] != 'L') continue;
			if (visited[ny][nx] != -1) continue;

			visited[ny][nx] = visited[curr_row][curr_col] + 1;
			curr_cnt = max(curr_cnt, visited[ny][nx]);
			q.push({ ny,nx });
		}
	}
	
	cnt = max(cnt, curr_cnt);
}

int main() {
	cin >> N >> M;
	init();

	// 육지 L, 바다 W
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> maze[i];
	}

	for (int i = 0; i < maze.size(); i++)
	{
		for (int j = 0; j < maze[i].size(); j++)
		{
			if (maze[i][j] == 'L')
			{
				bfs({i,j});
				visited = vector<vector<int>>(N, vector<int>(M, -1));
			}
		}
	}

	cout << cnt;
}