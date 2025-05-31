#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        // 공백은 그대로 추가
        if (c == ' ') {
            answer += ' ';
        }
        // 소문자
        else if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + n) % 26 + 'a';
            answer += c;
        }
        // 대문자
        else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + n) % 26 + 'A';
            answer += c;
        }
    }

    return answer;
}
