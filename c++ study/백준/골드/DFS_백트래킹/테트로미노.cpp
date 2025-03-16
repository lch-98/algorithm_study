#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int max_sum = 0;
vector<vector<int>> maze;
vector<vector<int>> visited;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
// 보라색 모형 방향 만들어줌 4가지 경우
vector<vector<pair<int, int>>> directions =
{
	{{0, 1}, {0, 2}, {1, 1}},
	{{1, 0}, {1, -1}, {2, 0}},
	{{1, 0}, {1, 1}, {2, 0}},
	{{0, 1}, {0, 2}, {-1, 1}}
};
void except_case(pair<int, int> start, int sum)
{
	for (int i = 0; i < directions.size(); i++)
	{
		int first_sum = sum;
		for (auto &direction : directions[i])
		{
			int ny = start.first + direction.first;
			int nx = start.second + direction.second;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			first_sum += maze[ny][nx];
		}
		max_sum = max(max_sum, first_sum);
	}
}

void dfs(pair<int,int> start, int sum, int depth)
{
	if (depth == 4)
	{
		max_sum = max(max_sum, sum);
		return;
	}

	for (int dr = 0; dr < 4; dr++)
	{
		int ny = start.first + dy[dr];
		int nx = start.second + dx[dr];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (visited[ny][nx] == 1) continue;
		visited[ny][nx] = 1;
		dfs({ ny, nx }, maze[ny][nx] + sum, depth + 1);
		visited[ny][nx] = 0;
	}
}

int main()
{
	cin >> N >> M;
	maze = vector<vector<int>>(N, vector<int>(M, 0));
	visited = vector<vector<int>>(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maze[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = 1;
			dfs({i,j}, maze[i][j], 1);
			visited[i][j] = 0;
			except_case({i,j}, maze[i][j]);
		}
	}
	cout << max_sum;
}