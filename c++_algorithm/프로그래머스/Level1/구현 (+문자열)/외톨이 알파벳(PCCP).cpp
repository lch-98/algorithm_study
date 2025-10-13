// PCCP 모의고사 1회 1번 문제
#include <string>
#include <vector>
#include <set>
using namespace std;

string solution(string input_string) {
    string answer = "";
    set<char> string_Xduplicate(input_string.begin(), input_string.end()); // set이라서 answer sort()할 필요X

    for (auto chr : string_Xduplicate) {
        int group_cnt = 0;
        bool in_group = false;

        for (int i = 0; i < input_string.size(); i++) {
            if (input_string[i] == chr) {
                if (in_group == false) {
                    group_cnt++;
                    in_group = true;
                }
            }
            else {
                in_group = false;
            }
        }

        if (group_cnt >= 2) answer += chr;
    }
    if (answer.empty()) answer = "N";
    return answer;
}