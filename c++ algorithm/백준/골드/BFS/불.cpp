// 중요 만약에 visited를 -1로 초기화 하면 지훈이가 길을 가다가 작은 길 즉, 불이 없는 곳을 못 가게 됨
// 그 이유는 jdist < visited[nrow][ncol]로 되어있어서
// -1로 초기화 할거면 visited[nrow][ncol] == -1 || jdist < visited[nrow][ncol] 변경해줘야 함.
#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int R, C;
vector<string> maze;
vector<vector<int>> visited;
vector<vector<int>> jvisited;
int jrow, jcol;
vector<pair<int, int>> fire;

void init()
{
	maze = vector<string>(R);
	visited = vector<vector<int>>(R, vector<int>(C, 99999));
	jvisited = vector<vector<int>>(R, vector<int>(C, 99999));
	fire.clear();
}

void print()
{
	for (int i = 0; i < jvisited.size(); i++)
	{
		for (int j = 0; j < jvisited[i].size(); j++)
		{
			cout << jvisited[i][j] << " ";
		}
		cout << "\n";
	}
}

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
void fire_bfs()
{
	queue<pair<int, int>> q;
	for (int i = 0; i < fire.size(); i++)
	{
		q.push({ fire[i] });
		visited[fire[i].first][fire[i].second] = 0;
	}

	while (!q.empty())
	{
		int curr_row = q.front().first;
		int curr_col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nrow = curr_row + dy[i];
			int ncol = curr_col + dx[i];
			if (nrow < 0 || ncol < 0 || nrow >= R || ncol >= C) continue;
			if (maze[nrow][ncol] == '#') continue;
			if (visited[nrow][ncol] != 99999) continue;

			q.push({ nrow, ncol });
			visited[nrow][ncol] = visited[curr_row][curr_col] + 1;
		}
	}
}

int j_bfs()
{
	queue<pair<int, int>> q;

	q.push({jrow, jcol});
	jvisited[jrow][jcol] = 0;

	while (!q.empty())
	{
		int curr_row = q.front().first;
		int curr_col = q.front().second;
		q.pop();

		if (curr_row == 0 || curr_col == 0 || curr_row == R - 1 || curr_col == C - 1) {
			return jvisited[curr_row][curr_col]; // 탈출에 걸린 시간 반환
		}

		for (int i = 0; i < 4; i++)
		{
			int nrow = curr_row + dy[i];
			int ncol = curr_col + dx[i];
			if (nrow < 0 || ncol < 0 || nrow >= R || ncol >= C) continue;
			if (maze[nrow][ncol] == '#') continue;
			if (jvisited[nrow][ncol] != 99999) continue;

			int j_dist = jvisited[curr_row][curr_col] + 1;
			if (j_dist < visited[nrow][ncol])
			{
				q.push({ nrow, ncol });
				jvisited[nrow][ncol] = j_dist;
			}
		}
	}

	return -1;
}


int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	init();
	for (int i = 0; i < R; i++)
	{
		cin >> maze[i];
		for (int j = 0; j < C; j++)
		{
			if (maze[i][j] == 'J') jrow = i, jcol = j;
			else if (maze[i][j] == 'F') fire.push_back({ i,j });
		}
	}
	fire_bfs();
	int res = j_bfs();
	if (res == -1) cout << "IMPOSSIBLE";
	else if (res != -1) cout << res + 1;
}