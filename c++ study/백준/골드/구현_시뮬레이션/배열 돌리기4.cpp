#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
vector<vector<int>> maze;
vector<int> visited;
void rotate(int r, int c, int s)
{
	int sy = r - s;
	int sx = c - s;
	int ey = r + s;
	int ex = c + s;

	// 한 층씩 회전 (바깥에서부터 안쪽으로)
	while (sy < ey && sx < ex)
	{
		int prev = maze[sy][sx];  // 시작 위치의 값을 저장
		// 왼쪽 -> 위쪽
		for (int i = sy; i < ey; i++) maze[i][sx] = maze[i + 1][sx];
		// 아래쪽 -> 왼쪽
		for (int i = sx; i < ex; i++) maze[ey][i] = maze[ey][i + 1];
		// 오른쪽 -> 아래쪽
		for (int i = ey; i > sy; i--) maze[i][ex] = maze[i - 1][ex];
		// 위쪽 -> 오른쪽
		for (int i = ex; i > sx + 1; i--) maze[sy][i] = maze[sy][i - 1];
		
		// 마지막으로 시작 위치의 값 배치
		maze[sy][sx + 1] = prev;
		// 다음 안쪽 직사각형으로 이동
		sy++;
		sx++;
		ey--;
		ex--;
	}
}

vector<int> case_;
vector<vector<int>> all_case;
void case_division(int depth)
{
	if (depth == K)
	{
		all_case.push_back(case_);
		return;
	}

	for (int i = 0; i < K; i++)
	{
		if (visited[i] == 1) continue;
		visited[i] = 1;
		case_.push_back(i);
		case_division(depth + 1);
		case_.pop_back();
		visited[i] = 0;
	}
}

int main()
{
	cin >> N >> M >> K;
	maze = vector<vector<int>>(N, vector<int>(M, 0));
	visited = vector<int>(N, 0);
	// 1번 입력
	// 입력받는 부분 시작 ===================================================================
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maze[i][j];
		}
	}
	vector<vector<int>> rotate_info; // 회전 정보를 넣음
	for (int i = 0; i < K; i++)
	{
		int r, c, s;
		cin >> r >> c >> s;
		rotate_info.push_back({ r - 1, c - 1, s }); // 행, 열이 0부터 할 수 있게 각 -1을 해줌
	}
	// 입력받는 부분 끝 =====================================================================

	// 2번 케이스를 나눔
	case_division(0); // 모든 케이스를 나누는 함수

	// 3번 연산을 진행
	int minRowSum = 21e8; // 최소 합을 기록하는 변수
	vector<vector<int>> originalMaze = maze; // 초기화 시켜줄 배열을 미리 만들어 놓음
	for (int i = 0; i < all_case.size(); i++) // 모든 케이스
	{
		maze = originalMaze; // 각 케이스마다 maze를 초기화해서 연산을 진행해야 하므로
		for (int j = 0; j < all_case[i].size(); j++) // 모든 케이스에 있는 순서 vector를 실행
		{
			int idx = all_case[i][j];
			rotate(rotate_info[idx][0], rotate_info[idx][1], rotate_info[idx][2]);
		}
		// 연산 진행
		for (int i = 0; i < maze.size(); i++)
		{
			int row_sum = 0; // 행 합을 구함
			for (int j = 0; j < maze[i].size(); j++)
			{
				row_sum += maze[i][j];
			}
			minRowSum = min(row_sum, minRowSum); // 최소 행 합을 구함
		}
	}

	// 4번 출력
	cout << minRowSum;
}