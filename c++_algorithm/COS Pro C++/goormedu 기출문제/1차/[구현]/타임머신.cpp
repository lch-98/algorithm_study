// 하단과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(long long num) {

	long long answer = 0;
	num = num + 1;

	string str = to_string(num);
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '0')
		{
			str[i] = '1';
		}
	}
	answer = stoll(str);
	return answer;
}


int main() {
	long long num = 999999999999999999;
	long long ret = solution(num);

	cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}