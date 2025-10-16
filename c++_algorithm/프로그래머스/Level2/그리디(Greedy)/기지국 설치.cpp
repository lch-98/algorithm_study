// Summer/Winter Coding(~2018) feat. ChatGPT
#include <iostream>
#include <vector>
using namespace std;

/*
 4G → 5G 기지국 문제 풀이 (그리디 알고리즘)
 
 핵심 아이디어:
  - 아파트를 1번부터 끝까지 순서대로 보며, 전파가 닿지 않은 구간을 만나면
    새 기지국을 설치해 그 구간을 커버한다.
  - 이미 설치된 기지국(stations)의 전파 범위 안이라면,
    그 구간은 건너뛰고 그 기지국의 커버 끝 다음 위치로 점프한다.
*/

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;   // 새로 설치해야 하는 기지국 개수
    int e = 1;        // 현재 검사할 아파트 번호 (1부터 시작)
    int f = 0;        // stations 배열의 인덱스 (현재 보고 있는 기지국)

    // 모든 아파트를 덮을 때까지 반복
    while (e <= n)
    {
        // 현재 아파트(e)가 기존 기지국 범위 안에 있는 경우
        // stations[f] - w ~ stations[f] + w 범위가 해당 기지국의 커버 범위
        if (f < stations.size() && e >= stations[f] - w)
        {
            // 이 기지국이 덮는 마지막 아파트 다음부터 확인 시작
            e = stations[f] + w + 1;
            // 다음 기지국으로 이동
            f++;
        }
        else
        {
            // 기존 기지국으로 커버되지 않은 구간 → 새 기지국 설치
            // 한 기지국이 덮을 수 있는 범위: (2*w + 1)
            e += w * 2 + 1;
            answer++;
        }
    }

    return answer;
}

/*
예시:
N = 11, stations = [4, 11], W = 1

[4] 기지국 커버 범위: [3~5]
[11] 기지국 커버 범위: [10~11]

1) e=1 → 1은 [3~5] 밖 → 새 기지국 설치 (커버: 1~3) → e=4, answer=1
2) e=4 → [3~5] 안 → e=6, f=1
3) e=6 → [10~11] 밖 → 새 기지국 설치 (커버: 6~8) → e=9, answer=2
4) e=9 → [10~11] 밖 → 새 기지국 설치 (커버: 9~11) → e=12, answer=3
종료 → 총 3개 필요
*/
