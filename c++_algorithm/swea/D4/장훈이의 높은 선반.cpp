#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T; // 테스트 케이스 수 입력

	for (int tc = 1; tc <= T; ++tc) {
		int N, B;
		cin >> N >> B; // 사원 수 N과 목표 높이 B 입력

		vector<int> N_lst(N); // 사원들의 높이 리스트
		int total_sum = 0; // 사원들의 총합을 구해 배열 크기 설정

		for (int i = 0; i < N; ++i) {
			cin >> N_lst[i];
			total_sum += N_lst[i];
		}

		vector<int> v_lst(total_sum + 1, 0); // 가능한 합을 기록하는 배열
		v_lst[0] = 1; // 0을 만드는 것은 항상 가능
		vector<int> ans_lst = { 0 }; // 현재까지 가능한 부분합을 기록

		for (int height : N_lst) {
			vector<int> temp_lst; // 새로 가능한 부분합 기록용
			for (int partial_sum : ans_lst) {
				if (v_lst[height + partial_sum] == 0) {
					v_lst[height + partial_sum] = 1;
					temp_lst.push_back(height + partial_sum);
				}
			}
			ans_lst.insert(ans_lst.end(), temp_lst.begin(), temp_lst.end());
		}

		int ans = 0;
		for (int k = B; k <= total_sum; ++k) {
			if (v_lst[k] == 1) {
				ans = k;
				break;
			}
		}

		cout << "#" << tc << " " << ans - B << endl;
	}

	return 0;
}