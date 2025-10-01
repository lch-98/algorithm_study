//2018 KAKAO BLIND RECRUITMENT
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

string AlphabetLower(string str) {
    for (char &c : str) {
        if ('A' <= c && c <= 'Z') c += ('a' - 'A');
    }
    return str;
}

bool ChkSpecialSign(const string &s) {
    return ('a' <= s[0] && s[0] <= 'z') && ('a' <= s[1] && s[1] <= 'z');
}

int solution(string str1, string str2) {
    str1 = AlphabetLower(str1);
    str2 = AlphabetLower(str2);

    unordered_map<string,int> m1, m2;

    // str1 다중집합
    for (int i=0; i < (int)str1.size()-1; i++) {
        string sub = str1.substr(i,2);
        if (ChkSpecialSign(sub)) m1[sub]++;
    }
    // str2 다중집합
    for (int i=0; i < (int)str2.size()-1; i++) {
        string sub = str2.substr(i,2);
        if (ChkSpecialSign(sub)) m2[sub]++;
    }

    // 교집합, 합집합 크기 계산
    int inter = 0, uni = 0;
    unordered_map<string,int> allKeys = m1;
    for (auto &p : m2) allKeys[p.first] += 0; // 키 병합

    for (auto &p : allKeys) {
        string key = p.first;
        int c1 = m1[key];
        int c2 = m2[key];
        inter += min(c1, c2);
        uni   += max(c1, c2);
    }

    if (uni == 0) return 65536; // 공집합 처리
    return (int)floor((double)inter / uni * 65536);
}
