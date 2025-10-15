// PCCP 모의고사 1회 4번
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Program {
    int score;
    int call;
    int run;
};

bool compare(const Program &a, const Program &b) {
    return a.call < b.call; // 호출 시각 오름차순
}

struct cmp {
    bool operator()(const Program &a, const Program &b) const {
        if (a.score == b.score) return a.call > b.call; // 호출 시각 빠른 게 먼저
        return a.score > b.score; // 점수가 낮을수록 우선순위 높음
    }
};

vector<long long> solution(vector<vector<int>> program) {
    vector<Program> p;
    for (auto &v : program) p.push_back({v[0], v[1], v[2]});

    sort(p.begin(), p.end(), compare); // 호출 시각 기준 정렬

    priority_queue<Program, vector<Program>, cmp> pq;
    vector<long long> answer(11, 0);

    long long now = 0; 
    int idx = 0;
    int n = p.size();

    while (idx < n || !pq.empty()) {
        // 현재 시각까지 호출된 프로그램들 추가
        while (idx < n && p[idx].call <= now) {
            pq.push(p[idx]);
            idx++;
        }

        // 실행할 프로그램이 없으면 다음 호출 시각으로 점프
        if (pq.empty()) {
            now = p[idx].call;
            continue;
        }

        // 우선순위 높은 프로그램 실행
        Program cur = pq.top();
        pq.pop();

        // 대기 시간 누적
        answer[cur.score] += (now - cur.call);

        // 실행
        now += cur.run;
    }

    // 모든 프로그램 종료 시각
    answer[0] = now;
    return answer;
}