#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binary(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        vector<int> Sang(N), Sune(M);
        for (int i = 0; i < N; i++) cin >> Sang[i];
        for (int i = 0; i < M; i++) cin >> Sune[i];

        int ans = 0;
        if (N < M) for (int i = 0; i < N; i++) { if (binary(Sune, Sang[i])) ans++; }
        else for (int i = 0; i < M; i++) { if (binary(Sang, Sune[i])) ans++; }

        cout << ans << '\n';
    }
    return 0;
}