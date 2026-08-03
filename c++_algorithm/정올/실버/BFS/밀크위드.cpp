#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<string> maze;
vector<vector<int>> visited;
int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1}; // 행
int dx[] = {0, 0, -1, 1, -1, 1, -1, 1}; // 열

void print_visited() {
	for (int i = 0; i < visited.size(); i++) {
		for (int j = 0; j < visited[0].size(); j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}

int bfs(pair<int,int> start) {
	int res = 0;
	queue<pair<int,int>> q;
	q.push(start);
    // 첫 날이 카운트 1로 됨
    // 따라서 return 해줄 때 -1을 해줘야 답이 맞음
	visited[start.first][start.second] = 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		
		for (int dr = 0; dr < 8; dr++) {
			int ny = cy + dy[dr];
			int nx = cx + dx[dr];
			
			if (ny < 0 || nx < 0 || ny >= visited.size() || nx >= visited[0].size()) continue;
			if (maze[ny][nx] == '*') continue;
			if (visited[ny][nx] != 0) continue;
			
			q.push({ ny, nx });
			visited[ny][nx] = visited[cy][cx] + 1;
			res = max(res, visited[ny][nx]);
		}
		// print_visited();
	}
	return res-1;
}

int main() {
	int X, Y, Mx, My; // 열, 행, 장애물 열, 장애물 행 
	string str;
	cin >> X >> Y >> Mx >> My;

	for (int i = 0; i < Y; i++) {
		cin >> str;
		maze.push_back(str);
	}
	visited = vector<vector<int>>(Y, vector<int>(X, 0));
	
	int ans = bfs({ (Y-1) - (My - 1), Mx - 1 });
	cout << ans << "\n";
	return 0;
}