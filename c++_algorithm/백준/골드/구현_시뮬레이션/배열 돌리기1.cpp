#include <iostream>
#include <vector>
using namespace std;

int N, M, R;
vector<vector<int>> maze;
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

int main() {
	cin >> N >> M >> R;
	maze = vector<vector<int>>(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maze[i][j];
		}
	}

	for (int i = 0; i < R; i++)
	{
		int sy = 0; // 첫 행 시작
		int sx = 0; // 첫 열 시작
		int ey = N - 1; // 끝 행
		int ex = M - 1; // 끝 열
		// 반시계 방향
		while (sy < ey && sx < ex)
		{
			int prev = maze[sy][sx];

			// 위쪽 행 (오른쪽에서 왼쪽으로 이동)
			for (int i = sx; i < ex; i++) maze[sy][i] = maze[sy][i + 1];

			// 오른쪽 열 (아래에서 위로 이동)
			for (int i = sy; i < ey; i++) maze[i][ex] = maze[i + 1][ex];

			// 아래쪽 행 (왼쪽에서 오른쪽으로 이동)
			for (int i = ex; i > sx; i--) maze[ey][i] = maze[ey][i - 1];

			// 왼쪽 열 (위에서 아래로 이동)
			for (int i = ey; i > sy; i--) maze[i][sx] = maze[i - 1][sx];

			// 마지막 남은 자리에 이전에 저장한 값을 넣어줌
			maze[sy + 1][sx] = prev;

			sy++;
			sx++;
			ey--;
			ex--;
		}
	}
	print();
}