#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int cnt = 0;
int N;
vector<string> maze;
vector<vector<bool>> visited;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

void bfs(pair<int,int> start)
{
	queue<pair<int, int>> q;
	q.push(start);
	visited[start.first][start.second] = true;

	while (!q.empty())
	{
		int curr_row = q.front().first;
		int curr_col = q.front().second;
		q.pop();

		for (int dr = 0; dr < 4; dr++)
		{
			int ny = curr_row + dy[dr];
			int nx = curr_col + dx[dr];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (maze[ny][nx] != maze[start.first][start.second]) continue;
			if (visited[ny][nx] == true) continue;
			q.push({ny,nx});
			visited[ny][nx] = true;
		}
	}
	cnt++;
}

int main()
{
	// 빨간색과 초록색의 차이를 거의 느끼지 못함
	cin >> N;
	maze = vector<string> (N);
	visited = vector<vector<bool>> (N, vector<bool>(N, false));

	for (int i = 0; i < N; i++)
	{
		cin >> maze[i];
	}
	
	// 적록 색맹이 아닌사람이 본 구역
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == true) continue;

			if (maze[i][j] == 'R') { bfs({ i,j }); }
			else if (maze[i][j] == 'B') { bfs({ i,j }); }
			else if (maze[i][j] == 'G') { bfs({ i,j });  }
		}
	}
	cout << cnt;
	
	cnt = 0; // 초기화 한 번 진행하고 출력
	visited = vector<vector<bool>>(N, vector<bool>(N, false)); // visited도 다시 한 번 초기화 시켜줘야 함
	// 적록 색맹이 본 사람이 본 구역
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (maze[i][j] == 'G') maze[i][j] = 'R';
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == true) continue;

			if (maze[i][j] == 'R') { bfs({ i,j }); }
			else if (maze[i][j] == 'B') { bfs({ i,j }); }
			else if (maze[i][j] == 'G') { bfs({ i,j }); }
		}
	}
	cout << " " << cnt;
}