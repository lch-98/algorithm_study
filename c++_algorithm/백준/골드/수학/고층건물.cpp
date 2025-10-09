#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> heights(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }
    int maxVisible = 0;

    for (int i = 0; i < N; i++) {
        int count = 0;
        // 오른쪽 방향
        for (int j = i + 1; j < N; j++) {
            bool visible = true;
            double slope_ij = (double)(heights[j] - heights[i]) / (j - i);

            for (int k = i + 1; k < j; k++) {
                double slope_ik = (double)(heights[k] - heights[i]) / (k - i);
                if (slope_ik >= slope_ij) {
                    visible = false;
                    break;
                }
            }
            if (visible) count++;
        }
        // 왼쪽 방향
        for (int j = i - 1; j >= 0; j--) {
            bool visible = true;
            double slope_ij = (double)(heights[j] - heights[i]) / (j - i);  // j-i는 음수이므로 올바름

            for (int k = i - 1; k > j; k--) {
                double slope_ik = (double)(heights[k] - heights[i]) / (k - i);
                if (slope_ik <= slope_ij) {
                    visible = false;
                    break;
                }
            }
            if (visible) count++;
        }
        maxVisible = max(maxVisible, count);
    }
    cout << maxVisible << '\n';
    return 0;
}
