#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Node {
    string genre;
    int total_of_genre;
    int index;
    int play;
};

bool compare(Node &a, Node &b) {
    if (a.total_of_genre != b.total_of_genre)
        return a.total_of_genre > b.total_of_genre;
    if (a.play != b.play)
        return a.play > b.play;
    return a.index < b.index;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> unmap;
    for (int i=0; i< genres.size(); i++) {
        unmap[genres[i]] += plays[i];
    }
    
    vector<Node> chk;
    for (int i=0; i< genres.size(); i++) {
        chk.push_back({genres[i], unmap[genres[i]], i, plays[i]});
    }
    sort(chk.begin(), chk.end(), compare);
    
    string prev_genre = "";
    int cnt = 0;
    for (auto &x : chk) {
        if (x.genre != prev_genre) {
            prev_genre = x.genre;
            cnt = 0;
        }
        if (cnt < 2) {
            answer.push_back(x.index);
            cnt++;
        }
    }
    return answer;
}