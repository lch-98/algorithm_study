#include <string>
#include <vector>
using namespace std;

int toSeconds(int hhmm) {
    int h = hhmm / 100;
    int m = hhmm % 100;
    return h * 3600 + m * 60;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for (int i = 0; i < schedules.size(); i++) {
        int schedule_time = toSeconds(schedules[i]);

        if (startday == 1) { // 월요일 시작
            bool flag = true;
            for (int j = 0; j < 7; j++) {
                if (j == 5 || j == 6) continue; // 토, 일 제외
                int time_info = toSeconds(timelogs[i][j]);
                if (!(time_info <= schedule_time + 600)) {
                    flag = false;
                    break;
                }
            }
            if (flag) answer++;
        } 
        else if (startday == 2) { // 화요일 시작
            bool flag = true;
            for (int j = 0; j < 7; j++) {
                if (j == 4 || j == 5) continue; // 토, 일 제외
                int time_info = toSeconds(timelogs[i][j]);
                if (!(time_info <= schedule_time + 600)) {
                    flag = false;
                    break;
                }
            }
            if (flag) answer++;
        } 
        else if (startday == 3) { // 수요일 시작
            bool flag = true;
            for (int j = 0; j < 7; j++) {
                if (j == 3 || j == 4) continue;
                int time_info = toSeconds(timelogs[i][j]);
                if (!(time_info <= schedule_time + 600)) {
                    flag = false;
                    break;
                }
            }
            if (flag) answer++;
        } 
        else if (startday == 4) { // 목요일 시작
            bool flag = true;
            for (int j = 0; j < 7; j++) {
                if (j == 2 || j == 3) continue;
                int time_info = toSeconds(timelogs[i][j]);
                if (!(time_info <= schedule_time + 600)) {
                    flag = false;
                    break;
                }
            }
            if (flag) answer++;
        } 
        else if (startday == 5) { // 금요일 시작
            bool flag = true;
            for (int j = 0; j < 7; j++) {
                if (j == 1 || j == 2) continue;
                int time_info = toSeconds(timelogs[i][j]);
                if (!(time_info <= schedule_time + 600)) {
                    flag = false;
                    break;
                }
            }
            if (flag) answer++;
        } 
        else if (startday == 6) { // 토요일 시작
            bool flag = true;
            for (int j = 0; j < 7; j++) {
                if (j == 0 || j == 1) continue;
                int time_info = toSeconds(timelogs[i][j]);
                if (!(time_info <= schedule_time + 600)) {
                    flag = false;
                    break;
                }
            }
            if (flag) answer++;
        } 
        else { // 일요일 시작
            bool flag = true;
            for (int j = 0; j < 7; j++) {
                if (j == 6 || j == 0) continue;
                int time_info = toSeconds(timelogs[i][j]);
                if (!(time_info <= schedule_time + 600)) {
                    flag = false;
                    break;
                }
            }
            if (flag) answer++;
        }
    }
    return answer;
}
