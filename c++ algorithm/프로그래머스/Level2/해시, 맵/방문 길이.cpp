#include <string>
#include <unordered_map>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    unordered_map<char, pair<int,int>> direction = {
        {'U', {-1, 0}},
        {'D', {1, 0}},
        {'R', {0, 1}},
        {'L', {0, -1}}
    };
    
    unordered_map<string, int> chk_duplicate;
    pair<int, int> curr_pos = {0, 0};
    for (int i = 0; i < dirs.size(); i++) {
        int ny = curr_pos.first + direction[dirs[i]].first;
        int nx = curr_pos.second + direction[dirs[i]].second;
        
        if (ny < -5 || nx < -5 || ny > 5 || nx > 5) continue;

        string path1 = to_string(curr_pos.first) + "," + to_string(curr_pos.second) + 
                       "->" + to_string(ny) + "," + to_string(nx);
        string path2 = to_string(ny) + "," + to_string(nx) + 
                       "->" + to_string(curr_pos.first) + "," + to_string(curr_pos.second);
        
        if (chk_duplicate[path1] == 0 && chk_duplicate[path2] == 0) {
            answer++;
            chk_duplicate[path1] = 1;
            chk_duplicate[path2] = 1;
        }

        curr_pos.first = ny;
        curr_pos.second = nx;
    }
    return answer;
}
