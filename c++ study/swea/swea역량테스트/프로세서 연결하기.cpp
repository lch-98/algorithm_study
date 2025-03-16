#include <iostream>
#include <vector>
using namespace std;

int N;
int cnt;
vector<vector<int>> maze;
vector<vector<bool>> visited;
vector<pair<int, int>> cores;
int core_num, line_ans;

void init() {
	maze = vector<vector<int>>(N, vector<int>(N, 0));
	visited = vector<vector<bool>>(N, vector<bool>(N, false));
	cnt = 0;
	cores.clear();
	core_num = 0;
	line_ans = 21e8;
}

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

// 특정 방향으로 라인을 그리거나 지우는 함수
int drawLine(int sy, int sx, int dir, bool draw)
{
	int ny = sy + dy[dir];
	int nx = sx + dx[dir];
	int len = 0;
	while (ny >= 0 && ny < N && nx >= 0 && nx < N)
	{
		visited[ny][nx] = draw; // draw가 true면 라인을 긋고, false면 라인을 지운다
		ny += dy[dir];
		nx += dx[dir];
		len++;
	}
	return len;
}

void simulate(int idx, int line_len, int core_cnt) {
	if (idx == cores.size())
	{
		if (core_cnt > core_num) 
		{
			core_num = core_cnt;
			line_ans = line_len;
		}
		else if (core_cnt == core_num && line_len < line_ans) 
		{
			line_ans = line_len;
		}
		return;
	}

	int y = cores[idx].first;
	int x = cores[idx].second;

	for (int dir = 0; dir < 4; dir++)
	{
		int flag = 1;
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		while (ny >= 0 && ny < N && nx >= 0 && nx < N)
		{
			if (maze[ny][nx] == 1 || visited[ny][nx] == true) {flag = 0; break;} // 다른 코어나 이미 방문한 위치에 막히면 실패
			ny += dy[dir];
			nx += dx[dir];
		}
		if (flag == 0) continue; // 이 방향으로는 갈 수 없으므로 선을 그릴 수 없음

		int added_len = drawLine(y, x, dir, true);
		simulate(idx + 1, line_len + added_len, core_cnt + 1);
		drawLine(y, x, dir, false); // 원복
	}
	simulate(idx + 1, line_len, core_cnt); // 이 코어를 연결하지 않는 경우도 고려
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		init();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> maze[i][j];
				if (maze[i][j] == 1 && i != 0 && i != N - 1 && j != 0 && j != N - 1) {
					cores.push_back({ i, j });
				}
			}
		}
		simulate(0, 0, 0);
		cout << "#" << tc << " " << line_ans << "\n";
	}
}