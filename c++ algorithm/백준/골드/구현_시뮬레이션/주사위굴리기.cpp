#include <iostream>
#include <vector>
using namespace std;

int N, M;
int x, y, K;
int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0;
vector<vector<int>> maze;
int dy[] = { 0, 0, 0, -1, 1 };  // 동, 서, 북, 남
int dx[] = { 0, 1, -1, 0, 0 };

void simulate(int dr)
{
    // d1이 바닥 d6가 윗면
	int temp_d1 = d1, temp_d2 = d2, temp_d3 = d3, temp_d4 = d4, temp_d5 = d5, temp_d6 = d6;
	if (dr == 1) // 동쪽으로 굴리기
	{
		d1 = temp_d3;
		d4 = temp_d1;
		d6 = temp_d4;
		d3 = temp_d6;
	}
	else if (dr == 2) // 서쪽으로 굴리기
	{
		d1 = temp_d4;
		d3 = temp_d1;
		d6 = temp_d3;
		d4 = temp_d6;
	}
	else if (dr == 3) // 북쪽으로 굴리기
	{
		d1 = temp_d2;
		d5 = temp_d1;
		d6 = temp_d5;
		d2 = temp_d6;
	}
	else if (dr == 4) // 남쪽으로 굴리기
	{
		d1 = temp_d5;
		d2 = temp_d1;
		d6 = temp_d2;
		d5 = temp_d6;
	}

	// 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다. 
	// 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
	if (maze[x][y] == 0)
	{
		maze[x][y] = d1;
	}
	else
	{
		d1 = maze[x][y];
		maze[x][y] = 0;
	}

	cout << d6 << '\n';
}

int main()
{
	cin >> N >> M;
	maze = vector<vector<int>>(N, vector<int>(M, 0));
	cin >> x >> y >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maze[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		int dr;
		cin >> dr;
		//!!!! 조심 여기서 주어지는 x값이 row이고 y값이 col임
		int ny = x + dy[dr];
		int nx = y + dx[dr];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		x = ny;
		y = nx;

		simulate(dr);
	}
	return 0;
}
