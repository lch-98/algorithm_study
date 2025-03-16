#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> maze;
vector<vector<int>> visited;
void init()
{
	maze = vector<vector<int>>(N, vector<int>(N, 0));
	visited = vector<vector<int>>(N, vector<int>(N, 9999));
}

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
int bfs(int sy, int sx)
{
	queue<pair<int, int>> q;
	q.push({ sy,sx });
	visited[sy][sx] = maze[sy][sx];

	while (!q.empty())
	{
		int curr_row = q.front().first;
		int curr_col = q.front().second;
		q.pop();
		
		for (int dr = 0; dr < 4; dr++)
		{
			int ny = curr_row + dy[dr];
			int nx = curr_col + dx[dr];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

			int dist = visited[curr_row][curr_col] + maze[ny][nx];
			if (visited[ny][nx] > dist)
			{
				q.push({ ny,nx });
				visited[ny][nx] = dist;
			}
		}
	}
	return visited[N - 1][N - 1];
}

int main()
{
	int tc = 1;
	while(true)
	{
		cin >> N;
		if (N == 0) break;
		init();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> maze[i][j];
			}
		}
		int res = bfs(0, 0);
		cout << "Problem " << tc << ":" << " " << res << "\n";
		tc++;
		
	}
}
