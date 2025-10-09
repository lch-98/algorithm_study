#include <iostream>
#include <vector>
using namespace std;

int H, W;
vector<vector<int>> maze;
void init()
{
	maze = vector<vector<int>>(H, vector<int>(W, 0));
}

int simulate()
{
	int sum = 0;
	vector<vector<int>> row_onelst(H);
	for (int row = 0; row < maze.size(); row++)
	{
		int prev_oneidx = 0;
		for (int col = 0; col < maze[row].size(); col++)
		{
			if (maze[row][col] == 1)
			{
				int cnt = 0;
				for (int col2 = col+1; col2 < maze[row].size(); col2++)
				{
					cnt++;
					if (maze[row][col2] == 1)
					{
						sum += --cnt;
						col = --col2;
						break;
					}
				}
			}
		}
	}
	return sum;
}

int main()
{
	cin >> H >> W;
	init();

	for (int i = 0; i < W; i++)
	{
		int num;
		cin >> num;
		for (int row = H - 1; row >= H -num; row--)
		{
			maze[row][i] = 1;
		}
	}

	// 미로 보여주는 방법
	//for (int i = 0; i < maze.size(); i++)
	//{
	//	for (int j = 0; j < maze[i].size(); j++)
	//	{
	//		cout << maze[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	
	int res = simulate();
	cout << res;
}