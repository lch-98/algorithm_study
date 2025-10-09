#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct Compare {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) return a > b;  // 절댓값 같으면, 실제 값이 작은 거 우선
		return abs(a) > abs(b);             // 절댓값 기준 오름차순
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, Compare> pq;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (num == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}
	}

	return 0;
}
