#include <iostream>
using namespace std;

long long X, Y;

int main() {
	// 입력 받기
	cin >> X >> Y;

	// 현재 승률 계산
	long long Z = (Y * 100) / X;
	
	// 승률이 99 이상이면 더 이상 승률을 올릴 수 없음
	if (Z >= 99) {
		cout << -1 << endl;
		return 0;
	}

	// 이진 탐색을 통해 최소 게임 횟수를 구함
	long long left = 0, right = 1000000000;  // 범위 설정
	long long answer = -1;

	while (left <= right) {
		long long mid = (left+right) / 2;
		long long newX = X + mid;  // 추가 게임 후의 전체 게임 수
		long long newY = Y + mid;  // 추가 게임 후의 이긴 게임 수
		long long newZ = (newY * 100) / newX;  // 새로운 승률

		//cout << mid << " " << newX << " " << newY << " " << newZ << "\n";
		if (newZ > Z) {  // 승률이 증가한 경우
			answer = mid;
			right = mid - 1;  // 더 작은 mid를 찾아본다
		}
		else {
			left = mid + 1;  // 더 많은 게임을 해야 한다
		}
	}

	// 결과 출력
	cout << answer << endl;
	return 0;
}
