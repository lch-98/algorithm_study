#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, T;
vector<vector<int>> maze;
vector<vector<int>> visited;
void init()
{
	maze = vector<vector<int>>(N, vector<int>(M, 0));
	visited = vector<vector<int>>(N, vector<int>(M, 15000));
}

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int sword_time = 0;
int bfs(int sy, int sx)
{
	queue<pair<int, int>> q;
	q.push({sy, sx});
	visited[sy][sx] = 0;
	
	while (!q.empty())
	{
		int curr_row = q.front().first;
		int curr_col = q.front().second;
		q.pop();

		for (int dr = 0; dr < 4; dr ++)
		{
			int ny = curr_row + dy[dr];
			int nx = curr_col + dx[dr];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

			if (maze[ny][nx] == 1) continue;
			if (visited[ny][nx] != 15000) continue;

			visited[ny][nx] = visited[curr_row][curr_col] + 1;
			q.push({ ny, nx });

		}	
	}
	return visited[N - 1][M - 1];
}

int main()
{
	cin >> N >> M >> T;
	init();
	int sword_y = 0, sword_x = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maze[i][j];
			if (maze[i][j] == 2) sword_y = i, sword_x = j;
		}
	}

	int time = bfs(0, 0);
	sword_time = visited[sword_y][sword_x] + abs(sword_y - (N - 1)) + abs(sword_x - (M - 1));
	
	int res = min(time, sword_time);
	if (res <= T)
	{
		cout << res;
	}
	else
	{
		cout << "Fail";
	}
}