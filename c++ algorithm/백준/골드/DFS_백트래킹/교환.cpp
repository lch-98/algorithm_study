#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

string num_;
int change_cnt;
int max_ans;
unordered_set<string> visited; // 방문한 상태를 기록

void backtracking(string num, int depth) {
	// 이미 방문한 상태면 중단
	string state = num + "_" + to_string(depth);
	if (visited.find(state) != visited.end()) {
		return;
	}
	visited.insert(state);

	// 종료 조건: 교환 횟수를 모두 사용했을 경우
	if (depth == change_cnt) {
		max_ans = max(max_ans, stoi(num)); // 최댓값 갱신
		return;
	}

	// 모든 가능한 교환을 시도
	for (int i = 0; i < num.size(); i++) {
		for (int j = i + 1; j < num.size(); j++) {
			// 교환 시도
			swap(num[i], num[j]);
			// 숫자가 0으로 시작하는지 확인
			if (num[0] != '0') {
				backtracking(num, depth + 1);
			}
			// 원상복구
			swap(num[i], num[j]);
		}
	}
}

int main() {
	cin >> num_ >> change_cnt;
	max_ans = -1; // 초기화
	visited.clear(); // 방문 기록 초기화
	backtracking(num_, 0);

	// 교환을 통해 만들어진 숫자가 없을 경우 -1 출력
	cout << (max_ans == -1 ? -1 : max_ans) << "\n";
}
