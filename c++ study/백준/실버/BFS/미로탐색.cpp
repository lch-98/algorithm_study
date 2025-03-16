#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, M;
vector<vector<int>> maze;
vector<vector<int>> visited;
struct pos
{
	int y, x;
};
void init()
{
	maze = vector<vector<int>>(N, vector<int>(M, 0));
	visited = vector<vector<int>>(N, vector<int>(M, -1));
}

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
void bfs(int ey, int ex)
{
	queue<pos> q;
	q.push({ 0,0 });
	visited[0][0] = maze[0][0];

	while (!q.empty())
	{
		int curr_row = q.front().y;
		int curr_col = q.front().x;
		q.pop();

		for (int dr = 0; dr < 4; dr++)
		{
			int ny = curr_row + dy[dr];
			int nx = curr_col + dx[dr];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (maze[ny][nx] == 0 || visited[ny][nx] != -1) continue;

			q.push({ ny, nx });
			visited[ny][nx] = visited[curr_row][curr_col] + maze[ny][nx];
		}
	}
}

int main()
{
	cin >> N >> M;
	init();

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			int num = stoi(str.substr(j,1));
			maze[i][j] = num;
		}
	}
	
	bfs(N-1, M-1);
	cout << visited[N - 1][M - 1];
}