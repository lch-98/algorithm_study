#include <string>
#include <vector>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> solution(string command) {
    vector<int> answer;
    pair<int,int> curr_pos = {0,0};
    int curr_dr = 0;
    for (int i=0; i<command.size(); i++) {
        if (command[i] == 'R') { curr_dr = (curr_dr+1) % 4; }
        else if (command[i] == 'L') { curr_dr = (curr_dr+3) % 4; }
        else {
            if (command[i] == 'G') {
                curr_pos.first += -(dy[curr_dr]); // y
                curr_pos.second += dx[curr_dr]; // x
            }
            else if (command[i] == 'B') {
                curr_pos.first += dy[curr_dr]; // y
                curr_pos.second += -(dx[curr_dr]); // x
            }
        }
    }
    answer.push_back(curr_pos.second);
    answer.push_back(curr_pos.first);
    return answer; // {x, y}
}