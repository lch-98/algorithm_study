#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, K;
vector<vector<int>> arr;

int bfs(int si, int sj, int val) {
    queue<pair<int, int>> q;
    vector<vector<int>> v(N, vector<int>(M, 0));
    int cnt = 1;

    q.push({si, sj});
    v[si][sj] = 1;

    while (!q.empty()) {
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        // 네 방향 탐색
        int di[4] = {-1, 1, 0, 0};
        int dj[4] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++) {
            int ni = ci + di[d];
            int nj = cj + dj[d];

            if (ni >= 0 && ni < N && nj >= 0 && nj < M && v[ni][nj] == 0 && arr[ni][nj] == val) {
                q.push({ni, nj});
                v[ni][nj] = 1;
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    cin >> N >> M >> K;
    arr.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    // 시계: 상,우,하,좌
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};
    int d1 = 1, d2 = 2, d3 = 3, d4 = 4, d5 = 5, d6 = 6; // 초기값
    int dr = 1;                                         // 동쪽(우측)
    int ci = 0, cj = 0, ans = 0;

    for (int k = 0; k < K; k++) {  // K번 이동
        // [1] 한 칸 이동(dr), 범위밖 => 방향을 반대로
        int ni = ci + di[dr];
        int nj = cj + dj[dr];

        if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
            ci = ni;
            cj = nj;
        } else {  // 범위밖 => 반대방향 이동!
            dr = (dr + 2) % 4;
            ci = ci + di[dr];
            cj = cj + dj[dr];
        }

        // [1] 좌표의 이동처럼, 주사위 회전도 처리
        if (dr == 0) {  // 상(북)
            int temp = d1;
            d1 = d5;
            d5 = d6;
            d6 = d2;
            d2 = temp;
        } else if (dr == 1) {  // 우(동)
            int temp = d1;
            d1 = d4;
            d4 = d6;
            d6 = d3;
            d3 = temp;
        } else if (dr == 2) {  // 하(남)
            int temp = d1;
            d1 = d2;
            d2 = d6;
            d6 = d5;
            d5 = temp;
        } else {  // 좌(서)
            int temp = d1;
            d1 = d3;
            d3 = d6;
            d6 = d4;
            d4 = temp;
        }

        // [2] 점수계산: arr[] 같은 값이면 그 개수만큼 점수
        ans += bfs(ci, cj, arr[ci][cj]) * arr[ci][cj];

        // [3] 주사위방향 전환
        if (d6 > arr[ci][cj]) {
            dr = (dr + 1) % 4;  // 시계방향
        } else if (d6 < arr[ci][cj]) {
            dr = (dr + 3) % 4;  // 반시계방향
        }
    }

    cout << ans << endl;

    return 0;
}
