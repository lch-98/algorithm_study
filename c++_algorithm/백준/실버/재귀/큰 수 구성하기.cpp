#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, K;
vector<char> num;
int max_num = 0;

void recursive(string str, int depth, int targetLen) {
    if (depth == targetLen) {
        int val = stoi(str);
        if (val <= N && val > max_num)
            max_num = val;
        return;
    }

    for (int i = 0; i < num.size(); i++) {
        recursive(str + num[i], depth + 1, targetLen);
    }
}

int main() {
    cin >> N >> K;
    num = vector<char>(K);
    for (int i = 0; i < K; i++) {
        cin >> num[i];
    }

    int maxLen = to_string(N).size();
    for (int len = 1; len <= maxLen; len++) {
        recursive("", 0, len);
    }

    cout << max_num << "\n";
    return 0;
}
