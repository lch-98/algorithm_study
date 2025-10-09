#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 최대 겹치는 길이 계산 함수
int get_overlap(string a, string b) {
	
	int max_len = min(a.size(), b.size());

	for (int len = max_len; len > 0; len--) 
	{
		cout << a.substr(a.size() - len) << " " << b.substr(0, len) << "\n";
		if (a.substr(a.size() - len) == b.substr(0, len)) return len;
	}
	return 0;
}

int solution(string s1, string s2) {
	int overlap1 = get_overlap(s1, s2);
	int overlap2 = get_overlap(s2, s1);

	int len1 = s1.size() + s2.size() - overlap1;
	int len2 = s2.size() + s1.size() - overlap2;

	return min(len1, len2);
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	string s1 = "ababc";
	string s2 = "abcdab";
	int ret = solution(s1, s2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}