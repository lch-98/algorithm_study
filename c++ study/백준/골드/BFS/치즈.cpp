#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> maze;
vector<vector<int>> visited;
int cnt;
int cheese_cnt;
void init() {
	maze = vector<vector<int>>(n, vector<int>(m, 0));
	cnt = 0;
	cheese_cnt = 0;
}

void print() {
	for (int i = 0; i < maze.size(); i++)
	{
		for (int j = 0; j < maze[i].size(); j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << "\n";
	}
}

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
void bfs(pair<int,int> start) {
	visited = vector<vector<int>>(n, vector<int>(m, 0));
	queue<pair<int, int>> q;
	q.push(start);
	visited[start.first][start.second] = 1;

	while (!q.empty())
	{
		int curr_row = q.front().first;
		int curr_col = q.front().second;
		q.pop();

		for (int dr = 0; dr < 4; dr ++)
		{
			int ny = curr_row + dy[dr];
			int nx = curr_col + dx[dr];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx] != 0) continue;
			if (maze[ny][nx] == 0)
			{
				visited[ny][nx] = 1;
				q.push({ ny,nx });
			}
			if (maze[ny][nx] == 1) 
			{
				maze[ny][nx] = 9;	
			}
		}
	}
}

void simulate() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maze[i][j] == 9) maze[i][j] = 0;
		}
	}
}

int cnt_func() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maze[i][j] == 1)
			{
				cheese_cnt++;
			}
		}
	}
	return cheese_cnt;
}

int main() {
	cin >> n >> m;
	init();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> maze[i][j];
		}
	}

	int prev_cnt = 0;
	while (1)
	{
		if (cnt_func() != 0)
		{
			bfs({ 0,0 });
			simulate();
			cnt++;
			prev_cnt = cheese_cnt;
			cheese_cnt = 0;
		}
		else
		{
			cout << cnt << "\n";
			cout << prev_cnt;
			return 0;
		}
	}

}