#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;

    for (string op : operations) {
        if (op[0] == 'I') {
            int num = stoi(op.substr(2));
            ms.insert(num);
        }
        else if (op == "D 1") {
            if (!ms.empty()) {
                auto it = prev(ms.end()); // 가장 큰 값
                ms.erase(it);
            }
        }
        else if (op == "D -1") {
            if (!ms.empty()) {
                auto it = ms.begin(); // 가장 작은 값
                ms.erase(it);
            }
        }
    }

    // 비어있으면 {0, 0}
    if (ms.empty()) return {0, 0};
    return {*prev(ms.end()), *ms.begin()};
}