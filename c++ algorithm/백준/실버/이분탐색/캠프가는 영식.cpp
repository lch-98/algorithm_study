#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
	return a[0] < b[0];
}

int main() {
	int N, T;
	cin >> N >> T;
	vector<vector<int>> bus_list(N);
	for (int i = 0; i < N; i++) {
		int S, L, C;
		cin >> S >> L >> C;
		bus_list[i].push_back(S);
		for (int j = 1; j < C; j++) {
			bus_list[i].push_back(S +( L * j));
		}
	}
	// 최소가 되는 버스 범위에서 찾아야 하므로, 오름차순 정렬
	sort(bus_list.begin(), bus_list.end(), compare);

	int answer = -1;
	for (int i = 0; i < bus_list.size(); i++) {
		// 마지막 값이 도착시간 보다 작으면 다음꺼에서 확인
		// 도달할 수 없기 때문임
		if (bus_list[i][bus_list[i].size() - 1] < T) continue;
			
		int left = 0;
		int right = bus_list[i].size() - 1;
		int idx = -1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (bus_list[i][mid] >= T) {
				idx = mid;
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}

		if (idx != -1) {
			int wait = bus_list[i][idx] - T;
			if (answer == -1 || wait < answer) answer = wait;
		}
	}
	cout << answer;
	return 0;
}