#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    vector<string> words = {"aya", "ye", "woo", "ma"};
    
    for (string b : babbling) {
        int idx = 0;
        string prev = "";
        bool valid = true;
        
        while (idx < b.size()) {
            bool matched = false;
            
            for (string w : words) {
                // 현재 위치에서 w가 시작되는지 확인
                if (b.substr(idx, w.size()) == w && prev != w) {
                    idx += w.size();
                    prev = w;
                    matched = true;
                    break;
                }
            }
            
            // 어떤 발음도 매칭 안되면 실패
            if (!matched) {
                valid = false;
                break;
            }
        }
        
        if (valid) answer++;
    }
    return answer;
}