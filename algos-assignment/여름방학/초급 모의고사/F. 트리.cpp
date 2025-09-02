#include <iostream>
using namespace std;

int n, root;
int parent[51];
int cnt = 0;

void dfs(int cur, int k) {
    bool isLeaf = true;
    for (int i = 0; i < n; i++) {
        if (parent[i] == cur) {
            if (i == k) continue;
            dfs(i, k);
            isLeaf = false;
        }
    }
    if (isLeaf) cnt++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> parent[i];
        if (parent[i] == -1) root = i;
    }
    int k;
    cin >> k;
    if (k == root) {
        cout << 0;
    } else {
        dfs(root, k);
        cout << cnt;
    }
    return 0;
}
