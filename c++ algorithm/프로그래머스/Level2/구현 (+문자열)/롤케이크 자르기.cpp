#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solution(vector<int> topping) {
    int n = topping.size();
    int answer = 0;

    unordered_set<int> chulsoo;           // 철수 토핑 집합
    unordered_map<int,int> brotherCount;  // 동생 토핑 개수
    unordered_set<int> brother;           // 동생 토핑 집합

    for (int t : topping) {
        brotherCount[t]++;
        brother.insert(t);
    }

    for (int i=0; i<n-1; i++) {
        int t = topping[i];
        chulsoo.insert(t);

        brotherCount[t]--;
        if (brotherCount[t] == 0) {
            brother.erase(t);
        }

        if (chulsoo.size() == brother.size()) answer++;
    }

    return answer;
}
