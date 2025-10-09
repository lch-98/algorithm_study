#include <vector>
#include <queue>
using namespace std;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
int bfs(vector<vector<int>> &maps, pair<int,int> start) {
    vector<vector<int>> visited = vector<vector<int>>(maps.size(), vector<int>(maps[0].size(), -1));
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = 1;
    
    while(!q.empty()) {
        int curr_row = q.front().first;
        int curr_col = q.front().second;
        q.pop();
        
        for (int dr = 0; dr < 4; dr++) {
            int ny = curr_row + dy[dr];
            int nx = curr_col + dx[dr];
            if (ny < 0 || nx < 0 || ny >= maps.size() || nx >= maps[0].size()) continue;
            if (visited[ny][nx] != -1) continue;
            if (maps[ny][nx] != 1) continue; 
            q.push({ny,nx});
            visited[ny][nx] = visited[curr_row][curr_col] + 1;
        }
    }
    return visited[maps.size() - 1][maps[0].size() - 1];
}

int solution(vector<vector<int> > maps)
{
    int answer = bfs(maps, {0,0});
    return answer;
}