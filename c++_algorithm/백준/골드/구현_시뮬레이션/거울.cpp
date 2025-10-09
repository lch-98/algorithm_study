#include <vector>
#include <iostream>
using namespace std;

int N, M;
vector<vector<int>> mirror;
vector<pair<int, int>> left_;
vector<pair<int, int>> bottom_;
vector<pair<int, int>> right_;
vector<pair<int, int>> top_;
void init()
{
	mirror = vector<vector<int>>(N+2, vector<int>(M+2, -1));
}

void print()
{
	for (int i = 0; i < N + 2; i++)
	{
		for (int j = 0; j < M + 2; j++)
		{
			cout << mirror[i][j] << " ";
		}
		cout << "\n";
	}
}

void numbering()
{
	// 넘버링 하는 곳
	int cnt = 1;
	for (int row = 1; row < N + 1; row++)
	{
		mirror[row][0] = cnt;
		cnt++;
		left_.push_back({row, 0});
	}
	
	for (int col = 1; col < M + 1; col++)
	{
		mirror[N+1][col] = cnt;
		cnt++;
		bottom_.push_back({N+1, col});
	}

	for (int row = N; row >= 1; row--)
	{
		mirror[row][M+1] = cnt;
		cnt++;
		right_.push_back({row, M+1});
	}

	for (int col = M; col >= 1; col--)
	{
		mirror[0][col] = cnt;
		cnt++;
		top_.push_back({0, col});
	}
}


int direction(int dr)
{
	if (dr == 0) return 1;
	if (dr == 1) return 0;
	if (dr == 2) return 3;
	if (dr == 3) return 2;
}

int dy[] = { 0,-1,0,1 };
int dx[] = { 1,0,-1,0 };
void left_simulate(pair<int,int> laser)
{
	int sy = laser.first;
	int sx = laser.second;
	int dr = 0;

	while (true)
	{
		int ny = sy + dy[dr];
		int nx = sx + dx[dr];

		// 범위를 벗어나면 바로 break;
		// 범위는 1,1 -> 1+N, 1+M
		if (mirror[ny][nx] == 1)
		{
			dr = direction(dr);
		}

		if (nx == 0 || ny == 0 || ny > N || nx > M)
		{
			cout << mirror[ny][nx] << " ";
			break;
		}
		sy = ny;
		sx = nx;
	}
}

void bottom_simulate(pair<int, int> laser)
{
	int sy = laser.first;
	int sx = laser.second;
	int dr = 1;

	while (true)
	{
		int ny = sy + dy[dr];
		int nx = sx + dx[dr];

		// 범위를 벗어나면 바로 break;
		// 범위는 1,1 -> 1+N, 1+M
		if (mirror[ny][nx] == 1)
		{
			dr = direction(dr);
		}

		if (nx == 0 || ny == 0 || ny > N || nx > M)
		{
			cout << mirror[ny][nx] << " ";
			break;
		}
		sy = ny;
		sx = nx;
	}
}

void right_simulate(pair<int, int> laser)
{
	int sy = laser.first;
	int sx = laser.second;
	int dr = 2;

	while (true)
	{
		int ny = sy + dy[dr];
		int nx = sx + dx[dr];

		// 범위를 벗어나면 바로 break;
		// 범위는 1,1 -> 1+N, 1+M
		if (mirror[ny][nx] == 1)
		{
			dr = direction(dr);
		}

		if (nx == 0 || ny == 0 || ny > N || nx > M)
		{
			cout << mirror[ny][nx] << " ";
			break;
		}
		sy = ny;
		sx = nx;
	}
}

void top_simulate(pair<int, int> laser)
{
	int sy = laser.first;
	int sx = laser.second;
	int dr = 3;

	while (true)
	{
		int ny = sy + dy[dr];
		int nx = sx + dx[dr];

		// 범위를 벗어나면 바로 break;
		// 범위는 1,1 -> 1+N, 1+M
		if (mirror[ny][nx] == 1)
		{
			dr = direction(dr);
		}

		if (nx == 0 || ny == 0 || ny > N || nx > M)
		{
			cout << mirror[ny][nx] << " ";
			break;
		}

		sy = ny;
		sx = nx;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	init();

	for (int i = 1; i < N+1; i++)
	{
		for (int j = 1; j < M+1; j++)
		{
			cin >> mirror[i][j];
		}
	}
	numbering();
	//print();
	for (int i = 0; i < left_.size(); i++)
	{
		left_simulate(left_[i]);
	}

	for (int i = 0; i < bottom_.size(); i++)
	{
		bottom_simulate(bottom_[i]);
	}

	for (int i = 0; i < right_.size(); i++)
	{
		right_simulate(right_[i]);
	}

	for (int i = 0; i < top_.size(); i++)
	{
		top_simulate(top_[i]);
	}
}