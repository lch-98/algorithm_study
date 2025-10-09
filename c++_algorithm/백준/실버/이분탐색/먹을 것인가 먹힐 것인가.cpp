#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;
vector<int> B;

int binary_search_count(int target) {
	int left = 0;
	int right = B.size() - 1;
	int count = 0;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (target > B[mid]) {
			count = mid + 1;  // mid 이전의 값들은 모두 target보다 작음
			left = mid + 1;   // 더 오른쪽에서 탐색
		}
		else {
			right = mid - 1;  // 더 작은 값에서 탐색
		}
	}

	return count;  // A[i]보다 작은 B의 개수 반환
}

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int N, M;
		cin >> N >> M;
		A.clear();
		B.clear();

		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			A.push_back(num);
		}

		for (int i = 0; i < M; i++) {
			int num;
			cin >> num;
			B.push_back(num);
		}

		// A와 B를 정렬
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		int cnt = 0;
		// A의 각 원소에 대해 B에서 A[i]보다 작은 원소들의 개수를 구함
		for (int i = 0; i < A.size(); i++) {
			cnt += binary_search_count(A[i]);
		}

		cout << cnt << "\n";
	}

	return 0;
}
