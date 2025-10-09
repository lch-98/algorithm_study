#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> preferences(N, vector<int>(M));

	// 각 회원의 치킨 선호도 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> preferences[i][j];
		}
	}

	int max_satisfaction = 0;

	// M개의 치킨 중에서 3가지를 고르는 모든 조합을 완전탐색
	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			for (int k = j + 1; k < M; k++) {
				int current_satisfaction = 0;

				// 선택된 3가지 치킨 (i, j, k)에 대해 각 회원의 만족도를 계산
				for (int member = 0; member < N; member++) {
					current_satisfaction += max({ preferences[member][i], preferences[member][j], preferences[member][k] });
				}

				// 만족도의 최대값을 갱신
				max_satisfaction = max(max_satisfaction, current_satisfaction);
			}
		}
	}

	// 결과 출력
	cout << max_satisfaction << endl;

	return 0;
}
