#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string copy_n = to_string(n);
    
    for (int i = copy_n.length()-1; i >= 0; i--) {
        answer.push_back(stoi(copy_n.substr(i,1)));
    }

    return answer;
}