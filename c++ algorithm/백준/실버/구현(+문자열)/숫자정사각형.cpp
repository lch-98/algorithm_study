#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> maze(N, vector<int>(M));
	for (int i = 0; i < N; i++) 
	{
		string row;
		cin >> row;
		for (int j = 0; j < M; j++) 
		{
			maze[i][j] = row[j] - '0';
		}
	}

	int max_size = 1;  // 가장 큰 정사각형의 한 변의 길이 (최소 1)

	// 큰 크기의 정사각형부터 확인하기 위해 역순으로 탐색
	int limit = min(N, M);  // N과 M 중 작은 값을 기준으로
	for (int size = limit; size >= 1; size--) 
	{
		for (int i = 0; i < N - (size-1); i++) 
		{
			for (int j = 0; j < M - (size-1); j++) 
			{
				if (maze[i][j] == maze[i][j + (size-1)] &&
					maze[i][j] == maze[i + (size-1)][j] &&
					maze[i][j] == maze[i + (size - 1)][j + (size - 1)])
				{
					//cout << i << " " << j << " " << size;
					cout << size * size << endl;
					return 0;  // 가장 큰 정사각형을 찾으면 바로 종료
				}
			}
		}
	}

	// 만약 탐색을 다 했는데도 발견되지 않았다면, 최소 정사각형 크기는 1
	cout << 1 << endl;
	return 0;
}
