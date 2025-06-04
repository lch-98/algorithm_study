#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {    
    vector<int> pos;
    for(int i=0; i<s.length(); i++) {
        if (s[i] == ' ') {
            pos.push_back(i); // 공백을 기록
        }
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += ('a'-'A'); // 일단 소문자로 다 변환
    }
    
    for (int i: pos) {
        if(s[i+1] >= 'a' && s[i+1] <= 'z') s[i+1] -= ('a'-'A'); // 공백기준 다음 문자가 소문자라면 대문자로 변환
    }
    
    if(s[0] >= 'a' && s[0] <= 'z') s[0] -= ('a'-'A'); // 만약 첫 문자가 소문자라면 대문자로 변환

    return s;
}