#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<vector<int>> maze;

bool check_five_in_row(string line) {
	if (line.find("11111") != -1) 
	{
		if (line.find("111111") == -1) 
		{
			return true;
		}
	}
	if (line.find("22222") != -1)
	{
		if (line.find("222222") == -1)
		{
			return true;
		}
	}
	return false;
}

bool simulate(int last_row, int last_col)
{
	string vertical;
	for (int i = 0; i < 19; i++)
	{
		vertical += to_string(maze[i][last_col]);
	}
	if (check_five_in_row(vertical)) return true;

	string horizontal;
	for (int j = 0; j < 19; j++)
	{
		horizontal += to_string(maze[last_row][j]);
	}
	if (check_five_in_row(horizontal)) return true;

    // ↘
	string right_diagonal;
	for (int i = -18; i <= 18; i++) 
	{
		int r = last_row + i;
		int c = last_col + i;
		if (r >= 0 && r < 19 && c >= 0 && c < 19) 
		{
			right_diagonal += to_string(maze[r][c]);
		}
	}
	if (check_five_in_row(right_diagonal)) return true;

    // ↙
	string left_diagonal;
	for (int i = -18; i <= 18; i++)
	{
		int r = last_row + i;
		int c = last_col - i;
		if (r >= 0 && r < 19 && c >= 0 && c < 19) 
		{
			left_diagonal += to_string(maze[r][c]);
		}
	}
	if (check_five_in_row(left_diagonal)) return true;

	return false;
}

int main() {
	cin >> N;
	maze = vector<vector<int>>(19, vector<int>(19, 0));

	for (int i = 0; i < N; i++)
	{
		int row, col;
		cin >> row >> col;
		// 0,0을 시작점으로 했기 때문에
		row--;
		col--;
		// 홀수면 흑돌 1 짝수면 백돌 2
		maze[row][col] = (i % 2 == 0) ? 1 : 2;

		if (simulate(row, col))
		{
			cout << i + 1;
			return 0;
		}
	}
	cout << -1;
}