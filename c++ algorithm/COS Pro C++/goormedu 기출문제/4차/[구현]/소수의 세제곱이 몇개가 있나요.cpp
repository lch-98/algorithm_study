// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
	int answer = 0;
	// 35000 * 35000이면 제한해준 10억이 넘어감
	// 나중에 i가 2일 때 case만 추가해주면 됨
	for (int i = 3; i < 35000; i++)
	{
		int flag = 1; // 소수면 flag가 1
		
		if (b < i*i) break; // 제곱수가 b보다 크면 연산을 끝내도 됨
		if (i % 2 == 0) continue; // 짝수면 넘어가기
		for (int j = 2; j < i; j++)
		{
			// 자기 자신을 제외한 값이 나눠지면 소수가 아님
			if (i % j == 0) {
				flag = 0; // 소수가 아니기 때문에 flag가 0
				break;
			}
		}
		
		if (flag == 1)
		{
			if (a <= i*i && b >= i*i)
			{
				//cout << "조건을 만족하는 소수들: " << i*i << "\n";
				answer++;
			}
			if (a <= i*i*i && b >= i*i*i)
			{
				//cout << "조건을 만족하는 소수들: " << i*i*i << "\n";
				answer++;
			}
		}
	}
	// 2일 때 케이스만 따로 추가
	if (a <= 2 * 2 && b >= 2 * 2)
	{
		//cout << "조건을 만족하는 소수들: " << 2 << "\n";
		answer++;
	}
	else if (a <= 2 * 2 * 2 && b >= 2 * 2 * 2)
	{
		//cout << "조건을 만족하는 소수들: " << 2 << "\n";
		answer++;
	}
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	int a = 6;
	int b = 30;
	int ret = solution(a, b);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;

	return 0;
}