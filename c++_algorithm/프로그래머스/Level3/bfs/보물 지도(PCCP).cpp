#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<vector<int>> maze;
vector<vector<vector<int>>> visited;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

struct Node {
    int y, x, shoe; // shoe = 0 안씀, shoe = 1 씀
};

void bfs(int max_row, int max_col) {
    queue<Node> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 0;

    while (!q.empty()) {
        int curr_row = q.front().y;
        int curr_col = q.front().x;
        int shoe_used = q.front().shoe;
        q.pop();

        // 목적지 도착
        if (curr_row == max_row - 1 && curr_col == max_col - 1) return;

        for (int dr = 0; dr < 4; dr++) {
            int ny = curr_row + dy[dr];
            int nx = curr_col + dx[dr];
            if (ny < 0 || nx < 0 || ny >= max_row || nx >= max_col) continue;
            if (maze[ny][nx] == 1) continue;
            if (visited[curr_row][curr_col][shoe_used] + 1 < visited[ny][nx][shoe_used]) {
                visited[ny][nx][shoe_used] = visited[curr_row][curr_col][shoe_used] + 1;
                q.push({ny, nx, shoe_used});
            }
        }

        if (shoe_used == 0) {
            for (int dr = 0; dr < 4; dr++) {
                int ny = curr_row + dy[dr] * 2;
                int nx = curr_col + dx[dr] * 2;
                if (ny < 0 || nx < 0 || ny >= max_row || nx >= max_col) continue;
                if (maze[ny][nx] == 1) continue;
                if (visited[curr_row][curr_col][0] + 1 < visited[ny][nx][1]) {
                    visited[ny][nx][1] = visited[curr_row][curr_col][0] + 1;
                    q.push({ny, nx, 1});
                }
            }
        }
    }
}

int solution(int n, int m, vector<vector<int>> hole) {
    int answer = 0;
    maze = vector<vector<int>>(m, vector<int>(n, 0));
    visited = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(2, 9999999)));

    for (int i = 0; i < hole.size(); i++) {
        maze[hole[i][1] - 1][hole[i][0] - 1] = 1;
    }

    bfs(m, n);

    int normal = visited[m - 1][n - 1][0];
    int jump = visited[m - 1][n - 1][1];

    int res = min(normal, jump);
    if (res == 9999999) answer = -1;
    else answer = res;

    return answer;
}