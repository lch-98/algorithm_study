#include <iostream>
#include <vector>
using namespace std;

// 로봇 청소기 바라보는 방향 d
// d가 0부터 ~ 3까지 -> 북 동 남 서
vector<vector<int>> maze;
int N, M;
int sy, sx, dr;
int cnt; // 방을 청소하는 갯수를 적는 칸
vector<int> dy;
vector<int> dx;

void direction(int dr)
{
	// 머리 방향으로 전진 우측 후진 좌측 이동 순으로 선언
	if (dr == 0) { dy = {-1, 0, 1, 0}; dx = {0, 1, 0, -1}; } // 북쪽 방향
	else if (dr == 1) { dy = {0, 1, 0, -1 }; dx = {1, 0, -1, 0}; } // 동쪽 방향
	else if (dr == 2) { dy = {1, 0, -1, 0 }; dx = {0, -1, 0, 1}; } // 남쪽 방향
	else if (dr == 3) { dy = { 0, -1, 0, 1 }; dx = { -1, 0, 1, 0 }; } // 서쪽 방향
}

void simulate(int cy, int cx, int dr)
{
	direction(dr);
	while (1)
	{
		// 1번. 현재 칸이 아직 청소되지 않은 경우, 현재 칸 청소
		if (maze[cy][cx] == 0) cnt++;  maze[cy][cx] = 2;

		// 2번. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우 flag = 1; 빈 칸 찾은 경우 flag = 0;
		int flag = 0; // 빈칸을 못 찾으면 while문 break;
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (maze[ny][nx] == 1) continue; // 벽이 있으면 다음 방향 확인
			if (ny < 0 && nx < 0 && ny >= N && nx >= N) continue; // 크기 넘으면 다음 방향 확인
			// 단 하나의 빈 칸이라도 있으면 오케이
			if (maze[ny][nx] == 0) flag = 1; break;
		}
		if (flag == 0)
		{
			int ny = cy + dy[2];
			int nx = cx + dx[2];
			// 뒤로 갈 수 있는지 판단하고 머리 방향 유지하고 갈 수 있으면 후진 후 1번으로
			if (maze[ny][nx] != 1)
			{
				cy = ny;
				cx = nx;
				continue;
			}
			else break; // 갈 수 없으니 멈춰버림
		}
		// 3번. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
		else if (flag == 1)
		{
			int flag_1 = 0;
			// 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진
			for (int i = 0; i < 4; i++)
			{
				dr = (dr + 3) % 4; // 반시계 방향 90도 회전
				direction(dr);
				int ny = cy + dy[0];
				int nx = cx + dx[0];
				// 할 필요 없음 이미 위에서 갈 수 없는 걸 확인 했음
				//if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				//if (maze[ny][nx] == 1) continue;
				if (maze[ny][nx] == 0) // 앞으로 전진할 때 청소되지 않은 칸이 있으면 갈 수 있음
				{
					// 할 필요 없음 어차피 break 하고 맨위에서 청소 할거임
					// maze[ny][nx] = 2;
					cy = ny;
					cx = nx;
					flag_1 = 1;
					break;
				}
			}
			// 만약 전진했다면 1번으로 이동
			if (flag_1 == 1) continue;
		}
	}
}


int main()
{
	// 0인 경우 청소되지 않은 빈 칸, 빈 칸을 2로 만들어서 청소처리
	// 1인 경우 벽이 있는 것
	cin >> N >> M;
	cin >> sy >> sx >> dr;

	maze = vector<vector<int>>(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maze[i][j];
		}
	}
	simulate(sy, sx, dr);
	cout << cnt;
}