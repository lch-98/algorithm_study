// PCCP 기출문제
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int toSec(int m, int s) {
    return m * 60 + s;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int curr_minute = stoi(pos.substr(0,2));
    int curr_second = stoi(pos.substr(3,2));
    int op_start_minute = stoi(op_start.substr(0,2));
    int op_start_second = stoi(op_start.substr(3,2));
    int op_end_minute = stoi(op_end.substr(0,2));
    int op_end_second = stoi(op_end.substr(3,2));
    int video_len_minute = stoi(video_len.substr(0,2));
    int video_len_second = stoi(video_len.substr(3,2));
    
    int curr = toSec(curr_minute, curr_second);
    int op_start_time = toSec(op_start_minute, op_start_second);
    int op_end_time = toSec(op_end_minute, op_end_second);
    int video_time = toSec(video_len_minute, video_len_second);

    // 시작 위치에서 오프닝 체크
    if (op_start_time <= curr && curr <= op_end_time) {
        curr = op_end_time;
    }

    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == "prev") {
            curr = max(0, curr - 10);
        }
        else if (commands[i] == "next") {
            curr = min(video_time, curr + 10);
        }

        // 명령 실행 후 오프닝 체크
        if (op_start_time <= curr && curr <= op_end_time) {
            curr = op_end_time;
        }
    }
    
    int answer_minute = curr / 60;
    int answer_second = curr % 60;
    string mm = (answer_minute < 10 ? "0" : "") + to_string(answer_minute);
    string ss = (answer_second < 10 ? "0" : "") + to_string(answer_second);
    answer = mm + ":" + ss;
    return answer;
}