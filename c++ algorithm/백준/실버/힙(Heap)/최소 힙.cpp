#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            if (!pq.empty()) {
                cout << pq.top() << "\n";
                pq.pop();
            } else {
                cout << 0 << "\n";
            }
        } else {
            pq.push(num);
        }
    }
}
