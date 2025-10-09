// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solution(vector<int> enemies, vector<int> armies) {
	int answer = 0;
	sort(armies.rbegin(), armies.rend());
	sort(enemies.begin(), enemies.end());

	for (int i = 0; i < armies.size(); i++)
	{
		int chk_max = 0;
		for (int j = 0; j < enemies.size(); j++)
		{
			if (armies[i] >= enemies[j]) chk_max++;
		}
		answer = max(answer, chk_max);
		if (answer > chk_max) break; // 필요없는 연산을 제거
	}
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	vector<int> enemies1 = { 1, 4, 3 };
	vector<int> armies1 = { 1, 3 };
	int ret1 = solution(enemies1, armies1);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	vector<int> enemies2 = { 1, 1, 1 };
	vector<int> armies2 = { 1, 2, 3, 4 };
	int ret2 = solution(enemies2, armies2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}