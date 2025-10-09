// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int solution(int number, int target) {
	int answer = 0;

	// number가 더 클 경우에는 무조건 연산 2를 수행해야함
	if (number > target) {
		while (number != target) {
			number -= 1;
			answer++;
		}	
	}
	// number가 작을 경우에 그리디 접근
	else if (number < target) {
		while (number != target) {
			if (number < target) {
				/* 
				  만약 2를 곱한 값에서 target을 뺀 값이랑 1을 더한 값에서 target을 뺀 값을 비교해서
				  전자 값보다 후자 값이 작으면 target에 최소 연산은 +1로 진행해줘야 한다.
				  ex. 7 9 -> (14-9) > abs(7-9) -> (빼기)5번 연산 vs (더하기)2번 연산 -> 더하기 연산을 해주는게 맞음
				  ex. 5 9 -> (10-9) > abs(6-9) -> (빼기)1번 연산 vs (더하기)3번 연산 -> 곱하기를 해주는게 맞음
				*/ 
				if (number * 2 - target > abs(number + 1 - target))
				{
					number += 1;
					answer++;
				}
				else
				{
					number = number * 2;
					answer++;
				}
			}
			else if (number > target) {
				number--;
				answer++;
			}
		}
	}
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	int number1 = 5;
	int target1 = 9;
	int ret1 = solution(number1, target1);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	int number2 = 3;
	int target2 = 11;
	int ret2 = solution(number2, target2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}