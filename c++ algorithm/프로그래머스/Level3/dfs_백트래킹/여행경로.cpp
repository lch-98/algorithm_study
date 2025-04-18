#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(string current, vector<vector<string>>& tickets, vector<bool>& used, vector<string>& route, int depth) {
    if (depth == tickets.size()) return true;  // 모든 티켓 사용 완료

    for (int i = 0; i < tickets.size(); i++) {
        if (!used[i] && tickets[i][0] == current) {
            used[i] = true;
            route.push_back(tickets[i][1]);
            if (dfs(tickets[i][1], tickets, used, route, depth + 1)) return true;
            used[i] = false;
            route.pop_back(); // 백트래킹
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());  // 알파벳 순 정렬
    vector<string> route = {"ICN"};
    vector<bool> used(tickets.size(), false);

    dfs("ICN", tickets, used, route, 0);

    return route;
}
