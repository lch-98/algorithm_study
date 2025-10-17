// 2018 KAKAO BLIND RECRUITMENT
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Data {
    string HEAD;
    string NUM;
    int index;
};

// 비교 함수
bool compare(const Data &a, const Data &b) {
    if (a.HEAD != b.HEAD) return a.HEAD < b.HEAD;
    int numA = stoi(a.NUM);
    int numB = stoi(b.NUM);
    if (numA != numB) return numA < numB;
    return a.index < b.index; // 입력 순서 유지
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<Data> parsed;

    for (int i = 0; i < files.size(); i++) {
        string file = files[i];
        string head = "", num = "";
        int j = 0;

        while (j < file.size() && !isdigit(file[j])) {
            head += file[j];
            j++;
        }

        while (j < file.size() && isdigit(file[j]) && num.size() < 5) {
            num += file[j];
            j++;
        }

        string lower_head = head;
        for (auto &c : lower_head) c = tolower(c);

        parsed.push_back({lower_head, num, i});
    }

    sort(parsed.begin(), parsed.end(), compare);

    for (auto &p : parsed)
        answer.push_back(files[p.index]);

    return answer;
}
