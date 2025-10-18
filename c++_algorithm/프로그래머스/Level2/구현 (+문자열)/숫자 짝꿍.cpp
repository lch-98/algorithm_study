// 연습문제
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<char> matching_map; // 짝을 이루는 숫자를 넣을 배열
    
    unordered_map<int, int> un_map;
    for (int i = 0; i < X.length(); i++) {
        int num = X[i] - '0';     // 숫자로 변환
        un_map[num]++;
    }

    // un_map으로만 짝 확인
    for (int i = 0; i < Y.length(); i++) {
        int num = Y[i] - '0'; 
        if (un_map[num] > 0) {
            un_map[num]--;
            matching_map.push_back(Y[i]);
        }
    }

    sort(matching_map.begin(), matching_map.end(), greater<int>()); // 내림차순
    
    for (int i = 0; i < matching_map.size(); i++) {
        answer += matching_map[i];
    }

    if (answer == "") answer = "-1";
    else if (answer[0] == '0') answer = "0";

    return answer;
}
