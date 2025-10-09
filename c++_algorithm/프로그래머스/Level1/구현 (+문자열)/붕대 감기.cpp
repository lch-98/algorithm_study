// PCCP 1번 문제
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    unordered_map<int, pair<int,int>> interrupt_attack_time; // 공격 발생한 시간을 체크해서 인터럽트 발생
    for (int i=0; i< attacks.size(); i++) { // {공격 시간 {공격 인터럽트를 위한 카운트 , 공격시간일 때 인덱스}}
        interrupt_attack_time[attacks[i][0]].first++;
        interrupt_attack_time[attacks[i][0]].second = i;
    }
    int time = 0;
    int sequence_time = 0; // 연속 치료 횟수 카운트
    int current_health = health; // 현재 체력
    while (time < attacks[attacks.size()-1][0]) {
        time++;
        if (interrupt_attack_time[time].first > 0) { // 몬스터 공격 부분
            current_health -= attacks[interrupt_attack_time[time].second][1];
            sequence_time = 0; // 공격 당했으므로 연속 치료 횟수 카운트 초기화
            if (current_health <= 0) return -1; // 체력이 0이하가 되면 죽음
        }
        else { // 몬스터 공격이 아니라면 체력 회복
            if (current_health < health) { // 현재 최력이 최대 최력보다 작다면 회복
                sequence_time++; // 연속 치료 횟수 카운트
                if (sequence_time == bandage[0]) { // 연속 치료 카운트 수가 차면 회복
                    current_health += (bandage[1] + bandage[2]);
                    sequence_time = 0;
                    if (current_health > health) { // 최대 최력보다 현재 최력이 크면 최대 최력으로 초기화
                        current_health = health;
                    }
                }
                else { // 연속 치료 카운트 수가 안차면
                    current_health += bandage[1];
                    if (current_health > health) { // 최대 최력보다 현재 최력이 크면 최대 최력으로 초기화
                        current_health = health;
                    }
                }
            }
        } // 몬스터 공격이 아니라면 체력 회복... else 문 끝
    } // while 문 끝
    answer = current_health;
    return answer;
}