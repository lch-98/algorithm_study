#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int K, vector<string> words) {
	int answer = 1;  // 최소 한 줄은 필요
	int current_length = 0;  // 현재 줄의 사용된 문자 수

	for (int i = 0; i < words.size(); i++) {
		int word_length = words[i].length();

		if (current_length == 0) {
			// 첫 단어는 그냥 추가
			current_length += word_length;
		}
		else if (current_length + 1 + word_length <= K) {
			// 현재 줄에 공백 포함해서 단어 추가 가능
			current_length += 1 + word_length;
		}
		else {
			// 새 줄로 넘어가야 하는 경우
			answer++;
			current_length = word_length;  // 새로운 줄에서 단어 시작
		}
	}

	return answer;
}

// 테스트 코드
int main() {
	int K = 10;
	vector<string> words = { "nice", "happy", "hello", "world", "hi" };
	int ret = solution(K, words);

	cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}
