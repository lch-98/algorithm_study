#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<long long, char>> num_arr;

int binary_search(long long target) {
    int left = 0;
    int right = num_arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (num_arr[mid].first == target) {
            return mid;
        }
        if (target < num_arr[mid].first) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<long long> height(N);

    for (int i = 0; i < N; i++) cin >> height[i];

    int peak = max_element(height.begin(), height.end()) - height.begin();
    for (int i = 0; i < N; i++) {
        char pos;

        if (i < peak) pos = 'L';
        else if (i == peak) pos = 'T';
        else pos = 'R';

        num_arr.push_back({ height[i], pos });
    }

    sort(num_arr.begin(), num_arr.end());

    while (Q--) {
        long long x;
        cin >> x;

        int idx = binary_search(x);

        if (idx == -1) cout << "N\n";
        else cout << num_arr[idx].second << "\n";
    }
    return 0;
}