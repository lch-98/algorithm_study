#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// N개의 칸, 두 줄로 이루어진 경로가 주어짐
// 안전한 칸은 이동 가능(1), 위험한 칸은 이동 불가능(0)
// 매 초마다 한 칸 앞으로, 한 칸 뒤로 이동하거나 반대편 줄로 k칸 앞으로 점프 가능

int N, k;
vector<string> maze;
vector<vector<bool>> visited; // 방문 여부 저장
int dx[3] = { 1, -1, k };       // 오른쪽, 왼쪽, k칸 점프 이동
int dy[3] = { 0, 0, 1 };         // 줄 유지, 줄 유지, 반대편 줄로 이동

struct info {
	int y;
	int x;
	int time;
};

void init() {
	maze = vector<string>(2);
	visited = vector<vector<bool>>(2, vector<bool>(N, false));
}

// BFS 탐색 함수
int bfs(pair<int, int> start) {
	queue<info> q; // ((줄, 칸), 시간) 형식
	q.push({ start.first, start.second, 0 });
	visited[start.first][start.second] = true;

	while (!q.empty()) {
		int curr_row = q.front().y;
		int curr_col = q.front().x;
		int time = q.front().time;
		q.pop();

		// 세 가지 이동 방식
		for (int i = 0; i < 3; i++) {
			int ny = curr_row + dy[i];
			int nx = curr_col + dx[i];
			int next_row = curr_row;

			// 점프 이동 시 줄 변경
			if (i == 2) {
				ny = 1 - curr_row; // 반대편 줄로 이동
				nx = curr_col + k;
			}

			// 종료 조건: N번 칸을 넘어가면 클리어
			if (nx >= N) return 1;

			// 이동 조건 확인
			if (nx < 0 || ny < 0 || ny >= 2 || visited[ny][nx]) continue;
			if (maze[ny][nx] == '0' || nx < time + 1) continue;

			// 방문 처리 및 큐에 삽입
			visited[ny][nx] = true;
			q.push({ ny, nx, time + 1 });
		}
	}

	return 0; // 이동 가능 경로가 없으면 클리어 불가능
}

int main() {
	cin >> N >> k;
	init();

	// 두 줄의 칸 입력
	for (int i = 0; i < 2; i++) {
		cin >> maze[i];
	}

	// 시작은 왼쪽 줄의 첫 번째 칸 (0,0)에서 출발
	cout << bfs({ 0, 0 });

	return 0;
}