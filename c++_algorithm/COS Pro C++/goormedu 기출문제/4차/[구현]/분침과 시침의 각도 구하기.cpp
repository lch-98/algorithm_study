// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

float minute_angle = 0;
string solution(int hour, int minute) {
	string answer = "";

	float hour_angle = (360.0 / (12.0 / hour));
	if (minute != 0)
	{
		minute_angle = (360.0 / (60.0 / minute));
	}

	if (hour_angle > minute_angle)
	{
		answer = to_string(hour_angle - minute_angle);
	}
	else if (hour_angle < minute_angle)
	{
		answer = to_string(minute_angle - hour_angle);
	}
	int idx_dot = answer.find('.');

	return answer.substr(0, idx_dot + 2);
}


// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	int hour = 3;
	int minute = 50;
	string ret = solution(hour, minute);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 \"" << ret << "\" 입니다." << endl;
}