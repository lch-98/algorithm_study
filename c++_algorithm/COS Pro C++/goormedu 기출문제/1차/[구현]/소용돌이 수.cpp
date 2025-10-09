#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dy[] = { 0, 1, 0, -1 }; // 동, 남, 서, 북
int dx[] = { 1, 0, -1, 0 };

int solution(int n) {
	vector<vector<int>> maze(n, vector<int>(n, 0));

	int answer = 0;
	int num = 1, dr = 0, ny = 0, nx = 0;

	for (int i = 1; i <= n * n; i++) {
		maze[ny][nx] = i;
		if (ny == nx) answer += i; // 채우면서 대각선 합 구하기

		int next_y = ny + dy[dr];
		int next_x = nx + dx[dr];

		// 범위를 벗어나거나 이미 값이 있으면 방향 전환
		if (next_y < 0 || next_x < 0 || next_y >= n || next_x >= n || maze[next_y][next_x] != 0) {
			dr = (dr + 1) % 4;
			next_y = ny + dy[dr];
			next_x = nx + dx[dr];
		}

		ny = next_y;
		nx = next_x;
	}
	
	return answer;
}

int main() {
	int n1 = 3;
	int ret1 = solution(n1);

	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	int n2 = 2;
	int ret2 = solution(n2);

	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}