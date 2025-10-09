#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 두 단어가 한 글자만 다를 때 true
bool canConvert(const string& a, const string& b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) diff++;
        if (diff > 1) return false;
    }
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    auto it = find(words.begin(), words.end(), target);
    if (it == words.end()) return 0;  // target이 없으면 변환 불가

    vector<bool> visited(words.size(), false);
    queue<pair<string, int>> q; // <현재 단어, 변환 횟수>
    q.push({begin, 0});
    
    while (!q.empty()) {
        string curr = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        if (curr == target) return steps;
        
        for (int i = 0; i < words.size(); i++) {
            if (!visited[i] && canConvert(curr, words[i])) {
                visited[i] = true;
                q.push({words[i], steps + 1});
            }
        }
    }
    return 0; // 변환 불가능
}