#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(string s) {
    bool answer = true;
    ((s.length() == 4) || (s.length() == 6)) ? answer = true : answer = false;
    if(answer == false) return answer;
    for(int i=0; i<s.size(); i++) {
        ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) ? answer = false : answer = true;
        if(answer == false) return answer;
    }
    return answer;
}