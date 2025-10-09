// 2019 KAKAO BLIND RECRUITMENT
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<pair<string, string>> print_answer;
    unordered_map<string, string> chk_nickname; // id, nickname
    for (int i=0; i<record.size(); i++) {
        if (record[i].find("Enter") < 100000) {
            int space_idx = record[i].find(" ", 6);
            string id = record[i].substr(6, space_idx - 6);
            string nickname = record[i].substr(space_idx + 1);
            
            chk_nickname[id] = nickname;

            print_answer.push_back({record[i].substr(0,5), id});
        }
        else if (record[i].find("Leave") < 100000) {
            int space_idx = record[i].find(" ", 6);
            string id = record[i].substr(6, space_idx);
            
            print_answer.push_back({record[i].substr(0,5), id});
        }
        else { // "Change"
            int space_idx = record[i].find(" ", 7);
            string id = record[i].substr(7, space_idx - 7);
            string nickname = record[i].substr(space_idx + 1);
            chk_nickname[id] = nickname;
        }
    }
    
    for (int i=0; i< print_answer.size(); i++) {
        if(print_answer[i].first == "Enter") {
            string merge_ans = chk_nickname[print_answer[i].second] + "님이 들어왔습니다.";
            answer.push_back(merge_ans);
        }
        else {
            string merge_ans = chk_nickname[print_answer[i].second] + "님이 나갔습니다.";
            answer.push_back(merge_ans);
        }
    }
    return answer;
}