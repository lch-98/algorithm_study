#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // 카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 길다.
    for (int height = 1; height <= yellow; height++) {
        if (yellow % height != 0) continue;

        int width = yellow / height;

        int total_w = width + 2;
        int total_h = height + 2;
        int total = total_w * total_h;

        if (total - yellow == brown) {
            answer.push_back(total_w);
            answer.push_back(total_h);
            break;
        }
    }

    return answer;
}