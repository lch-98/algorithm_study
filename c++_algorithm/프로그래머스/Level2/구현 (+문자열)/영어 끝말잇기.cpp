#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, int> chk_words;

    chk_words[words[0]] = 1;
    if (words[0].length() == 1) {
        return {1, 1};  // 한 글자면 바로 탈락
    }

    for (int i = 1; i < words.size(); i++) {
        int number = i % n + 1;
        int turn = i / n + 1;

        string prev = words[i - 1];
        string curr = words[i];

        if (curr.length() == 1) {
            return {number, turn};
        }

        if (prev.back() != curr.front()) {
            return {number, turn};
        }

        if (chk_words[curr] > 0) {
            return {number, turn};
        }

        chk_words[curr]++;
    }

    return {0, 0};
}
