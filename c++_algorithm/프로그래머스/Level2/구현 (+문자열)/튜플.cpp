// 2019 카카오 개발자 겨울 인턴십
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool compare(pair<vector<int>, int> &a, pair<vector<int>, int> &b) {
    return a.second < b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<vector<int>, int>> NarrAndSize; // 요소들이 담긴 배열 및 사이즈 -> n-튜플 배열

    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == '{') {
            string str = "";
            vector<int> n_arr; // 괄호가 열린시점으로부터 닫힐때까지 n개 요소를 가진 튜플 즉, n-튜플
            for (int j = i + 1; j < s.length() - 1; j++) {
                if ('0' <= s[j] && s[j] <= '9') str += s[j];
                else if (s[j] == ',') {
                    n_arr.push_back(stoi(str));
                    str = "";
                    continue;
                }
                else if (s[j] == '}') {
                    n_arr.push_back(stoi(str));
                    NarrAndSize.push_back({ n_arr, n_arr.size() }); // n-튜플을, n-튜플 배열에 넣어줌
                    i = j;
                    break;
                }
            }
        }
    }
    // 각 튜플 크기로 오름차순 진행
    sort(NarrAndSize.begin(), NarrAndSize.end(), compare);
    // 크기가 작은 튜플 부터 중복을 체크해서 다음 튜플에서 없는 요소들만 answer container에 추가
    unordered_map<int,int> chk_duplicate;
    
    for (int i = 0; i < NarrAndSize.size(); i++) {
        for (int j=0; j< NarrAndSize[i].first.size(); j++) {
            if (chk_duplicate[NarrAndSize[i].first[j]] < 1) answer.push_back(NarrAndSize[i].first[j]); 
            chk_duplicate[NarrAndSize[i].first[j]]++;
        }        
    }
    return answer;
}