#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    deque<int> dq;
    vector<int> targets(M);

    for (int i = 1; i <= N; i++) dq.push_back(i);
    for (int i = 0; i < M; i++) cin >> targets[i];

    int moves = 0;
    for (int t = 0; t < M; t++) {
        int target = targets[t];
        int idx = 0;

        for (int i = 0; i < dq.size(); i++) {
            if (dq[i] == target) {
                idx = i;
                break;
            }
        }

        if (idx <= dq.size() / 2) {
            while (dq.front() != target) {
                dq.push_back(dq.front());
                dq.pop_front();
                moves++;
            }
        }
        else {
            while (dq.front() != target) {
                dq.push_front(dq.back());
                dq.pop_back();
                moves++;
            }
        }

        dq.pop_front();
    }

    cout << moves << "\n";
    return 0;
}
