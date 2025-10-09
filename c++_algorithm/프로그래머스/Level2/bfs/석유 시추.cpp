#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int bfs(pair<int,int> start, int id, vector<vector<int>> &land, vector<vector<int>> &group) {
    queue<pair<int,int>> q;
    q.push(start);
    group[start.first][start.second] = id;
    int cnt = 1;

    while (!q.empty()) {
        int curr_row = q.front().first;
        int curr_col = q.front().second;
        q.pop();

        for (int dr = 0; dr < 4; dr++) {
            int ny = curr_row + dy[dr];
            int nx = curr_col + dx[dr];
            if (ny < 0 || nx < 0 || ny >= land.size() || nx >= land[0].size()) continue;
            if (land[ny][nx] == 0 || group[ny][nx] != 0) continue;
            group[ny][nx] = id;
            q.push({ny, nx});
            cnt++;
        }
    }
    return cnt;
}

int solution(vector<vector<int>> land) {
    int n = land.size();
    int m = land[0].size();
    vector<vector<int>> group(n, vector<int>(m, 0));
    vector<int> group_size;
    group_size.push_back(0);

    int id = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (land[i][j] == 1 && group[i][j] == 0) {
                int size = bfs({i, j}, id, land, group);
                group_size.push_back(size);
                id++;
            }
        }
    }

    int answer = 0;
    for (int col = 0; col < m; col++) {
        set<int> oil_ids;
        for (int row = 0; row < n; row++) {
            if (group[row][col] != 0) oil_ids.insert(group[row][col]);
        }
        int sum = 0;
        for (int gid : oil_ids) sum += group_size[gid];
        answer = max(answer, sum);
    }

    return answer;
}