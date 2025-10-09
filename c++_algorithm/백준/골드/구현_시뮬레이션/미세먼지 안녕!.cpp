#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int dy[] = {-1, 1, 0, 0};
int dx[] = { 0, 0, -1, 1 };
vector<vector<int>> map_;
vector<vector<int>> chk_expand;
vector<pair<int, int>> air_purifier;
int R, C, T;
void expand() {
	// 먼저 공기청정기, 미세먼지 없는칸 넘어감
	// 미세먼지칸 발견시 가능항 방향 카운트
	// chk_expand 벡터에 가능항 방향으로 가운데 누적 값 저장
	// 이후, 가운데 값에 가능항 방향 카운트 만큼 빼줌
	for (int i = 0; i < map_.size(); i++) {
		for (int j = 0; j < map_[0].size(); j++) {
			if (map_[i][j] == -1 || map_[i][j] == 0) continue;
			int cnt = 0;
			for (int dr = 0; dr < 4; dr++) {
				int ny = i + dy[dr];
				int nx = j + dx[dr];
				// 칸이 없거나(범위를 벗어나거나), 공기청정기 위치면 넘어가기
				if (ny < 0 || nx < 0 || ny >= map_.size() || nx >= map_[0].size()) continue;
				if (map_[ny][nx] == -1) continue;
				chk_expand[ny][nx] += floor(map_[i][j] / 5);
				cnt++;
			}
			map_[i][j] -= floor(map_[i][j] / 5) * cnt;
		}
	}
	// chk_expand로 계산한 누적값을 map_함수에 반영
	for (int i = 0; i < map_.size(); i++) {
		for (int j = 0; j < map_[0].size(); j++) {
			if (map_[i][j] == -1) continue;
			map_[i][j] += chk_expand[i][j];
		}
	}
	// 누적 값을 초기화 시켜줌
	chk_expand = vector<vector<int>>(R, vector<int>(C, 0));
}

void working() {
	int top = air_purifier[0].first;
	int bottom = air_purifier[1].first;
	vector<vector<int>> tmp = map_;

	// 위쪽 (반시계)
	for (int i = top - 1; i > 0; i--) tmp[i][0] = map_[i - 1][0];
	for (int j = 0; j < C - 1; j++) tmp[0][j] = map_[0][j + 1];
	for (int i = 0; i < top; i++) tmp[i][C - 1] = map_[i + 1][C - 1];
	for (int j = C - 1; j > 1; j--) tmp[top][j] = map_[top][j - 1];
	tmp[top][1] = 0;

	// 아래쪽 (시계)
	for (int i = bottom + 1; i < R - 1; i++) tmp[i][0] = map_[i + 1][0];
	for (int j = 0; j < C - 1; j++) tmp[R - 1][j] = map_[R - 1][j + 1];
	for (int i = R - 1; i > bottom; i--) tmp[i][C - 1] = map_[i - 1][C - 1];
	for (int j = C - 1; j > 1; j--) tmp[bottom][j] = map_[bottom][j - 1];
	tmp[bottom][1] = 0;

	// 공기청정기 위치 유지
	tmp[top][0] = tmp[bottom][0] = -1;

	map_ = tmp;
}


int main() {
	cin >> R >> C >> T;
	map_ = vector<vector<int>>(R, vector<int>(C, 0));
	chk_expand = vector<vector<int>>(R, vector<int>(C, 0));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map_[i][j];
			if (map_[i][j] == -1) air_purifier.push_back({i,j});
		}
	}


	for (int i = 0; i < T; i++) {
		// 미세먼지 확산
		expand();
		// 공기청정기 작동
		working();
	}

	// 미세먼지의 양 출력
	int ans = 0;
	for (int i = 0; i < map_.size(); i++) {
		for (int j = 0; j < map_[0].size(); j++) {
			if (map_[i][j] == -1) continue;
			else ans += map_[i][j];
		}
	}
	cout << ans;
	return 0;
}