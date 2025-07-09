#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char, int> chk_duplicate;
    unordered_map<char, int> chk_idx;
    for (int i=0; i<s.length(); i++) {
        if(chk_duplicate[s[i]] > 0) { // 중복된 값이 있으면 확인 및 재갱신
            answer.push_back(i - chk_idx[s[i]]);
            chk_idx[s[i]] = i; // 최근 인덱스로 재갱신 하는 부분
        }
        // 처음 나왔을 때 인덱스 저장 및 중복 체크
        // 중복을 위한 연산은 한번만 체크해줘도 됨
        else answer.push_back(-1);
        chk_duplicate[s[i]]++;
        chk_idx[s[i]] = i;
    }
    return answer;
}