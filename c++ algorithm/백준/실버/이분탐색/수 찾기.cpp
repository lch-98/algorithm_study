#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// binary_search 함수 직접 구현
bool binary_search(const vector<int>& A, int target) {
	int left = 0;
	int right = A.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;  // 중간 인덱스 계산 // (left + right) / 2도 맞는 표현

		if (A[mid] == target) {
			return true;  // 값을 찾았으면 true 반환
		}
		else if (A[mid] < target) {
			left = mid + 1;  // 오른쪽 절반에서 계속 탐색
		}
		else {
			right = mid - 1;  // 왼쪽 절반에서 계속 탐색
		}
	}

	return false;  // 값을 찾지 못했으면 false 반환
}

int main() {
	ios_base::sync_with_stdio(0);  // 입력 속도 향상
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> A(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	// 1. 배열 A를 정렬
	sort(A.begin(), A.end());

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		// 2. 직접 구현한 binary_search로 num이 배열 A에 있는지 확인
		if (binary_search(A, num)) {
			cout << 1 << "\n";  // 존재하면 1 출력
		}
		else {
			cout << 0 << "\n";  // 존재하지 않으면 0 출력
		}
	}

	return 0;
}
