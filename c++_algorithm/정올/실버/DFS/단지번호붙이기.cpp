#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> maze;
vector<vector<int>> visited;
vector<int> ans;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int N;

struct pos {
    int row;
    int col;
};

int cnt;   // 현재 단지의 집 개수

void dfs(pos start) {
    // 현재 위치 방문
    visited[start.row][start.col] = 1;
    cnt++;

    for (int dr = 0; dr < 4; dr++) {
        int ny = start.row + dy[dr];
        int nx = start.col + dx[dr];

        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if (visited[ny][nx] == 1) continue;
        if (maze[ny][nx] == '0') continue;

        dfs({ ny, nx });
    }
}

int main() {
    cin >> N;

    maze = vector<string>(N);
    visited = vector<vector<int>>(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
        cin >> maze[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (maze[i][j] == '0') continue;
            if (visited[i][j] == 1) continue;

            cnt = 0;
            dfs({ i, j }); 
            ans.push_back(cnt);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int x : ans) cout << x << '\n';

    return 0;
}