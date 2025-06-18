// 한양대학교 HEPC 문제
#include <iostream>
#include <vector>
using namespace std;

int N, M, R, C;
vector<vector<int>> camping_map;
vector<vector<int>> flatter_map;
bool flatter_compare(int row, int col) {
	vector<int> compare_arr;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			// 각 위치에서 실제 고도 - 작업 계획도 고도
			int flattened_height = camping_map[row + i][col + j] - flatter_map[i][j];
			compare_arr.push_back(flattened_height);
		}
	}

	// 만약 전에 값이랑 현재 값이 하나라도 다르다면 평탄화 불가능, 모든 값이 같다면 평탄화 가능
	int prev = compare_arr[0];
	for (int i = 1; i < compare_arr.size(); i++) {
		if (compare_arr[i] != prev) return false;
	}
	return true;
}

int main() {
	cin >> N >> M >> R >> C;
	// 입력 부분
	camping_map = vector<vector<int>>(N, vector<int>(M, 0));
	flatter_map = vector<vector<int>>(R, vector<int>(C, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> camping_map[i][j];
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)	{
			cin >> flatter_map[i][j];
		}
	}

	// R, C만큼은 제외해주고 모든 값을 확인해야 함
	int ans = 0;
	for (int i = 0; i <= N-R; i++) {
		for (int j = 0; j <= M-C; j++) {
			if (flatter_compare(i, j)) ans++;
		}
	}
	cout << ans;
}