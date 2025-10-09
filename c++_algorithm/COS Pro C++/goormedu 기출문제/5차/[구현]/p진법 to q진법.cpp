// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

string solution(string s1, string s2, int p, int q) {
	string answer = "";
	
	// p진수를 10진수로 변환
	int dec_s1 = 0;
	for (int i = s1.length() - 1; i >= 0; i--)
	{	
		int idx = i - (s1.length() - 1);
		int abs_idx = abs(idx);
		dec_s1 += stoi(s1.substr(i, 1)) * pow(p, abs_idx);
	}

	int dec_s2 = 0;
	for (int i = s2.length() - 1; i >= 0; i--)
	{
		int idx = i - (s2.length() - 1);
		int abs_idx = abs(idx);
		dec_s1 += stoi(s2.substr(i, 1)) * pow(p, abs_idx);
	}

	// 10진수로 변환한 합을 q진수로 변환
	int dec_sum_s1s2 = dec_s1 + dec_s2;

	while (dec_sum_s1s2 > 0) 
	{
		int remainder = dec_sum_s1s2 % q;
		answer = to_string(remainder) + answer;
		dec_sum_s1s2 /= q;
	}
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	string s1 = "112001";
	string s2 = "12010";
	int p = 3;
	int q = 8;
	string ret = solution(s1, s2, p, q);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 \"" << ret << "\" 입니다." << endl;
}