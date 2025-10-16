// 연습문제
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int curr1 = 0, curr2 = 0;

    for (int i = 0; i < goal.size(); i++) {
        auto it1 = find(cards1.begin(), cards1.end(), goal[i]);
        auto it2 = find(cards2.begin(), cards2.end(), goal[i]);

        if (it1 != cards1.end()) { // cards1에 존재
            int idx = it1 - cards1.begin();
            if (idx == curr1) curr1++;   // 현재 맨 앞 카드일 경우만 사용 가능
            else { answer = "No"; break; }
        }
        else if (it2 != cards2.end()) { // cards2에 존재
            int idx = it2 - cards2.begin();
            if (idx == curr2) curr2++;
            else { answer = "No"; break; }
        }
        else { // 둘 다 없으면 불가능
            answer = "No";
            break;
        }
    }
    return answer;
}