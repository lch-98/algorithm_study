#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 방향 배열 (상, 하, 좌, 우)
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int solution(vector<vector<int>> garden) {
    int n = garden.size(); // 정원의 크기
    queue<pair<int, int>> q; // BFS를 위한 큐
    int answer = 0;

    // 먼저 핀 꽃(1)의 위치를 큐에 삽입
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (garden[row][col] == 1) {
                q.push({row, col});
            }
        }
    }

    // BFS 시작
    while (!q.empty()) {
        int size = q.size();
        bool spread = false; // 하루 동안 꽃이 퍼졌는지 확인

        for (int i = 0; i < size; i++) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // 상하좌우로 꽃이 퍼짐
            for (int d = 0; d < 4; d++) {
                int new_row = row + dy[d];
                int new_col = col + dx[d];

                // 격자 범위 내에 있고 아직 꽃이 피지 않은 경우
                if (new_row >= 0 && new_col >= 0 && new_row < n && new_col < n && garden[new_row][new_col] == 0) {
                    garden[new_row][new_col] = 1;
                    q.push({new_row, new_col});
                    spread = true; // 꽃이 퍼졌음
                }
            }
        }

        // 꽃이 퍼졌다면 하루 증가
        if (spread) answer++;
    }

    return answer;
}

// 테스트 케이스
int main() {
    vector<vector<int>> garden1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int ret1 = solution(garden1);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;
    
    vector<vector<int>> garden2 = {{1, 1}, {1, 1}};
    int ret2 = solution(garden2);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}
