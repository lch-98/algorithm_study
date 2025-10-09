#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, X;
    cin >> N >> X;
    vector<int> visit(N);
    for (int i = 0; i < N; i++) {
        cin >> visit[i];
    }
    int window_sum = 0;
    for (int i = 0; i < X; i++) {
        window_sum += visit[i];
    }
    int max_sum = window_sum;
    int max_cnt = 1;
    
    for (int i = X; i < N; i++) {
        window_sum = window_sum - visit[i-X] + visit[i];
       
        if (max_sum < window_sum) {
            max_sum = max(max_sum, window_sum);
            max_cnt = 1;
        }
        else if (max_sum == window_sum) {
            max_cnt++;
        }
    }
    if (max_sum == 0) cout << "SAD" << "\n";
    else {
        cout << max_sum << "\n";
        cout << max_cnt << "\n";
    }

    return 0;
}