// PCCP 모의고사 1회 2번
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> set_permu;
vector<int> visited;
int max_ans = -1;
void backtracking(int depth, int branch, int target_depth, vector<vector<int>> &ability) {
    if (depth == target_depth) {
        int ans = 0;
        for (int i=0; i< set_permu.size(); i++) {
            ans += ability[set_permu[i]][i];
        }
        max_ans = max(max_ans, ans);
        return;
    }
    
    for (int i=0; i<branch; i++) {
        if (visited[i] == 1) continue;
        visited[i] = 1;
        set_permu.push_back(i);
        backtracking(depth+1, branch, target_depth, ability);
        set_permu.pop_back();
        visited[i] = 0;
    }
}

int solution(vector<vector<int>> ability) {
    // 한 학생은 최대 한개의 종목 대표만 할 수 있음
    // 행의 길이 학생 수, 열의 길이 종목 수
    // 행의 길이가 branch, 열의 길이가 depth
    visited = vector<int>(ability.size(), 0);
    backtracking(0, ability.size(), ability[0].size(), ability);
    
    return max_ans;
}