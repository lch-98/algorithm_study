#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>
using namespace std;

int w, h;
vector<string> maze;
vector<vector<int>> fire_visited;
vector<vector<int>> sanggeun_visited;
pair<int,int> start_pos_sanggeun;
int answer = 0;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void fire_bfs() {
    queue<pair<int,int>> q;
    // 여러 불 시작점 모두 큐에 넣기
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (maze[i][j] == '*') {
                q.push({i,j});
                fire_visited[i][j] = 1;
            }
        }
    }
    
    while(!q.empty()) {
        int curr_ny = q.front().first;
        int curr_nx = q.front().second;
        q.pop();

        for (int dr = 0; dr < 4; dr++) {
            int ny = curr_ny + dy[dr];
            int nx = curr_nx + dx[dr];
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (fire_visited[ny][nx] != INT_MAX) continue;
            if (maze[ny][nx] == '#') continue;
            fire_visited[ny][nx] = fire_visited[curr_ny][curr_nx] + 1;
            q.push({ny, nx});
        }
    }
}

int sanggeun_bfs() {
    queue<pair<int,int>> q;
    q.push(start_pos_sanggeun);
    sanggeun_visited[start_pos_sanggeun.first][start_pos_sanggeun.second] = 1;

    while (!q.empty()) {
        int curr_ny = q.front().first;
        int curr_nx = q.front().second;
        q.pop();

        for (int dr = 0; dr < 4; dr++) {
            int ny = curr_ny + dy[dr];
            int nx = curr_nx + dx[dr];
            // 탈출 성공
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) {
                answer = sanggeun_visited[curr_ny][curr_nx];
                return 1;
            }
            if (maze[ny][nx] == '#') continue;
            if (sanggeun_visited[ny][nx] != 0) continue;
            int nextTime = sanggeun_visited[curr_ny][curr_nx] + 1;
            if (nextTime >= fire_visited[ny][nx]) continue;
            sanggeun_visited[ny][nx] = nextTime;
            q.push({ny, nx});
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    for (int i = 0; i < tc; i++) {
        cin >> w >> h;
        maze = vector<string>(h);
        fire_visited = vector<vector<int>>(h, vector<int>(w, INT_MAX));
        sanggeun_visited = vector<vector<int>>(h, vector<int>(w, 0));
        for (int j = 0; j < h; j++) {
            cin >> maze[j];
            for (int k = 0; k < w; k++) {
                if(maze[j][k] == '@') {
                    start_pos_sanggeun = {j,k};
                }
            }
        }
        fire_bfs();
        if(sanggeun_bfs()) {
            cout << answer << "\n";
        }
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}