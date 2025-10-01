#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.rbegin(), score.rend());
    int box_min_num = 21e8;
    for(int i=0; i<score.size(); i++) {
        box_min_num = min(box_min_num, score[i]);
        if ((i+1) % m == 0) {
            answer += (box_min_num * m);
        }
    }
    return answer;
}