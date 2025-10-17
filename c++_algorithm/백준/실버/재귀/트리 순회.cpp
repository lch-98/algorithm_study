#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> tree(26, vector<char>(2, '.')); // [노드][0=왼쪽, 1=오른쪽]

void preorder(char node) {
    if (node == '.') return;
    cout << node;                     // 1. 루트
    preorder(tree[node - 'A'][0]);    // 2. 왼쪽
    preorder(tree[node - 'A'][1]);    // 3. 오른쪽
}

void inorder(char node) {
    if (node == '.') return;
    inorder(tree[node - 'A'][0]);     // 1. 왼쪽
    cout << node;                     // 2. 루트
    inorder(tree[node - 'A'][1]);     // 3. 오른쪽
}

void postorder(char node) {
    if (node == '.') return;
    postorder(tree[node - 'A'][0]);   // 1. 왼쪽
    postorder(tree[node - 'A'][1]);   // 2. 오른쪽
    cout << node;                     // 3. 루트
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        char root, left, right;
        cin >> root >> left >> right;
        tree[root - 'A'][0] = left;
        tree[root - 'A'][1] = right;
    }

    preorder('A'); cout << '\n';
    inorder('A');  cout << '\n';
    postorder('A');cout << '\n';

    return 0;
}
