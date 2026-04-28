#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    unordered_map<int, int> chk_duplicate;
    
    for (int i=0; i<numbers.size(); i++) {
        for (int j=i+1; j<numbers.size(); j++) {
            if (chk_duplicate[numbers[i] + numbers[j]] > 0) {
                continue;
            }
            chk_duplicate[numbers[i] + numbers[j]]++;
            answer.push_back(numbers[i] + numbers[j]);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}