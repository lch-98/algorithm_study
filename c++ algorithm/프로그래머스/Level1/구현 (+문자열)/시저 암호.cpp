#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (int i=0; i<s.size(); i++) {
        // 공백이면 패스
        if (s[i] == ' ') continue;
        
        // 소문자일때
        else if (s[i] >= 'a' && s[i] <= 'z') {
            int test = s[i] + n;
            if (test > 122) {
                test = test - 26; // 'z' = 122, 'a' = 96
            }
            s[i] = char(test);
        }
        
        // 대문자일때
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            int test = s[i] + n;
            if (test > 90) {
                test = test - 26; // 'z' = 90, 'a' = 64
            }
            s[i] = char(test); 
        }
    }
    
    answer = s;
    return answer;
}