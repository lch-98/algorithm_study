#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> maze;
vector<vector<bool>> visited;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int bfs(int row, int col)
{
	int cnt_divide = 1;
	queue<pair<int, int>> q;
	q.push({ row, col });
	visited[row][col] = true;

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
			if (visited[ny][nx] == true) continue;
			if (maze[ny][nx] == 0) continue;

			q.push({ ny,nx });
			visited[ny][nx] = true;
			cnt_divide++;
		}
	}
	return cnt_divide;
}

int main()
{
	cin >> N;
	maze = vector<vector<int>>(N, vector<int>(N, 0));
	visited = vector<vector<bool>>(N, vector<bool>(N, false));

	vector<string> input(N);

	for (int i = 0; i < N; i++) {
		cin >> input[i];
		for (int j = 0; j < N; j++) {
			maze[i][j] = stoi(input[i].substr(j, 1)); 
		}
	}

	int cnt = 0; // 몇 개인지 카운트 하는 변수
	vector<int> ans_lst;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == false && maze[i][j] == 1)
			{
				int res = bfs(i, j);
				ans_lst.push_back(res);
				cnt++;
			}
		}
	}
	sort(ans_lst.begin(), ans_lst.end());
	
	cout << cnt << "\n";

	for (int i = 0; i < ans_lst.size(); i++)
	{
		cout << ans_lst[i] << "\n";
	}
}