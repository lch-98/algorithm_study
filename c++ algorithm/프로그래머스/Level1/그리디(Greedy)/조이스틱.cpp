#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string name) {
    int answer = 0;
    
    // A B C D E, F G H I J, K L M N O, P Q R S T, U V W X Y, Z -> 26개
    // N은 정수값으로 78

    // 알파벳을 움직이는 최소값 구하기
    for (int i=0; i<name.size(); i++) {
        if (int(name[i]) < 78) { // N보다 작으므로 "다음 알파벳"으로 가는 연산을 진행
            answer += (int(name[i]) - int('A'));
        }
        else if (int(name[i]) == 78) { // N이랑 같으므로 그냥 13을 더해주면 됨
            answer+= 13;
        }
        else { // N보다 크므로 "이전 알파벳"으로 가는 연산을 진행
            answer += (90 - int(name[i]) + 1);
        }
    }
    
    // 2. 커서 이동 최소 횟수 계산
    int len = name.length();
    int move = len - 1; // 오른쪽으로 쭉 가는 기본값

    for (int i = 0; i < len; i++) {
        int next = i + 1;
        // 연속된 A 구간을 찾음
        while (next < len && name[next] == 'A') next++;

        // 왼쪽으로 돌아갔다가 다시 가는 경우를 고려한 최소값 계산
        int leftRight = i + i + (len - next);
        int rightLeft = i + 2 * (len - next);

        move = min({move, leftRight, rightLeft});
    }

    answer += move;
    return answer;
}