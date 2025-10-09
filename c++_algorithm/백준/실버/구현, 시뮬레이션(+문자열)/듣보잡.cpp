#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {

    int N, M;
    cin >> N >> M;
    
    vector<string> no_listen(N); 
    vector<string> no_see(M);    

    for (int i = 0; i < N; i++) {
        cin >> no_listen[i];
    }

    for (int j = 0; j < M; j++) {
        cin >> no_see[j];
    }
    
    unordered_set<string> intersected;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (no_listen[i] == no_see[j]) {
                intersected.insert(no_listen[i]);
                break;
            }
        }
    }

    vector<string> answer(intersected.begin(), intersected.end());
    cout << answer.size() << endl;
    for (const auto& name : answer) {
        cout << name << endl;
    }

    return 0;
}
