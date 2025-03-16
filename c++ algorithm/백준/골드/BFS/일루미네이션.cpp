#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int W, H;
vector<vector<int>> maze;
vector<pair<int, int>> direction_oddRow = { {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {0,-1} };
vector<pair<int, int>> direction_evenRow = { {-1,-1}, {-1,0}, {0,1}, {1,0}, {1,-1}, {0,-1} };
void init()
{
	maze = vector<vector<int>>(H+2, vector<int>(W+2, 0));
}

void print()
{
	for (int i = 0; i < maze.size(); i++)
	{
		for (int j = 0; j < maze[i].size(); j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << "\n";
	}
}

// 홀수 행과 짝수 행을 다 확인하면 됨
int bfs(int sy, int sx)
{
	queue<pair<int, int>> q;
	q.push({ sy,sx });
	
	int cnt = 0;
	while (!q.empty())
	{
		int curr_row = q.front().first;
		int curr_col = q.front().second;
		q.pop();

		vector<pair<int, int>> directions = curr_row % 2 == 0 ? direction_evenRow : direction_oddRow;
		for (auto &direction : directions)
		{
			int ny = curr_row + direction.first;
			int nx = curr_col + direction.second;

			if (ny < 0 || nx < 0 || ny >= H + 2 || nx >= W + 2) continue;
			if (maze[ny][nx] == 0)
			{
				q.push({ ny,nx });
				maze[ny][nx] = 99; // 방문처리
			}
			else if (maze[ny][nx] == 1)
			{
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	// W가 열 H가 행
	cin >> W >> H;
	init();
	for (int i = 1; i < H+1; i++)
	{
		for (int j = 1; j < W+1; j++)
		{
			cin >> maze[i][j];
		}
	}

	cout << bfs(0,0);
}