#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> maze;
vector<vector<int>> new_maze;
vector<vector<bool>> visited;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void init() {
    maze = vector<vector<int>>(N, vector<int>(M, 0));
    new_maze = vector<vector<int>>(N, vector<int>(M, 0));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));
}

void bfs(int row, int col) {
    queue<pair<int, int>> q;
    q.push({ row, col });
    visited[row][col] = true;

    while (!q.empty()) {
        int curr_row = q.front().first;
        int curr_col = q.front().second;
        q.pop();

        for (int dr = 0; dr < 4; dr++) {
            int ny = curr_row + dy[dr];
            int nx = curr_col + dx[dr];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (maze[ny][nx] == 0 || visited[ny][nx]) continue;

            q.push({ ny, nx });
            visited[ny][nx] = true;
        }
    }
}

void melt() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (maze[i][j] > 0) {
                int water = 0;
                for (int dr = 0; dr < 4; dr++) {
                    int ny = i + dy[dr];
                    int nx = j + dx[dr];
                    if (maze[ny][nx] == 0) water++;
                }
                new_maze[i][j] = max(0, maze[i][j] - water);
            }
        }
    }

    maze = new_maze;
}

int main() {
    cin >> N >> M;
    init();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
        }
    }

    int years = 0;

    while (true) {
        visited = vector<vector<bool>>(N, vector<bool>(M, false));
        int iceberg_count = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (maze[i][j] > 0 && !visited[i][j]) {
                    bfs(i, j);
                    iceberg_count++;
                }
            }
        }

        if (iceberg_count == 0) {
            cout << 0 << endl;
            break;
        }

        if (iceberg_count >= 2) {
            cout << years << endl;
            break;
        }

        melt();
        years++;
    }

    return 0;
}
