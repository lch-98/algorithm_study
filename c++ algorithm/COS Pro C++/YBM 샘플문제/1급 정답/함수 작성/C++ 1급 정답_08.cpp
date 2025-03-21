#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(int numberA, int numberB, int limit) {
	unordered_set<int> possible_numbers;  // 중복 제거를 위한 set
	queue<int> q;  // BFS를 위한 queue

	// 초기 숫자 삽입
	q.push(numberA);
	q.push(numberB);
	possible_numbers.insert(numberA);
	possible_numbers.insert(numberB);

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		// A를 더했을 때
		int nextA = current + numberA;
		if (nextA <= limit && possible_numbers.find(nextA) == possible_numbers.end()) {
			possible_numbers.insert(nextA);
			q.push(nextA);
		}

		// B를 더했을 때
		int nextB = current + numberB;
		if (nextB <= limit && possible_numbers.find(nextB) == possible_numbers.end()) {
			possible_numbers.insert(nextB);
			q.push(nextB);
		}
	}

	return possible_numbers.size();
}

// 아래는 테스트케이스를 출력해 보기 위한 main 함수입니다.
int main() {
	int numberA1 = 2;
	int numberB1 = 4;
	int limit1 = 10;
	int ret1 = solution(numberA1, numberB1, limit1);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	int numberA2 = 2;
	int numberB2 = 3;
	int limit2 = 10;
	int ret2 = solution(numberA2, numberB2, limit2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;

	return 0;
}
