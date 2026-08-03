#include <iostream>
#include <vector>
using namespace std;

int all_num;
int target_num1, target_num2;
int relation_all_num;

vector<vector<int>> arr_relation;
vector<int> visited;

int ans = -1;


void dfs(int start_num, int target_num, int depth) {
    if (start_num == target_num) {
        ans = depth;
        return;
    }

    visited[start_num] = 1;

    for (int i = 1; i <= all_num; i++) {
        if (arr_relation[start_num][i] == 0) continue;
        if (visited[i] == 1) continue;

        dfs(i, target_num, depth + 1);
    }
}

int main() {
    cin >> all_num;
    cin >> target_num1 >> target_num2;
    cin >> relation_all_num;

    arr_relation = vector<vector<int>>(all_num + 1, vector<int>(all_num + 1, 0));
    visited = vector<int>(all_num + 1, 0);

    for (int i = 0; i < relation_all_num; i++) {

        int x, y;
        cin >> x >> y;

        arr_relation[x][y] = 1;
        arr_relation[y][x] = 1;
    }

    dfs(target_num1, target_num2, 0);
    cout << ans;

    return 0;
}