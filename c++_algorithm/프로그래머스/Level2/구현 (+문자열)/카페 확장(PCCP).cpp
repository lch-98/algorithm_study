// PCCP 모의고사 2회 3번
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.first == b.first) return a.second < b.second; // -1 < +1 -> 퇴장 먼저
    return a.first < b.first;
}

int solution(vector<int> menu, vector<int> order, int k) {
    int answer = 0;
    unordered_map<int, int> menu_idx_time;
    for (int i = 0; i < menu.size(); i++) {
        menu_idx_time[i] = menu[i];
    }

    // 이벤트: pair<time, type>, type = -1 (퇴장), +1 (입장)
    // 같은 시간인 경우 퇴장(-1)을 먼저 처리하기 위해 타입을 정해둠
    vector<pair<int,int>> events;
    int server_free_time = 0; // 바리스타가 다음 주문을 시작할 수 있는 시각

    for (int i = 0; i < order.size(); i++) {
        int arrive = i * k; // i번째 손님의 도착 시간
        int duration = menu_idx_time[order[i]];

        int start_time;
        if (server_free_time <= arrive) {
            // 바리스타가 기다리고 있다면 도착 즉시 시작
            start_time = arrive;
        } else {
            // 바쁘면 이전 작업 끝난 후 시작
            start_time = server_free_time;
        }
        int finish_time = start_time + duration;
        server_free_time = finish_time; // 바리스타는 이 시점까지 바쁨

        events.push_back({arrive, 1});      // 입장
        events.push_back({finish_time, -1}); // 퇴장
    }

    // 시간순, 같으면 type 오름차순(-1이 먼저) 으로 정렬
    sort(events.begin(), events.end(), compare);

    int curr = 0;
    for (auto &e : events) {
        cout << e.first << " " << e.second << "\n";
        curr += e.second;
        answer = max(answer, curr);
    }

    return answer;
}
