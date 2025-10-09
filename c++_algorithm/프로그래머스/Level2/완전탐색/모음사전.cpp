#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> alphabet = {'A', 'E', 'I', 'O', 'U'};
vector<string> find_index;
bool found = false; // target을 찾았는지 여부

void backtracking(int depth, string str, string target) {
    if (found) return;
    if (str == target) {
        found = true; 
        return;
    }
    if (depth == 5) return;
    
    for (int i=0; i<alphabet.size(); i++) {
        find_index.push_back(str + alphabet[i]);
        backtracking(depth+1, str + alphabet[i], target);
        if (found) return;          // 찾은 뒤 더 돌지 않도록 중단
    }
}

int solution(string word) {
    backtracking(0, "", word);
    
    auto idx = find(find_index.begin(), find_index.end(), word);
    return idx - find_index.begin() + 1;
}


/*
#include <string>
#include <vector>
using namespace std;

int solution(string word) {
    int answer = 0;
    vector<char> vowels = {'A','E','I','O','U'};
    vector<int> weight = {781, 156, 31, 6, 1};

    for (int i = 0; i < word.size(); i++) {
        for (int j = 0; j < 5; j++) {
            if (word[i] == vowels[j]) {
                answer += j * weight[i] + 1; 
                break;
            }
        }
    }
    return answer;
}
*/