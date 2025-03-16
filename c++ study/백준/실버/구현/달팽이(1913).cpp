#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, target;
	cin >> N >> target;

	// 달팽이 배열을 위한 2D 벡터 초기화
	vector<vector<int>> snail(N, vector<int>(N, 0));

	// 방향 설정 (상, 우, 하, 좌 순서)
	int dy[] = { -1, 0, 1, 0 }; // 상, 우, 하, 좌
	int dx[] = { 0, 1, 0, -1 }; // 상, 우, 하, 좌

	int y = N / 2, x = N / 2; // 시작 위치 (중앙)
	int num = 1;              // 채울 숫자
	int dir = 0;              // 현재 방향 (상, 우, 하, 좌)

	snail[y][x] = num; // 중앙에 1을 채움

	int targetY = y, targetX = x; // target의 좌표를 추적
	if (num == target)
	{
		targetY = y;
		targetX = x;
	}

	num++; // 다음 숫자로 이동

	// 달팽이 채우기 (2부터 N^2까지)
	for (int step = 1; step <= N - 1; step++)
	{
		// step만큼 두 번씩 진행하는 방식 (상우하좌 각각 1번씩)
		for (int repeat = 0; repeat < 2; repeat++)
		{
			for (int i = 0; i < step; i++)
			{
				y += dy[dir];
				x += dx[dir];
				snail[y][x] = num;
				if (num == target)
				{
					targetY = y;
					targetX = x;
				}
				num++;
			}
			dir = (dir + 1) % 4; // 방향 전환 (상 → 우 → 하 → 좌)
		}
	}

	// 마지막 라인: N-1 만큼의 걸음으로 채움 (한 번만)
	for (int i = 0; i < N - 1; i++)
	{
		y += dy[dir];
		x += dx[dir];
		snail[y][x] = num;
		if (num == target)
		{
			targetY = y;
			targetX = x;
		}
		num++;
	}

	// 출력: 달팽이 배열 출력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << snail[i][j] << " ";
		}
		cout << "\n";
	}

	// target의 좌표 출력
	cout << targetY + 1 << " " << targetX + 1 << "\n"; // 좌표는 1부터 시작하므로 +1
	return 0;
}
