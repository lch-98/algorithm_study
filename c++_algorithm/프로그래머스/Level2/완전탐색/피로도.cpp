#include <string>
#include <vector>
#include <algorithm>
#include <iostream> // debugging
using namespace std;

// 중복을 제거한 순열 작성
vector<vector<int>> permu_vector; // 순열을 담을 벡터
void set_permutations(int depth, int target_depth, vector<int> &visited, vector<int> &permu) {
    if(depth == target_depth) {
        permu_vector.push_back(permu);
        return;
    }
    
    for (int i=0; i<target_depth; i++) {
        if(visited[i] == 1) continue;
        
        visited[i] = 1;
        permu.push_back(i);
        set_permutations(depth + 1, target_depth, visited, permu);
        visited[i] = 0;
        permu.pop_back();
        
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    // 피로도를 사용해서 던전을 탐험 가능
    // 던전 탐험시작 = 최소 필요 피로도 / 던전 탐험 마쳤을 때 = 소모 피로도
    // "최대한 많은 던전"을 탐험
    vector<int> visited(dungeons.size(), 0);
    vector<int> permu; // 재귀함수에서 사용할 벡터 컨테이너
    set_permutations(0, dungeons.size(), visited, permu);
    
    // 순열이 잘 들어갔는지 디버깅용 출력
    /*
    for (int i=0; i<permu_vector.size(); i++) {
        for (int num : permu_vector[i]) {
            cout << num << " ";
        }
        cout << "\n";
    }
    */
    for (int i=0; i<permu_vector.size(); i++) {
        int temp_k = k; //k 값을 각각 가능 횟수에서 비교하기 위해 복사
        int max_answer = 0;
        for (int num : permu_vector[i]) {
            if(temp_k >= dungeons[num][0]) {
                temp_k -= dungeons[num][1];
                max_answer++;
            }
            //cout << num << " ";
        }
        //cout << max_answer << "\n";
        answer = max(answer, max_answer);
    }

    return answer;
}