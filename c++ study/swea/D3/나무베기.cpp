#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m; // n은 map 사이즈, m은 자를 수 있는 나무의 횟수
vector<vector<int>> maze;
vector<vector<int>> visited;
pair<int, int> start;
pair<int, int> end_;
int ans;
void init() {
	maze = vector<vector<int>>(n, vector<int>(n, 0));
	visited = vector<vector<int>>(n, vector<int>(n, 0));
	ans = 21e8;
}

void print() {
	cout << "===== maze =====" << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << "\n";
	}
}

int cal_move(int prev_dr, int curr_dr) {
	// 4x4 이동 비용 표: prev_dr와 curr_dr의 방향 차이에 따른 비용 정의
	// 순서대로 머리 방향이 상 하 좌 우를 가르킴
	int move_cost[4][4] = {
		{0, 2, 1, 1}, // prev_dr = 0
		{2, 0, 1, 1}, // prev_dr = 1
		{1, 1, 0, 2}, // prev_dr = 2
		{1, 1, 2, 0}  // prev_dr = 3
	};
	return move_cost[prev_dr][curr_dr];
}

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
void dfs(pair<int,int> curr, int remote_cnt, int cut_cnt, int prev_dr) {
	if (curr.first == end_.first && curr.second == end_.second)
	{
		if (remote_cnt < ans)
		{
			ans = remote_cnt;
		}
		return;
	}

	for (int dr = 0; dr < 4; dr++)
	{
		int ny = curr.first + dy[dr];
		int nx = curr.second + dx[dr];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (visited[ny][nx] != 0) continue;

		// 그냥 전진
		if (maze[ny][nx] == 0) {
			visited[ny][nx] = 1;
			int move_remote_cnt = cal_move(prev_dr, dr);

			dfs({ ny, nx }, remote_cnt + move_remote_cnt + 1, cut_cnt, dr);
			visited[ny][nx] = 0;
		}

		// 나무 자르고 전진
		if (maze[ny][nx] == 1 && cut_cnt + 1 <= m) {
			visited[ny][nx] = 1;
			int move_remote_cnt = cal_move(prev_dr, dr);
			
			dfs({ ny, nx }, remote_cnt + move_remote_cnt + 1, cut_cnt + 1, dr);
			visited[ny][nx] = 0;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n >> m;
		init();
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < str.size(); j++)
			{
				if (str[j] == 'X') start = { i,j };
				else if (str[j] == 'Y') end_ = { i,j };
				else if (str[j] == 'T') maze[i][j] = 1;
			}
		}
		//print();
		dfs(start, 0, 0, 0);
		if (ans != 21e8) { cout << "#" << tc << " " << ans << "\n"; }
		else { cout << "#" << tc << " " << -1 << "\n"; }
	}

}