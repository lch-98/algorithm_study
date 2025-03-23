#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int K, vector<string> words) {
    int answer = 1;  // 최소 한 줄 필요
    int current_length = words[0].length();  // 첫 번째 단어의 길이로 초기화

    for (int i = 1; i < words.size(); i++) {  
        string str = words[i];
        // !중요: 단어가 엄청 짧을 경우에 한 줄에 여러 개 들어갈 수도 있는 점 조심
        if (current_length + 1 + str.length() <= K) {  
            // 현재 줄에 단어 추가 가능 (공백 포함)
            current_length += 1 + str.length();
        } else {  
            // 새로운 줄 필요
            answer++;
            current_length = str.length();  // 새 줄에서 현재 단어의 길이로 초기화
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
