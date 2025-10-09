#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> classes(N);
	for (int i = 0; i < N; i++) {
		cin >> classes[i].first >> classes[i].second;
	}

	sort(classes.begin(), classes.end()); // 시작 시간 기준 정렬

	priority_queue<int, vector<int>, greater<int>> pq; // 끝나는 시간 기준 min-heap
	pq.push(classes[0].second); // 첫 수업의 끝나는 시간 추가

	for (int i = 1; i < N; i++) {
		if (pq.top() <= classes[i].first) {
			pq.pop(); // 강의실 재사용 가능
		}
		pq.push(classes[i].second); // 새 수업 추가
	}

	cout << pq.size() << "\n"; // 필요한 최소 강의실 수
}
