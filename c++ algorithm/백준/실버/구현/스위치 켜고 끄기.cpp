#include <iostream>
#include <vector>
using namespace std;

vector<int> switch_state;

void simulate(int fm, int num) {
	// 남학생
	if (fm == 1) {
		// num의 배수를 모두 뒤집는다.
		for (int i = num; i <= switch_state.size(); i += num) {
			switch_state[i - 1] = 1 - switch_state[i - 1]; // 상태 반전
		}
	}

	// 여학생
	if (fm == 2) {
		int left = num - 1;
		int right = num - 1;

		// 현재 스위치 상태 반전
		switch_state[num - 1] = 1 - switch_state[num - 1];

		// 대칭 범위 확인
		while (left > 0 && right < switch_state.size() - 1 && switch_state[left - 1] == switch_state[right + 1]) {
			switch_state[left - 1] = 1 - switch_state[left - 1]; // 왼쪽 스위치 상태 반전
			switch_state[right + 1] = 1 - switch_state[right + 1]; // 오른쪽 스위치 상태 반전
			left--; // 왼쪽으로 이동
			right++; // 오른쪽으로 이동
		}
	}
}

int main() {
	int N;
	cin >> N;
	switch_state = vector<int>(N);

	for (int i = 0; i < N; i++) {
		cin >> switch_state[i];
	}

	int student_num;
	cin >> student_num;

	for (int i = 0; i < student_num; i++) {
		int fm, num;
		cin >> fm >> num;
		simulate(fm, num);
	}

	// 20개씩 줄을 나누어 출력
	for (int i = 0; i < switch_state.size(); i++) {
		cout << switch_state[i] << " ";
		if ((i + 1) % 20 == 0) {
			cout << endl; // 20개 출력 후 줄 바꿈
		}
	}
	// 마지막 줄이 20개로 나누어 떨어지지 않을 경우 처리
	if (switch_state.size() % 20 != 0) {
		cout << endl;
	}

	return 0;
}
