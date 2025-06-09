#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;

        a %= 10;
        if (a == 0) {
            cout << 10 << "\n";
            continue;
        }

        vector<int> cycle;
        cycle.push_back(a);
        int num = a;

        while (1) { // 사이클 만들기
            num = (num * a) % 10;
            if (find(cycle.begin(), cycle.end(), num) != cycle.end()) break;
            cycle.push_back(num);
        }

        int index = (b - 1) % cycle.size();
        cout << cycle[index] << "\n";
    }

    return 0;
}
