#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string, int> find_no_completion;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for (int i=0; i<completion.size(); i++) {
        find_no_completion[completion[i]]++;
    }
    
    for (int i=0; i<participant.size(); i++) {
        if (find_no_completion[participant[i]] > 0) {
            find_no_completion[participant[i]]--;
        }
        else {
            answer += participant[i];
        }
    }
    
    return answer;
}