// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int K, vector<string> words) {
	int answer = 1;
	int current_length = words[0].length();

	for (int i = 1; i < words.size(); i++) {
		string str = words[i];
		if (current_length + 1 + str.length() <= K) {
			current_length = current_length + 1 + str.length();
		}
		else {
			answer++;
			current_length = str.length();
		}
	}
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int K = 10;
    vector<string> words = {"nice", "happy", "hello", "world", "hi"};
    int ret = solution(K, words);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다.";
}