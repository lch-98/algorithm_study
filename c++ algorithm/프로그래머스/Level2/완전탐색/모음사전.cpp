#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> alphabet = {'A', 'E', 'I', 'O', 'U'};
vector<string> find_index;
void backtracking(int depth, string str, string target) {
    if (str == target) return;
    if (depth == 5) return;
    
    for (int i=0; i<alphabet.size(); i++) {
        find_index.push_back(str+alphabet[i]);
        backtracking(depth+1, str+alphabet[i], target);
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