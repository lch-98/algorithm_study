#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<bool> numChk(10);
    for (int i=0; i<numbers.size(); i++) {
        numChk[numbers[i]] = true;
    }
    for (int i=0; i<numChk.size(); i++) {
        if(!numChk[i]) answer += i;
    }
    return answer;
}