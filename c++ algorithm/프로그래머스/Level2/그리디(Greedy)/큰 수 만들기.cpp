#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.length();
    
    for (int i = 0; i < len; i++) {
        char c = number[i];
        // 뒤에서 더 큰 숫자가 나올 수 있으므로, 작은 숫자는 제거
        while (!answer.empty() && k > 0 && answer.back() < c) {
            answer.pop_back();
            k--;
        }
        answer.push_back(c);
    }
    
    // 아직 제거할 숫자가 남아 있다면 뒤에서 자름
    answer = answer.substr(0, answer.length() - k);
    return answer;
}